/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:14:47 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/05 15:26:16 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Number.hpp"

Number::Number():
	n(0)
{
}

Number::Number(int const &n):
	n(n)
{
}

Number::Number(Number const &other):
	n(other.n)
{
}

Number::~Number()
{
}

Number &Number::operator=(Number const &other)
{
	this->n = other.n;
	return (*this);
}

Number &Number::operator=(int value)
{
	this->n = value;
	return (*this);
}

bool Number::operator<(Number const &b)
{
	return (this->n < b.n);
}

bool Number::operator<=(Number const &b)
{
	return (this->n <= b.n);
}

bool Number::operator>(Number const &b)
{
	return (this->n > b.n);
}

bool Number::operator>=(Number const &b)
{
	return (this->n >= b.n);
}

bool Number::operator==(Number const &b)
{
	return (this->n == b.n);
}

bool Number::operator!=(Number const &b)
{
	return (this->n != b.n);
}

int Number::getValue(void) const
{
	return (this->n);
}

std::ostream &operator<<(std::ostream &out, Number const &n)
{
	out << n.getValue();
	return (out);
}
