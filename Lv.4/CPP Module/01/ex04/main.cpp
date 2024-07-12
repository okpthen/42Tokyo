/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:42:13 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/18 16:52:41 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.hpp"

int main (int ac, char **av)
{
	File file(av);
	if (ac != 4)
	{
		std::cout << "Error: Invalid number of arguments." << std::endl;
		return (0);
	}
	file.replace();
	return (0);
}
