/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:06:44 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/19 18:13:53 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sed.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 4)
		std::cout << "error: Invalid number of arguments.\nusage: filename search replace" << std::endl;
	else
	{
		try
		{
			Sed::replace(argv[1], argv[2], argv[3]);
		}
		catch(char const *e)
		{
			std::cerr << "replace: error: " << e << std::endl;
		}
	}
	return (0);
}
