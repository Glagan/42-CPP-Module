/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Postfix.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:37:23 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 19:44:22 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSTFIX_HPP
# define POSTFIX_HPP

# include <string>
# include <stack>
# include <list>
# include "Token.hpp"

class Postfix
{
private:
	int acc;
	std::string original;
	std::string simple;
	std::deque<Token*> tokens;
	std::deque<Token*> postfix;
public:
	Postfix();
	Postfix(Postfix const &other);
	virtual ~Postfix();

	Postfix &operator=(Postfix const &other);

	void simplify(void);
	void tokenize(void);
	void polish(void);
	void calculate(void);
};

#endif
