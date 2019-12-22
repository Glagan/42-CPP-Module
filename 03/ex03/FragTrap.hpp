/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:00:10 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 17:58:12 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
private:
	FragTrap();
protected:
	static const int nbrQuotes = 5;
	static std::string quotes[FragTrap::nbrQuotes];
public:
	FragTrap(std::string const &name);
	FragTrap(FragTrap const &other);
	virtual ~FragTrap();

	FragTrap &operator=(FragTrap const &other);

	void meleeAttack(std::string const &target);
	void rangedAttack(std::string const &target);
	void vaulthunter_dot_exe(std::string const &target);
};

#endif