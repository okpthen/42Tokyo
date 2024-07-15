#include "Command.hpp"

Command::Command(){}
Command::~Command(){}
Command::Command(std::string cmd, Client *client)
{
	set_command(cmd, client);
}
void	Command::exec_loop(std::string &cmdlst, Client *client, Server &server)
{
	_client = client;
	_lst.clear();
	std::string s;
	std::size_t	find;

	while ((find = cmdlst.find("\r"))  != std::string::npos)
		cmdlst.erase(find, 1);
	
	find = cmdlst.find("\n");
	if (find == std::string::npos)
	{
		_tmp += cmdlst;
		// std::cout << "kokotototteimasuka_" << std::endl;
		return ;
	}
	else
	{
		cmdlst.insert(0, _tmp);
		_tmp.clear();
	}

	std::istringstream stream(cmdlst.c_str());
	while (std::getline(stream, s, '\n'))
	{
		_lst.push_back(s);
	}
	int num;
	std::vector<std::string>::iterator it = _lst.begin();
	while (it != _lst.end())
	{
		set_command(*it, client);
		num = exec(server);
		if (num == 999)
			break ;
		print_err(num);
		std::cout  << num  << std::endl;
		it ++;
	}
}


void	Command::set_command(std::string &cmd, Client *client)
{
    _command = cmd;
	_arr.clear();
    std::string end, start, s;
	_client = client;

	if (!cmd.empty() && cmd[cmd.size() - 1] == '\n')
		cmd.erase(cmd.size() - 1);

	// std::cout  << _client->get_prefix() << "\t"<< cmd << "\t:result ";

	size_t found = cmd.find(":");
	if (found != std::string::npos)
	{
		end = cmd.substr(found+1, cmd.size());
		start = cmd.substr(0, found);
	}
	else
		start = cmd;
	while ((found = start.find("  "))  != std::string::npos)
		start.erase(found, 1);
	std::istringstream stream(start.c_str());
	while(std::getline(stream, s, ' '))
	{
		_arr.push_back(s);
	}
	if (end.size() != 0)
	{
		_arr.push_back(end);
	}
}

void	Command::print_arr()
{
	std::cout << "command owner\t" << _client->get_prefix() << std::endl;
	std::cout  << "command size\t" << _arr.size() << std::endl;
	std::cout << "command\t\t";
	std::vector<std::string>::iterator	it = _arr.begin();
	while (it != _arr.end())
    {
        std::cout << it->c_str() << " ";
		it ++;
    }
	std::cout << std::endl;
}

int	Command::exec(Server &server)
{
	if (_arr.empty())
		return (0);
	if (_arr[0] == "CAP")
		return (cap());
	if (_arr[0] == "NICK")
		return (nick(server));
	else if (_arr[0] == "USER")
		return (user(server));
	else if (_arr[0] == "PASS")
		return (pass(server));
	else if (_arr[0] == "JOIN" && _client->is_registered() == true)
		return (join(server));
	else if (_arr[0] == "PART" && _client->is_registered() == true)
		return (part(server));
	else if (_arr[0] == "PRIVMSG" && _client->is_registered() == true)
		return (privmsg(server));
	else if (_arr[0] == "KICK" && _client->is_registered() == true)
		return (kick(server));
	else if (_arr[0] == "INVITE" && _client->is_registered() == true)
		return (invite(server));
	else if (_arr[0] == "MODE" && _client->is_registered() == true)
		return (mode(server));
	else if (_arr[0] == "TOPIC" && _client->is_registered() == true)
		return (topic(server));
	else if (_arr[0] == "PING" && _client->is_registered() == true)
		return (ping(server));
	else if (_arr[0] == "QUIT")
		return (quit(server));
	else if (_arr[0] == "WHO")
		return (0);
	else if (_arr[0] == "WHOIS")
		return (0);
	else if (_client->is_registered() == false)
		return (451);
	else
		return (421);
}

int	Command::cap()
{
	// if (_arr[1] == "LS")
	// 	send(_client->get_fd(), ":irc.example.com CAP * LS :multi-prefix account-notify", 28, 0);
	return (0);
}

int	Command::nick(Server &server)
{
	if (_client->get_pass().empty())
    {
        server.s->remove_fd(_client->get_fd());
        return (999);
    }
	const char forbiddenChars[7] = {' ', '@', '#', ':', '!', '%', '&'};
	if (_arr.size() != 2)
		return (461);
	if (_arr[1].size() > 9 || _arr[1].empty() || !isalpha(_arr[1][0]))
		return (432);
	for (std::string::const_iterator it = _arr[1].begin(); it != _arr[1].end(); ++it)
	{
        for (int i = 0; i < 7; ++i)
		{
            if (*it == forbiddenChars[i])
			{
                return (432);
            }
        }
    }
	if (server.get_client(_arr[1]) != NULL)
		return (433);
	_client->set_nick(_arr[1]);
	if (true == _client->check_registered(server))
	{
		send_welcom();
	}
	return (0);
}

int	Command::user(Server &server)
{
	if (_client->get_pass().empty())
    {
        server.s->remove_fd(_client->get_fd());
        return (999);
    }
	if (_arr.size() != 5)
		return (461);
	if (!_client->get_user().empty())
		return (462);
	_client->set_user(_arr[1]);
	_client->set_host(_arr[2]);
	if (true == _client->check_registered(server))
	{
		send_welcom();
	}
	return (0);
}

int	Command::pass(Server &server)
{
	if(_arr.size() != 2)
		return (461);
	if (!_client->get_pass().empty())
		return (462);
	_client->set_pass(_arr[1]);
	if (true == _client->check_registered(server))
	{
		send_welcom();
	}
	if (_arr[1] != server.get_pass()){
		server.s->remove_fd(_client->get_fd());
		return (999);
	}
	return (0);
}

int	Command::join(Server &server)
{
	Channel *ch;

	if(!(_arr.size() == 2 || _arr.size() == 3))
		return (461);
	ch = server.get_channel(_arr[1]);
	if (ch == NULL)
	{
		if (!_arr.empty() && !_arr[1].empty() && _arr[1][0] != '#')
			return (403);
		if (_arr[1].size() == 1)
			return (403);
		Channel *ch1 = new Channel(_arr[1], _client);
		server.add_channel(ch1);
		std::string mes = ":" + _client->get_prefix() + " JOIN :" + _arr[1] + "\n";
		_client->add_message(mes);
		mes = ":ft_irc 353 " + _client->get_nick() + " = " + _arr[1] + " :"
			+ ch1->get_member_list() + "\n";
		_client->add_message(mes);
		mes = ":ft_irc 366 " + _client->get_nick() + " " + _arr[1] + " :End of NAMES list\n";
		_client->add_message(mes);
		if (_arr.size() == 3)
			ch1->mode_password(true, _arr[2]);
		return (0);
	}
	if ((ch->get_mode() & INVITE) != 0 && _arr.size() == 2
			&& (!ch->is_invited(_client)))
		return (473);
	if ((ch->get_mode() & PASSWORD) != 0 && (_arr.size() == 3)
			&& (ch->get_pass() != _arr[2]))
		return (475);
	if ((ch->get_mode() & PASSWORD) != 0 && (_arr.size() == 2))
		return (475);
	if (ch->get_max() <= ch->get_member() && (ch->get_mode() & LIMIT) != 0)
		return (471);
	if (ch->is_exit(_client) == true)//エラーコードなしなんか表示させておく？
		return (0);
	ch->add_member(_client);
	{
		std::string mes = ":" + _client->get_prefix() + " JOIN :" + _arr[1] + "\n";
		ch->send_privmsg(mes, _client);
		if (!ch->get_topic().empty())
		{
			mes = ":ft_irc 332 " + _client->get_nick() + " " + _arr[1] + " :" + ch->get_topic() + "\n";
			// send(_client->get_fd(), mes.c_str(), mes.size(), 0);
		}
		mes += ":ft_irc 353 " + _client->get_nick() + " = " + _arr[1] + " :"
			+ ch->get_member_list() + "\n";
		// send(_client->get_fd(), mes.c_str(), mes.size(), 0);
		mes += ":ft_irc 366 " + _client->get_nick() + " " + _arr[1] + " :End of NAMES list\n";
		_client->add_message(mes);
		return (0);
	}
	return (UNKNOWN_ERROR);
}

int	Command::part(Server &server)
{
	Channel *ch;
	ch = server.get_channel(_arr[1]);

	if (ch == NULL)
		return (403);
	if (!(_arr.size() == 2 || _arr.size() == 3))
		return (461);
	if (ch->is_exit(_client) == false)
		return (442);
	std::string mes;
	mes = ":" + _client->get_prefix() + " PART " + _arr[1];
	if (_arr.size() == 2)
		mes += " :\n";
	else 
		mes += " :" + _arr[2] + "\n";
	ch->send_mes(mes);
	if (ch->delete_member(_client) == NO_MEMBER)
	{
		server.remove_channel(ch);
	}
	return (0);
}

int	Command::privmsg(Server &server)
{
	std::string	mes;
	if (_arr.size() != 3)
		return (461);
	mes = ":" + _client->get_prefix() + " PRIVMSG " + _arr[1] + " :" + _arr[2] + "\n";
	if (!_arr.empty() && !_arr[1].empty() && _arr[1][0] == '#')
	{
		Channel *ch = server.get_channel(_arr[1]);
		if (ch == NULL)
			return (401);
		if (ch->is_exit(_client) == false)//これ本家送れるけどどうなっている？
			return (404);
		ch->send_privmsg(mes, _client);
		return (0);
	}
	else
	{
		Client	*user = server.get_client(_arr[1]);
		if (user == NULL)//自分に送れるらしい
			return (401);
		user->add_message(mes);
		return (0);
	}
	return (0);
}

int	Command::kick(Server &server)
{
	std::string	mes;
	if (!(_arr.size() == 3 || _arr.size() == 4))
		return (461);
	if (!_arr.empty() && !_arr[1].empty() && _arr[1][0] != '#')
		return (403);

	Channel *ch = server.get_channel(_arr[1]);
	if (ch == NULL)
		return (403);
	if (ch->is_admin(_client) == false)
		return (482);
	Client	*cli = server.get_client(_arr[2]);
	if (cli == NULL)
		return (401);//arr2に入っている　治す必要あり
	if (ch->is_exit(_client) == false)
		return (442);//あれ？　これはぢ大丈夫
	if (ch->is_exit(cli) == false)
		return (401);//arr２　これはだめ
	if (_arr.size() == 3)
	{
		mes = ":" + _client->get_prefix() + " KICK " + _arr[1] + " " + _arr[2] + " :"
				+ _client->get_nick() + "\n";
	}
	else
	{
		mes = ":" + _client->get_prefix() + " KICK " + _arr[1] + " " + _arr[2] + " :"
				+ _arr[3] + "\n";
	}
	ch->send_mes(mes);
	ch->delete_member(cli);
	return (0);
}

int	Command::invite(Server &server)
{
	if (_arr.size() != 3)
		return (461);
	Client	*cli = server.get_client(_arr[1]);
	if (cli == NULL)
		return (401);
	Channel *ch = server.get_channel(_arr[2]);
	if (ch == NULL)
		return (403);//_arr2に入っている
	if (ch->is_exit(_client) == false)
		return (442);//sonnzaisinakutemo syoutaiokureru
	if(ch->is_exit(cli) == true)
		return (443);
	if (ch->is_admin(_client) == false)
		return (482);//sannpiryouronnari
	ch->add_invite(_arr[1]);
	std::string mes;
	mes = ":" + _client->get_prefix() + " INVITE " + _arr[1] + " " + _arr[2] + "\n";
	cli->add_message(mes);
	return (341);
}

int	Command::topic(Server & server)
{
	std::string mes;
	if (!(_arr.size() == 2 || _arr.size() == 3))
		return (461);
	Channel *ch = server.get_channel(_arr[1]);
	if (ch == NULL)
		return (403);//ここのエラー処理書いい？本家はないっぽい？
	if(ch->is_exit(_client) == false)
		return (442);
	if (_arr.size() == 2)
	{
		if (ch->get_topic().empty())
			mes = ":ft_irc 331 " + _client->get_nick() + " " + _arr[1] + " :No topic is set\n";
		else
			mes = ":ft_irc 332 " + _client->get_nick() + " " + _arr[1] + " :" + _arr[2] + "\n";
		_client->add_message(mes);
		return (0);
	}
	else
	{
		if (ch->is_admin(_client) == true)
			ch->set_topic(_arr[2]);
		else if((ch->get_mode() & TOPIC) != 0)
			return (482);
		else
			ch->set_topic(_arr[2]);
		mes = ":" + _client->get_prefix() + " TOPIC " + _arr[1] + " :" + _arr[2] + "\n";
		ch->send_mes(mes);
		return (0);
	}
	return (UNKNOWN_ERROR);
}

int	Command::ping(Server & server)
{
	(void)server;
	std::string mes = ":ft_irc PONG ft_irc :127.0.0.1\r\n";
	_client->add_message(mes);
	return (0);
}

int	Command::mode(Server & server)
{
	std::string	msg;
	if (_arr.size() == 3 && _arr[1].at(0) != '#')
		return (0);
	if (!(_arr.size() == 2 ||  _arr.size() == 3 || _arr.size() == 4))
		return (461);

	Channel *ch = server.get_channel(_arr[1]);
	if (ch == NULL)
		return (403);
	if(ch->is_exit(_client) == false)
		return (442);
	if (_arr.size() == 2)
	{
		int mode = ch->get_mode();
		msg = ":ft_irc 324" + _client->get_nick() + " " + _arr[1] + " +";
		if ((mode & PASSWORD) != 0)
			msg += "k";
		if ((mode & LIMIT) != 0)
			msg += "l";
		if ((mode & INVITE) != 0)
			msg += "i";
		if ((mode & TOPIC) != 0)
			msg += "t";
		if ((mode & PASSWORD) != 0)
			msg += " " + ch->get_pass();
		if ((mode & LIMIT) != 0)
		{
			unsigned int maxuser = ch->get_max();
			std::stringstream ss;
    		ss << maxuser;
			std::string maxuserstr = ss.str();
			msg += " " + maxuserstr;
		}
		msg += "\n";
		_client->add_message(msg);
		return (0);
	}
	if (ch->is_admin(_client) == false && _arr.size() != 2)
		return (482);
	if (_arr[2] == "+i" && _arr.size() == 3){
		ch->mode_invite(true);
		msg = ":" + _client->get_prefix() + " MODE " + _arr[1] + " " + _arr[2] + "\n";
		}
	else if(_arr[2] == "-i" && _arr.size() == 3){
		ch->mode_invite(false);
		msg = ":" + _client->get_prefix() + " MODE " + _arr[1] + " " + _arr[2] + "\n";
		}
	else if(_arr[2] == "+t" && _arr.size() == 3){
		ch->mode_topic(true);
		msg = ":" + _client->get_prefix() + " MODE " + _arr[1] + " " + _arr[2] + "\n";
		}
	else if(_arr[2] == "-t" && _arr.size() == 3){
		ch->mode_topic(false);
		msg = ":" + _client->get_prefix() + " MODE " + _arr[1] + " " + _arr[2] + "\n";
		}
	else if (_arr[2] == "+k" && _arr.size() == 4){
		ch->mode_password(true, _arr[3]);
		msg = ":" + _client->get_prefix() + " MODE " + _arr[1] + " " 
			+ _arr[2] + " " +  _arr[3] + "\n";
		}
	else if(_arr[2] == "-k" && _arr.size() == 4){
		ch->mode_password(false, "");
		msg = ":" + _client->get_prefix() + " MODE " + _arr[1] + " " + _arr[2] + "\n";
		}
	else if(_arr[2] == "+l" && _arr.size() == 4){
		ch->set_maxmember(static_cast<unsigned int>(atoi(_arr[3].c_str())));//この文やばめby GPT suujiigai
		ch->mode_limit(true);
		msg = ":" + _client->get_prefix() + " MODE " + _arr[1] + " " 
			+ _arr[2] + " " +  _arr[3] + "\n";
		}
	else if (_arr[2] == "-l" && _arr.size() == 3){
		ch->mode_limit(false);
		msg = ":" + _client->get_prefix() + " MODE " + _arr[1] + " " + _arr[2] + "\n";
		}
	else if ((_arr[2] == "+o" || _arr[2] == "-o") && _arr.size() == 4)
	{
		Client *cli = server.get_client(_arr[3]);
		if (cli == NULL)//ここのエラーぶん変えるべき_arr[3]
			return (401);
		if (ch->is_exit(cli) == false)//ここのエラーぶん変えるべき
			return (441);
		if (_arr[2] == "+o")
			ch->give_admin(cli);
		else if(_arr[2] =="-o")
			ch->take_admin(cli);
		msg = ":" + _client->get_prefix() + " MODE " + _arr[1] + " " 
			+ _arr[2] + " " +  _arr[3] + "\n";
	}
	ch->send_mes(msg);
	return (0);
}

int	Command::quit(Server & server)
{
	server.s->remove_fd(_client->get_fd());
	return (999);
	return (0);
}


void	Command::send_welcom()
{
	std::string mse = "001 " + _client->get_nick() + " :Welcome to the Internet Relay Network "
			+ _client->get_prefix() + "\n";
	mse += "002 " + _client->get_nick() + " :Your host is ft_irc, running version 1.0\r\n";
	mse += "003 " + _client->get_nick() + " :This server was created Mon Jul 9 2024 at 12:34:56 UTC\r\n";
	mse += "004 " + _client->get_nick() + " :ft_irc 1.0 o tikl\r\n";
	_client->add_message(mse);
}