/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:14:24 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/16 21:10:51 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(int const value):
	value(0)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = (value << Fixed::bits);
}

Fixed::Fixed(float const value):
	value(0)
{
	int decimal;

	std::cout << "Float constructor called" << std::endl;
	decimal = (int)value;
	this->value = (decimal << Fixed::bits);
	// TODO: Add fractional part to this->value
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = other.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
    out << value.toFloat();
    return (out);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	int tmp;
	float value;

	value = (this->value >> Fixed::bits);
	tmp = this->value;
	for (int i = Fixed::bits; i > 0; i--)
	{
		value += ((0x1 & tmp) * powf(2, -i));
		tmp = tmp >> 1;
	}
	return (value);
}

int Fixed::toInt(void) const
{
	return (this->value >> Fixed::bits);
}
