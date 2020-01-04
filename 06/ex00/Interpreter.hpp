/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:46:16 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/04 16:27:11 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_HPP
# define INTERPRETER_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <cctype>
# include <cmath>
# include <limits>

class Interpreter
{
private:
	Interpreter();

	std::string str;
	int type;

	int status[4];
	int ivalue;
	float fvalue;
	double dvalue;
	char cvalue;

	void parse(void);

	void convert(void);
	void fromInt(void);
	void fromFloat(void);
	void fromDouble(void);
	void fromChar(void);

	void setFlag(int status, int flag);

	enum Type {
		TypeChar,
		TypeInt,
		TypeFloat,
		TypeDouble,
		TypeLong,
		TypeInvalid
	};
public:
	Interpreter(std::string const &value);
	Interpreter(Interpreter const &other);
	virtual ~Interpreter();

	static const int isImpossible = 0x00000001;
	static const int nonDisplayable = 0x00000010;

	Interpreter &operator=(Interpreter const &other);

	bool floatIsValue(void) const;
	bool doubleIsValue(void) const;
	bool hasFlag(int status, int flag) const;

	int getAsInt(void) const;
	float getAsFloat(void) const;
	double getAsDouble(void) const;
	char getAsChar(void) const;
	std::string const &getRaw(void) const;
};

std::ostream &operator<<(std::ostream &out, Interpreter const &pr);

#endif
