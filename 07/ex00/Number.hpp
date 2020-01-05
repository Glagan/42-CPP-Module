/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:14:55 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/05 15:26:08 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBER_HPP
# define NUMBER_HPP

# include <ostream>

class Number
{
private:
	int n;
public:
	Number();
	Number(int const &a);
	Number(Number const &other);
	virtual ~Number();

	Number &operator=(Number const &other);
	Number &operator=(int value);

	bool operator<(Number const &b);
	bool operator<=(Number const &b);
	bool operator>(Number const &b);
	bool operator>=(Number const &b);
	bool operator==(Number const &b);
	bool operator!=(Number const &b);

	int getValue(void) const;
};

std::ostream &operator<<(std::ostream &out, Number const &n);

#endif
