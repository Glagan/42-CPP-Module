/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:56:25 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/20 14:39:51 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class Peon: virtual public Victim
{
private:
public:
	Peon();
	Peon(std::string const &name);
	Peon(Peon const &peon);
	~Peon();

	Peon &operator=(const Peon& other);

	void getPolymorphed(void) const;
};

#endif
