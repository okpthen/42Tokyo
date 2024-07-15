#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include "irc.hpp"

class	Client;

enum
{
	DEFAULT = 0x0000,
	INVITE	=  0x0001,
	PASSWORD =  0x0002,
	TOPIC = 0x0004,
	LIMIT = 0x0008,
};

# define CHANNEL_NAME_MAX 200
# define DEFAULT_MAXMEMBER 100
# define NO_MEMBER 1

class Channel
{
	private:
		std::string								_name;
		std::string								_topic;
		std::vector<std::pair<Client*, bool> >	_members;
		unsigned int							_maxmember;
		std::string								_pass;
		int										_mode;
		std::vector<std::string>				_invite;
		Channel();

	public:
		Channel(const std::string name, Client *client);
		~Channel();
		void	add_member(Client *client);
		bool	delete_member(Client *client);
		void	add_invite(std::string name);

		void	mode_invite(bool	is);
		void	mode_password(bool	is, const std::string pass);
		void	mode_topic(bool	is);
		void	mode_limit(bool is);
		void	set_topic(const std::string topic);
		void	set_maxmember(const unsigned int num);
		void	give_admin(const Client *client);
		void	take_admin(const Client *client);

		void		print_all() const;
		void		print_member();
		int			get_mode() const;
		std::string	get_name() const;
		std::string	get_pass() const;
		std::string	get_topic() const;
		bool		is_admin(const Client *client);
		bool		is_exit(const Client *client);
		bool		is_invited(const Client *client);
		unsigned int			get_max() const;
		unsigned int			get_member() const;
		std::string 			get_member_list() const;

		void	send_mes(std::string mes);
		void	send_privmsg(std::string mes, Client *cli);

		bool operator==(const Channel& other) const;

	// class	Err_ChannelIsfull:	public std::exception
	// {
	// 	virtual	const char* what() const throw(){ return ":server 471 <nickname> <channel> :Cannot join channel (+l)"; };
	// };
	// class	Err_ClientAlreadyMember:	public std::exception
	// {
	// 	virtual	const char* what() const throw(){ return "443 <nickname> <channel> :is already on channel"; };
	// };
	// class	Err_ClientIsNotMember:	public std::exception
	// {
	// 	virtual	const char* what() const throw(){ return "442 <nickname> <channel> :You're not on that channel"; };
	// };
	// class	Err_NoSuchNick: public std::exception
	// {
	// 	virtual	const char* what() const throw(){ return "401 <nickname> :No such nick/channel"; };
	// };
};

#endif

// MODE - チャネルのモードを変更する：
// i - 招待のみのチャネル設定/解除
// t - チャネルオペレーターにトピックコマンドの制限を設定/解除
// k - チャネルキー（パスワード）を設定/解除 パスワード
// o - チャネルオペレーター権限を付与/剥奪 権限のつ追加剥奪
// l - チャネルのユーザー制限を設定/解除 人数