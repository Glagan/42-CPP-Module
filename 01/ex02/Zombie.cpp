/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:25:55 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/14 19:08:49 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->type = "";
	this->name = "";
}

Zombie::Zombie(std::string type, std::string name)
{
	this->setCharacteristics(type, name);
}

Zombie::~Zombie()
{
	std::cout << "<" << this->name << "(" << this->type << ")> Died" << std::endl;
}

void Zombie::setCharacteristics(std::string type, std::string name)
{
	this->type = type;
	this->name = name;
}

/*
** https://stackoverflow.com/a/24586587
*/
std::string	Zombie::randomName(std::string::size_type length)
{
    static std::string chrs =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static std::mt19937 rg(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

    std::string s;
    s.reserve(length);
    while(length--)
        s += chrs[pick(rg)];
    return (s);
}

void Zombie::advert(void)
{
	std::cout << "<" << this->name << " (" << this->type << ")> ";
	std::cout << "Braiiiiiiinnnssss ..." << std::endl;
}
