#include "Client.hpp"

Client::Client():_hostname("127.0.0.1"), _status(HANDSHAKE), _message(""){}
Client::Client(int fd):_fd(fd),_hostname("127.0.0.1"),_status(HANDSHAKE), _message(""){}

Client::~Client(){}

int				Client::get_fd() const {return _fd;}
std::string		Client::get_nick() const {return _nickname;}
std::string		Client::get_user() const {return _username;}
std::string		Client::get_pass() const {return _passward;}
std::string		Client::get_host() const {return _hostname;}

std::string		Client::get_prefix() const
{
	std::string res;
	if (_nickname.empty())
		res = "\?\?\?!";
	else
		res = _nickname + "!";
	if (_username.empty())
		res += "\?\?\?";
	else
		res += _username;
	res += "@";
	res += _hostname;
	return (res);
}

std::string		Client::get_status() const
{
	if (_status == LOGIN)
		return ("login");
	else if (_status == LOGOUT)
		return (("logout"));
	else if (_status == REGISTERED)
		return ("registered");
	else if (_status == HANDSHAKE)
		return ("handshake");
	return ("");
}

std::string		Client::get_message() const {return (this->_message);}

void	Client::set_fd(int fd){_fd = fd;}
void	Client::set_nick(const std::string &nick){_nickname = nick;}
void	Client::set_user(const std::string &user){_username = user;}
void	Client::set_pass(const std::string &pass){_passward = pass;}
void	Client::set_host(const std::string &host){_hostname = host;}
void	Client::set_status(const ClientStatus status){_status = status;}
void	Client::set_message(const std::string &message){_message = message;}

void	Client::add_message(const std::string &message){this->_message.append(message);}

bool	Client::is_registered(){return (_status == REGISTERED ? true: false);}
bool	Client::check_registered(Server &server)
{
	if (_status == REGISTERED)
		return false;
	if (!_nickname.empty() && !_username.empty()
			&& (_passward.compare(server.get_pass()) == 0))
		{
			_status = REGISTERED;
			return true;
		}
		return false;
}

void	Client::print_all()
{
	std::cout << "nick\t" << _nickname << std::endl
				<< "user\t" << _username << std::endl
				<< "pass\t" << _passward << std::endl
				<< "host\t" << _hostname << std::endl
				<< "fd\t" << _fd << std::endl
				<< "status\t" << get_status() << std::endl
				<< "prefix\t" << get_prefix() << std::endl;
}

bool	Client::operator==(const Client &n) const
{ return (this->_nickname == n._nickname); }
