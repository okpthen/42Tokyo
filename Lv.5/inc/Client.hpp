#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "irc.hpp"
class Server;

enum	ClientStatus
{
	LOGIN,
	LOGOUT,
	REGISTERED,
	HANDSHAKE,
};

# define NICK_MAX 9

class Client
{
	private:
		int				_fd;
		std::string		_nickname;
		std::string		_username;
		std::string 	_passward;
		std::string		_hostname;
		ClientStatus	_status;
		std::string		_message;
	
	public:
		Client();
		Client(int fd);
		~Client();

		int				get_fd() const;
		std::string		get_nick() const;
		std::string		get_user() const;
		std::string		get_pass() const;
		std::string		get_host() const;
		std::string		get_status() const;
		std::string		get_prefix() const;
		std::string		get_message() const;

		void	set_fd(int fd);
		void	set_nick(const std::string &nick);
		void	set_user(const std::string &user);
		void	set_pass(const std::string &pass);
		void	set_host(const std::string &host);
		void	set_status(const ClientStatus status);
		void	set_message(const std::string &message);

		void	add_message(const std::string &message);

		bool	is_registered();
		bool	check_registered(Server &server);

		void	print_all();

		bool	operator==(const Client &n) const;
};

#endif