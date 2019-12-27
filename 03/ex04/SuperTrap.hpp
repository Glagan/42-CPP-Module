/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:36:31 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/27 14:42:05 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <iostream>
# include <string>
# include "NinjaTrap.hpp"
# include "FragTrap.hpp"

class SuperTrap: public NinjaTrap, public FragTrap
{
private:
	SuperTrap();
public:
	SuperTrap(std::string const &name);
	SuperTrap(SuperTrap const &other);
	virtual ~SuperTrap();

	SuperTrap &operator=(SuperTrap const &other);

	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
};

#endif
