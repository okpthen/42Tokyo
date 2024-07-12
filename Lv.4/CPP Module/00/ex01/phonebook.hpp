/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:46:59 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/17 14:24:24 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOH_HPP
# define PHONEBOOH_HPP

#include "contact.hpp"

class PhoneBook
{
	private:
		Contact	phonebook[8];
	public:
		PhoneBook();
		void	search();
		void	hello();
		void	add();
		void	error();
		void	enter();
};


#endif