/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:32:25 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 17:59:36 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEVENT_HPP
# define ZOMBIEVENT_HPP

# include <iostream>
# include <string>
# include "Zombie.hpp"

class ZombieEvent
{
private:
	std::string	type;
public:
	ZombieEvent();
	virtual ~ZombieEvent();

	void 		setZombieType(std::string const &type);
	Zombie		*newZombie(std::string const &name);
	Zombie		*randomChump(void);
};

#endif
