/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 14:52:07 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/21 15:02:04 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
private:
public:
	Ice();
	Ice(Ice const &other);
	virtual ~Ice();

	Ice &operator=(Ice const &other);

	AMateria *clone(void) const;
	void use(ICharacter &target);
};

#endif
