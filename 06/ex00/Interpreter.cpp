/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:47:28 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/27 17:28:49 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Interpreter.hpp"

Interpreter::Interpreter(std::string const &value):
	str(value), type(TypeInvalid)
{
	for (int i = 0; i < 4; i++)
		this->status[i] = 0;
	this->parse();
	if (this->type != TypeInvalid)
	{
		this->convert();
		if (this->lvalue > std::numeric_limits<int>::max())
			this->setFlag(TypeInt, this->isImpossible);
		else if (this->lvalue < std::numeric_limits<int>::min())
			this->setFlag(TypeInt, this->isImpossible);
		if (this->hasFlag(TypeInt, this->isImpossible)
			|| this->ivalue > 127 || this->ivalue < 0)
			this->setFlag(TypeChar, this->isImpossible);
		if (!std::isprint(this->cvalue))
			this->setFlag(TypeChar, this->nonDisplayable);
	}
	else
	{
		this->setFlag(TypeInt, this->isImpossible);
		this->setFlag(TypeFloat, this->isImpossible);
		this->setFlag(TypeDouble, this->isImpossible);
		this->setFlag(TypeChar, this->isImpossible);
	}
}

Interpreter::Interpreter(Interpreter const &other):
	str(other.str), type(other.type),
	ivalue(other.ivalue), fvalue(other.fvalue),
	dvalue(other.dvalue), cvalue(other.cvalue)
{
	for (int i = 0; i < 4; i++)
		this->status[i] = other.status[i];
}

Interpreter::~Interpreter()
{
}

void Interpreter::parse(void)
{
	size_t length = this->str.length();
	size_t i = 0;

	if (length == 1 && !std::isdigit(this->str[0]))
	{
		this->type = TypeChar;
		this->cvalue = this->str[0];
		return ;
	}
	if (this->str[0] == '+' || this->str[0] == '-')
		i++;
	this->type = TypeInt;
	for ( ; i < length; i++)
	{
		if (this->str[i] == '.')
			this->type = TypeDouble;
		else if (this->str[i] == 'f' && i == length - 1 && this->type == TypeDouble)
			this->type = TypeFloat;
		else if (!std::isdigit(this->str[i]))
		{
			this->type = TypeInvalid;
			i = length;
		}
	}
	if (this->type == TypeDouble)
	{
		try
		{
			this->dvalue = std::stod(this->str);
		}
		catch(const std::exception& e)
		{
			this->type = TypeInvalid;
		}
	}
	else if (this->type == TypeFloat)
	{
		try
		{
			this->fvalue = std::stof(this->str);
		}
		catch(const std::exception& e)
		{
			this->type = TypeInvalid;
		}
	}
	else if (this->type == TypeInt)
	{
		try
		{
			this->ivalue = std::stoi(this->str);
		}
		catch(const std::exception& e)
		{
			this->lvalue = std::stol(this->str);
			this->type = TypeLong;
		}
	}
	else if (this->type == TypeInvalid)
	{
		if (this->str == "inff" || this->str == "-inff" || this->str == "+inff"
			|| this->str == "nanf")
		{
			this->fvalue = std::stof(this->str);
			this->type = TypeFloat;
		}
		else if (this->str == "inf" ||  this->str == "-inf" || this->str == "+inf"
				|| this->str == "nan")
		{
			this->dvalue = std::stod(this->str);
			this->type = TypeDouble;
		}
	}
}

void Interpreter::convert(void)
{
	switch (this->type)
	{
	case TypeLong:
		this->fromLong();
		break;
	case TypeInt:
		this->fromInt();
		break;
	case TypeFloat:
		this->fromFloat();
		break;
	case TypeDouble:
		this->fromDouble();
		break;
	case TypeChar:
		this->fromChar();
		break;
	}
}

void Interpreter::fromLong(void)
{
	this->fvalue = static_cast<float>(static_cast<int>(this->lvalue));
	this->dvalue = static_cast<double>(static_cast<int>(this->lvalue));
	this->cvalue = static_cast<char>(static_cast<int>(this->lvalue));
}

void Interpreter::fromInt(void)
{
	this->fvalue = static_cast<float>(this->ivalue);
	this->dvalue = static_cast<double>(this->ivalue);
	this->cvalue = static_cast<char>(this->ivalue);
}

bool Interpreter::floatIsValue(void) const
{
	return (!(std::isnan(this->fvalue) || std::isinf(this->fvalue)));
}

bool Interpreter::doubleIsValue(void) const
{
	return (!(std::isnan(this->dvalue) || std::isinf(this->dvalue)));
}

void Interpreter::fromFloat(void)
{
	this->lvalue = static_cast<long>(this->fvalue);
	this->ivalue = static_cast<int>(this->fvalue);
	this->dvalue = static_cast<double>(this->fvalue);
	this->cvalue = static_cast<char>(this->fvalue);
	if (!this->floatIsValue())
		this->setFlag(TypeInt, this->isImpossible);
}

void Interpreter::fromDouble(void)
{
	this->lvalue = static_cast<long>(this->dvalue);
	this->ivalue = static_cast<int>(this->dvalue);
	this->fvalue = static_cast<float>(this->dvalue);
	this->cvalue = static_cast<char>(this->dvalue);
	if (!this->doubleIsValue())
		this->setFlag(TypeInt, this->isImpossible);
}

void Interpreter::fromChar(void)
{
	this->lvalue = static_cast<long>(this->cvalue);
	this->ivalue = static_cast<int>(this->cvalue);
	this->fvalue = static_cast<float>(this->cvalue);
	this->dvalue = static_cast<double>(this->cvalue);
}

void Interpreter::setFlag(int status, int flag)
{
	this->status[status] |= flag;
}

bool Interpreter::hasFlag(int status, int flag) const
{
	return (this->status[status] & flag);
}

Interpreter &Interpreter::operator=(Interpreter const &other)
{
	this->str = other.str;
	this->type = other.type;
	for (int i = 0; i < 4; i++)
		this->status[i] = other.status[i];
	this->ivalue = other.ivalue;
	this->fvalue = other.fvalue;
	this->dvalue = other.dvalue;
	this->cvalue = other.cvalue;
	return (*this);
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

char Interpreter::getAsChar(void) const
{
	return (this->cvalue);
}

std::string const &Interpreter::getRaw(void) const
{
	return (this->str);
}

std::ostream &operator<<(std::ostream &out, Interpreter const &pr)
{
	std::stringstream ss;
	std::string tmp;

	if (pr.hasFlag(0, Interpreter::isImpossible))
		ss << "char: impossible" << '\n';
	else if (pr.hasFlag(0, Interpreter::nonDisplayable))
		ss << "char: Non displayable" << '\n';
	else
		ss << "char: '" << pr.getAsChar() << "'\n";

	if (pr.hasFlag(1, Interpreter::isImpossible))
		ss << "int: impossible" << '\n';
	else
		ss << "int: " << pr.getAsInt() << '\n';
	out << ss.str();
	ss.str(std::string());
	ss.clear();

	if (pr.hasFlag(2, Interpreter::isImpossible))
		ss << "float: impossible" << '\n';
	else
	{
		ss << "float: " << pr.getAsFloat();
		tmp = ss.str();
		if (pr.floatIsValue() && tmp.find('.') == std::string::npos)
			ss << ".0";
		ss << "f\n";
	}
	out << ss.str();
	ss.str(std::string());
	ss.clear();

	if (pr.hasFlag(3,  Interpreter::isImpossible))
		ss << "double: impossible";
	else
	{
		ss << "double: " << pr.getAsDouble();
		tmp = ss.str();
		if (pr.doubleIsValue() && tmp.find('.') == std::string::npos)
			ss << ".0";
	}
	out << ss.str() << std::endl;
	return (out);
}
