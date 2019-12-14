/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:12:56 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/14 19:31:34 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class ZombieHorde
{
private:
	std::string	type;
	int			size;
	Zombie		*zombies;
public:
	ZombieHorde(std::string type, int size);
	~ZombieHorde();

	void	advert(void);
	void	announce(void);
};

#endif