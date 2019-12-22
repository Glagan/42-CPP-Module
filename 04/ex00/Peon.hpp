/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:56:25 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 17:57:49 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon: public Victim
{
private:
	Peon();
public:
	Peon(std::string const &name);
	Peon(Peon const &peon);
	virtual ~Peon();

	Peon &operator=(const Peon& other);

	void getPolymorphed(void) const;
};

#endif
