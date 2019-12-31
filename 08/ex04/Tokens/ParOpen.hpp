/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParOpen.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:46:30 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/31 20:06:55 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAROPEN_HPP
# define PAROPEN_HPP

# include "Token.hpp"

class ParOpen: public Token
{
private:
public:
	ParOpen();
	ParOpen(ParOpen const &other);
	virtual ~ParOpen();

	ParOpen &operator=(ParOpen const &other);

	int getType(void) const;
	void display(void) const;
};

#endif
