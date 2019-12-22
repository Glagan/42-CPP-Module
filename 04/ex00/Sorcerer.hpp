/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:28:15 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 17:57:47 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"

class Sorcerer
{
private:
	Sorcerer();

	std::string name;
	std::string title;
public:
	Sorcerer(std::string const &name, std::string const &title);
	Sorcerer(const Sorcerer& other);
	virtual ~Sorcerer();

	Sorcerer &operator=(const Sorcerer& other);

	std::string const &getName(void) const;
	std::string const &getTitle(void) const;

	void polymorph(Victim const &victim) const;
};

std::ostream &operator<<(std::ostream &out, Sorcerer const &sorcerer);

#endif
