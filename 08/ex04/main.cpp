/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:35:59 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/30 16:40:31 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Postfix.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Postfix: error: missing expression" << std::endl;
	}
	else
	{
		try
		{
			Postfix poland(argv[1]);
		}
		catch(char const *e)
		{
			std::cerr << e << std::endl;
		}
	}
	return (0);
}
