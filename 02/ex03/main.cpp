/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:46:46 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/18 13:43:31 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Expression.hpp"

int main(int argc, char const **argv)
{
	if (argc != 2)
	{
		std::cout << "eval_expr: error: bad arguments.\n";
		std::cout << "           usage: expr" << std::endl;
	}
	else
	{
		Fixed acc(0);
		try
		{
			std::cout << Expression::calculate(acc, argv[1]) << std::endl;
		}
		catch (char const *e)
		{
			std::cerr << "eval_expr: error: " << e << std::endl;
		}
	}
	return (0);
}