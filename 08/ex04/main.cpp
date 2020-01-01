/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:35:59 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/01 19:32:23 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Postfix.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
		std::cerr << "Postfix: error: missing expression" << std::endl;
	else
	{
		try
		{
			Postfix poland(argv[1]);
			poland.tokenize();
			poland.displayTokens();
			poland.polish();
			poland.displayPostfix();
			poland.calculate();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
