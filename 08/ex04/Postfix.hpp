/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Postfix.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:37:23 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/10 12:32:17 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSTFIX_HPP
# define POSTFIX_HPP

# include <algorithm>
# include <iostream>
# include <sstream>
# include <string>
# include <deque>
# include <stack>
# include "Token.hpp"
# include "Tokens/Num.hpp"
# include "Tokens/Op.hpp"
# include "Tokens/ParOpen.hpp"
# include "Tokens/ParClose.hpp"

class Postfix
{
private:
	int acc;
	std::string original;
	std::string simple;
	std::deque<Token*> tokens;
	std::deque<Token*> postfix;

	class InvalidNumberException: public std::exception {
		virtual const char* what() const throw();
	};

	class NoExpressionException: public std::exception {
		virtual const char* what() const throw();
	};

	class DivisionByZeroException: public std::exception {
		virtual const char* what() const throw();
	};
	class InvalidExpressionException: public std::exception {
		virtual const char* what() const throw();
	};

	bool isOperand(char c) const;
public:
	Postfix();
	Postfix(std::string const &expression);
	Postfix(Postfix const &other);
	virtual ~Postfix();

	Postfix &operator=(Postfix const &other);

	void setExpression(std::string const &expression);

	void simplify(void);
	void tokenize(void);
	void displayTokens(void) const;
	void polish(void);
	void displayPostfix(void) const;
	void displayStack(std::deque<int> const &stack) const;
	int execute(int a, char op, int b) const;
	void calculate(void);
};

#endif
