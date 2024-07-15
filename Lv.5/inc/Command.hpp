#ifndef COMMAND_HPP
# define COMMAND_HPP

#include "irc.hpp"
#include "Error.hpp"

class	Server;
class	Client;
class	Channel;
class	Error;

class	Command: public Error
{
	std::vector<std::string>	_lst;
	std::string 				_tmp;

	public:
		Command(std::string cmd, Client *client);
		Command();
		~Command();
		void	set_command(std::string &cmd, Client *client);
		
		void	exec_loop(std::string &cmdlst, Client *client, Server &server);

		int		exec(Server &server);

		int		cap();
		int		nick(Server &server);
		int		user(Server &server);
		int		pass(Server &server);
		int		join(Server &server);
		int		part(Server &server);
		int		privmsg(Server &server);
		int		kick(Server &server);
		int		invite(Server &server);
		int		mode(Server &server);
		int		topic(Server &server);
		int		ping(Server &server);
		int		quit(Server &server);

		void	print_arr();
		void	send_welcom();
};

#endif