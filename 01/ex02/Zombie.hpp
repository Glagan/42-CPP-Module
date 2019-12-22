/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:24:33 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 17:59:38 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <random>

class Zombie
{
private:
	std::string	type;
	std::string	name;
public:
	Zombie();
	Zombie(std::string const &type, std::string const &name);
	virtual ~Zombie();

	void setCharacteristics(std::string const &type, std::string const &name);
	static std::string randomName(std::string::size_type length);
	void announce(void);
};

#endif