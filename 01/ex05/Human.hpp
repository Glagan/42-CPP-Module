/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:58:26 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/15 16:16:27 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Human
{
private:
	const Brain	brain;
public:
	Human();
	~Human();

	const Brain	&getBrain(void) const;
	std::string	identify(void) const;
};

#endif
