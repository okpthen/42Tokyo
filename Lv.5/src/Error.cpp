#include "Error.hpp"
#include <iostream>
#include "Client.hpp"



Error::Error(){}

Error::~Error(){}

void	Error::print_err(int num)
{
	std::string	mes;

	if (num == 0)
		return;
	if (num == 401)
		mes = ":ft_irc 401 " + _client->get_nick() + " " + _arr[1] +  " :No such nick/channel\n";
	else if (num == 403)
		mes = ":ft_irc 403 " + _client->get_nick() + " " + _arr[1] + " :No such channel\n";
	else if (num == 404)
		mes = ":ft_irc 404 " + _arr[1] + ":Cannot send to channel\n";
	else if (num == 421)
		mes = ":ft_irc 421 " + _client->get_nick() + " " + _arr[0] + " :Unknown command\n";
	else if (num == 432)
		mes = ":ft_irc 432 * " + _arr[1] + " :Erroneous Nickname\n";
	else if (num == 433)
		mes = ":ft_irc 433 * " + _arr[1] + " :Nickname is already in use\n";
	else if (num == 441)
		mes = ":ft_irc 441 " + _client->get_nick() + " " + _arr[1] + " :You're not on that channel\n";
	else if (num == 442)
		mes = ":ft_irc 442 " + _client->get_nick() + " " + _arr[1] + " :You're not on that channel\n";
	else if (num == 443)
		mes = ":ft_irc 443 " + _client->get_nick() + " " + _arr[1] + " :is already on channel\n";
	else if (num == 451)
		mes = ":ft_irc 451 :Not registered\n";
	else if (num == 461)
		mes = ":ft_irc 461 " + _client->get_nick() + " " + _arr[0] + " :Syntax error\n";
	else if (num == 462)
		mes = ":ft_irc 462 :You may not reregister\n";
	else if (num == 464)
	{
		if (_client->get_nick().size() == 0)
			mes = ":ft_irc 464 * :Password incorrect\n";
		else
			mes = ":ft_irc 464 " + _client->get_nick() + " :Password incorrect\n";
	}
	else if (num == 471)
		mes =  ":ft_irc 471 " + _client->get_nick() + " " + _arr[1] + " :Cannot join channel (+l)\n";
	else if (num == 473)
		mes =  ":ft_irc 473 " + _client->get_nick() + " " + _arr[1] + " :Cannot join channel (+i)\n";
	else if (num == 475)
		mes =  ":ft_irc 475 " + _client->get_nick() + " " + _arr[1] + " :Cannot join channel (+k)\n";
	else if (num == 476)
		mes = ":ft_irc 476 " + _arr[1] + " :Bad Channel Mask\n";
	else if (num == 482)
		mes = ":ft_irc 482 " + _client->get_nick() + " " + _arr[1] + " :You're not channel operator\n";
	else if (num == 324)
	{
		if (_arr.size() == 3)
			mes = _arr[1] + " "+  _arr[2] + "\n";
		else
			mes = _arr[1] + " "+ _arr[2] + " "+  _arr[3] + "\n";
		
	}
	else if (num == 332)
		mes = _arr[1] + " :No topic is set\n";
	else if (num == 331)
		mes = _arr[1] + " :" + _arr[2] + "\n";
	else if (num == 341)
		mes = ":ft_irc 341 " + _client->get_nick() + " " + _arr[2] + " :" + _arr[1] + "\n";
	_client->add_message(mes);
}
