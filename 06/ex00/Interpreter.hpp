/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:46:16 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/23 18:14:50 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_HPP
# define INTERPRETER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cctype>
# include <cmath>

class Interpreter
{
private:
	Interpreter();

	std::string originalValue;
	int originalType;

	bool impossibleInt;
	int ivalue;
	float fvalue;
	double dvalue;
	bool impossibleChar;
	char cvalue;

	bool tryAsInt(void);
	bool tryAsFloat(void);
	bool tryAsDouble(void);
	bool tryAsChar(void);

	enum Type {
		TypeInt,
		TypeDouble,
		TypeFloat,
		TypeChar,
		TypeInvalid
	};
public:
	Interpreter(std::string const &value);
	Interpreter(Interpreter const &other);
	virtual ~Interpreter();

	Interpreter &operator=(Interpreter const &other);

	bool isImpossibleInt(void) const;
	int getAsInt(void) const;
	float getAsFloat(void) const;
	double getAsDouble(void) const;
	bool isImpossibleChar(void) const;
	char getAsChar(void) const;
};

std::ostream &operator<<(std::ostream &out, Interpreter const &pr);

#endif
