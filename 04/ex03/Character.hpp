/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 15:06:27 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 17:57:12 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter
{
private:
	Character();

	std::string name;
	int equipped;
	AMateria *inventory[4];
public:
	Character(std::string const &name);
	Character(Character const &other);
	virtual ~Character();

	Character &operator=(Character const &other);

	std::string const &getName(void) const;

	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif
