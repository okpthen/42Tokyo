/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:51:58 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/20 02:26:23 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include <limits> 
#include <cstdlib>

class Contact
{
	private:
		std::string	firsername;
		std::string lastname;
		std::string nickname;
		std::string phonenumber;
		std::string darkestsecret;
		std::string	input(std::string str);
		std::string	output(std::string str);
	public:
		Contact();
		void	register_contact(void);
		void	show_contact(int num);
		void	show_all(void);
};

#endif