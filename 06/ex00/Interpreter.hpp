/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:46:16 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/27 15:45:00 by ncolomer         ###   ########.fr       */
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

class Interpreter
{
private:
	Interpreter();

	static const int isImpossible = 0x00000001;
	static const int nonDisplayable = 0x00000010;

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
	bool hasFlag(int status, int flag);

	enum Type {
		TypeInt,
		TypeFloat,
		TypeDouble,
		TypeChar,
		TypeInvalid
	};
public:
	Interpreter(std::string const &value);
	Interpreter(Interpreter const &other);
	virtual ~Interpreter();

	Interpreter &operator=(Interpreter const &other);

	bool floatIsValue(void) const;
	bool doubleIsValue(void) const;

	int getAsInt(void) const;
	float getAsFloat(void) const;
	double getAsDouble(void) const;
	char getAsChar(void) const;
};

std::ostream &operator<<(std::ostream &out, Interpreter const &pr);

#endif
