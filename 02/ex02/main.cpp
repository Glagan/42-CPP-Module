/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:46:46 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/17 19:18:19 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 5.05f ) / Fixed( 2 ) );
	Fixed d(a);
	Fixed e(d);

	std::cout << "# increment tests" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "min: " << Fixed::min(a, b) << std::endl;
	std::cout << "max: " << Fixed::max(a, b) << std::endl;
	std::cout << "# decrement tests" << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "min: " << Fixed::min(a, b) << std::endl;
	std::cout << "max: " << Fixed::max(a, b) << std::endl;
	std::cout << "# condition tests" << std::endl;
	std::cout << c << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << e << " == " << a << "\t\t" << (e == a) << std::endl;
	std::cout << e << " != "  << d << "\t\t\t" << (e != d) << std::endl;
	std::cout << e << " > " << a << "\t\t" << (e > a) << std::endl;
	std::cout << e << " < " << b << "\t\t" << (e < b) << std::endl;
	std::cout << b << " <= " << c << "\t" << (b <= c) << std::endl;
	std::cout << a << " >= " << c << "\t" << (a >= c) << std::endl;
	return (0);
}