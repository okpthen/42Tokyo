#include "Channel.hpp"

Channel::Channel()
:_name(""),_topic(""), _maxmember(DEFAULT_MAXMEMBER), _pass(""), _mode(0)
{}

Channel::Channel(const std::string name, Client *client)
:_name(name),_topic(""), _maxmember(DEFAULT_MAXMEMBER), _pass(""), _mode(0)
{
	add_member(client);
}

Channel::~Channel(){}

void	Channel::add_member(Client *client)
{
	std::vector<std::pair<Client*, bool> >::iterator it = _members.begin();
	while (it != _members.end())
	{
		if (it->first == client)
			break ;
		it ++;
	}
	if (_members.size() == 0)
		_members.push_back(std::make_pair(client, true));
	else
		_members.push_back(std::make_pair(client, false));
	return ;
}

bool	Channel::delete_member(Client *client)//adminが全員消失の可能性あり
{
	std::vector<std::pair<Client*, bool> >::iterator it = _members.begin();
	while (it != _members.end())
	{
		if (it->first == client)
		{
			_members.erase(it);
			break ;
		}
		it ++;
	}
	if(_members.empty())
		return (NO_MEMBER);
	return (0);
}

void	Channel::add_invite(std::string name)
{
	_invite.push_back(name);
}

void	Channel::mode_password(bool is, const std::string pass)
{
	if (is == true)
	{
		_mode = _mode | PASSWORD;
		_pass = pass;
	}
	if (is == false)
	{
		_mode = _mode & ~PASSWORD;
		_pass = "";
	}
}

void	Channel::mode_invite(bool is)
{
	if (is)
		_mode = _mode | INVITE;
	else
		_mode = _mode & ~INVITE;
}

void	Channel::mode_topic(bool is)
{
	if (is)
		_mode = _mode | TOPIC;
	else
		_mode = _mode & ~TOPIC;
}

void	Channel::mode_limit(bool is)
{
	if (is)
		_mode = _mode | LIMIT;
	else
		_mode = _mode & ~LIMIT;
}

void	Channel::print_all() const
{
	std::cout << "name\t" << _name << std::endl
				<< "topic\t" << _topic << std::endl
				<< "member\t" << _members.size() << std::endl
				<< "max\t" << _maxmember << std::endl
				<< "pass\t" << _pass << std::endl
				<< "mode\t" << _mode << std::endl;
}

void	Channel::print_member()
{
	std::vector<std::pair<Client*, bool> >::iterator it = _members.begin();
	std::cout << "channel " << _name << " " << _members.size() <<  " members and admin" << std::endl;
	while (it != _members.end())
	{
		std::cout << it->first->get_nick() << "\t" << it->second << std::endl;
		it ++;
	}
}

int				Channel::get_mode() const {return _mode;}
std::string		Channel::get_name() const {return _name;}
std::string		Channel::get_pass() const {return _pass;}
unsigned int	Channel::get_max() const{return _maxmember;}
unsigned int	Channel::get_member() const{return _members.size();}
std::string		Channel::get_topic() const{return _topic;}


void	Channel::set_maxmember( const unsigned int num){ _maxmember = num;}
void	Channel::set_topic(const std::string topic){ _topic = topic;}

void	Channel::give_admin(const Client *client)
{
	std::vector<std::pair<Client*, bool> >::iterator it = _members.begin();
	while (it != _members.end())
	{
		if (it->first == client)
		{
			it->second = true;
			break ;
		}
		it ++;
	}
}

void	Channel::take_admin(const Client *client)//adminがいなくなる可能性あり
{
	std::vector<std::pair<Client*, bool> >::iterator it = _members.begin();
	while (it != _members.end())
	{
		if (it->first == client)
		{
			it->second = false;
			break ;
		}
		it ++;
	}
}

bool	Channel::is_admin(const Client *client)
{
	std::vector<std::pair<Client*, bool> >::iterator it = _members.begin();
	while (it != _members.end())
	{
		if (it->first == client && it->second == true)
			return (true);
		it ++;
	}
	return (false);
}

bool	Channel::is_exit(const Client *client)
{
	std::vector<std::pair<Client*, bool> >::iterator it = _members.begin();
	while (it != _members.end())
	{
		if (it->first == client)
			return (true);
		it ++;
	}
	return (false);
}

bool	Channel::is_invited(const Client *client)
{
	std::vector<std::string>::iterator it = _invite.begin();
	while (it != _invite.end())
	{
		if (*it == client->get_nick())
		{	
			_invite.erase(it);
			return (true);
		}
		it ++;
	}
	return (false);
}

void	Channel::send_mes(std::string mes)
{
	std::vector<std::pair<Client*, bool> >::iterator it = _members.begin();
	while (it != _members.end())
	{
		it->first->add_message(mes);
		it ++;
	}
}

void	Channel::send_privmsg(std::string mes, Client *client)
{
	std::vector<std::pair<Client*, bool> >::iterator it = _members.begin();
	while (it != _members.end())
	{
		if (it->first != client)
			it->first->add_message(mes);
		it ++;
	}
}

std::string	Channel::get_member_list() const
{
	std::string		res;
	 std::vector<std::pair<Client*, bool> >::const_iterator it = _members.begin();
	while (it != _members.end())
	{
		if (!res.empty())
            res += " ";
		if (it->second == true)
			res += "@" + it->first->get_nick();
		else
			res += it->first->get_nick();
        ++it;
	}
	return (res);
}

bool	Channel::operator==(const Channel& other) const 
{
	return _name == other._name;
}