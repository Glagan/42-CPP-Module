/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:46:46 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/17 20:07:48 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Expression.hpp"

int main(int argc, char const **argv)
{
	if (argc != 2)
	{
		std::cout << "error: eval_expr: bad arguments.\n";
		std::cout << "           usage: expr" << std::endl;
	}
	else
		std::cout << Expression::calculate(argv[1]) << std::endl;
	return (0);
}