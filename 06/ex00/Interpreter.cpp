/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:47:28 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/23 18:25:18 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Interpreter.hpp"

Interpreter::Interpreter(std::string const &value):
	originalValue(value), impossibleInt(false), impossibleChar(false)
{
	if (this->tryAsInt())
		this->originalType = TypeInt;
	else if (this->tryAsFloat())
		this->originalType = TypeFloat;
	else if (this->tryAsDouble())
		this->originalType = TypeDouble;
	else if (this->tryAsChar())
		this->originalType = TypeChar;
	else
		this->originalType = TypeInvalid;
}

Interpreter::Interpreter(Interpreter const &other):
	originalValue(other.originalValue), originalType(other.originalType),
	impossibleInt(false), ivalue(other.ivalue),
	fvalue(other.fvalue), dvalue(other.dvalue),
	impossibleChar(false), cvalue(other.cvalue)
{
}

Interpreter::~Interpreter()
{
}

bool Interpreter::tryAsInt(void)
{
	try
	{
		this->ivalue = std::stoi(this->originalValue);
		this->fvalue = static_cast<float>(this->ivalue);
		this->dvalue = static_cast<double>(this->ivalue);
		this->cvalue = static_cast<char>(this->ivalue);
		return (true);
	}
	catch(const std::exception& e)
	{
	}
	return (false);
}

bool Interpreter::tryAsFloat(void)
{
	try
	{
		this->fvalue = std::stof(this->originalValue);
		if (std::isnan(this->fvalue) || std::isinf(this->fvalue))
		{
			std::cout << "isnan or inf" << std::endl;
			this->impossibleInt = true;
			this->impossibleChar = true;
		}
		this->ivalue = static_cast<int>(this->fvalue);
		this->dvalue = static_cast<double>(this->fvalue);
		this->cvalue = static_cast<char>(this->fvalue);
		return (true);
	}
	catch(const std::exception& e)
	{
	}
	return (false);
}

bool Interpreter::tryAsDouble(void)
{
	try
	{
		this->dvalue = std::stod(this->originalValue);
		if (std::isnan(this->dvalue) || std::isinf(this->dvalue))
		{
			std::cout << "isnan or inf" << std::endl;
			this->impossibleInt = true;
			this->impossibleChar = true;
		}
		this->ivalue = static_cast<int>(this->dvalue);
		this->fvalue = static_cast<float>(this->dvalue);
		this->cvalue = static_cast<char>(this->dvalue);
		return (true);
	}
	catch(const std::exception& e)
	{
	}
	return (false);
}

bool Interpreter::tryAsChar(void)
{
	if (this->originalValue.length() == 1)
	{
		this->cvalue = this->originalValue[0];
		this->ivalue = static_cast<int>(this->cvalue);
		this->fvalue = static_cast<float>(this->cvalue);
		this->dvalue = static_cast<double>(this->cvalue);
		return (true);
	}
	return (false);
}

Interpreter &Interpreter::operator=(Interpreter const &other)
{
	this->originalValue = other.originalValue;
	this->originalType = other.originalType;
	this->impossibleInt = other.impossibleInt;
	this->ivalue = other.ivalue;
	this->fvalue = other.fvalue;
	this->dvalue = other.dvalue;
	this->impossibleChar = other.impossibleChar;
	this->cvalue = other.cvalue;
	return (*this);
}

bool Interpreter::isImpossibleInt(void) const
{
	return (this->impossibleInt);
}

int Interpreter::getAsInt(void) const
{
	return (this->ivalue);
}

float Interpreter::getAsFloat(void) const
{
	return (this->fvalue);
}

double Interpreter::getAsDouble(void) const
{
	return (this->dvalue);
}

bool Interpreter::isImpossibleChar(void) const
{
	return (this->impossibleChar);
}

char Interpreter::getAsChar(void) const
{
	return (this->cvalue);
}

std::ostream &operator<<(std::ostream &out, Interpreter const &pr)
{
	if (pr.isImpossibleChar())
		std::cout << "char: impossible" << '\n';
	else if (std::isprint(pr.getAsChar()))
		std::cout << "char: '" << pr.getAsChar() << "'\n";
	else
		std::cout << "char: Non displayable" << '\n';
	if (pr.isImpossibleInt())
		std::cout << "int: impossible" << '\n';
	else
		std::cout << "int: " << pr.getAsInt() << '\n';
	std::cout << "float: " << pr.getAsFloat() << "f\n"
			<< "double: " << pr.getAsDouble() << std::endl;
	return (out);
}
