/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:24:33 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/14 18:56:54 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <random>

class Zombie
{
private:
	std::string	type;
	std::string	name;
public:
	Zombie();
	Zombie(std::string type, std::string name);
	~Zombie();

	void				setCharacteristics(std::string type, std::string name);
	static std::string	randomName(std::string::size_type length);
	void				advert(void);
};

#endif