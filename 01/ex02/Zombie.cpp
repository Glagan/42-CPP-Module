/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:25:55 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/19 20:29:48 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie():
    type(std::string()), name(std::string())
{
}

Zombie::Zombie(std::string const &type, std::string const &name):
    type(type), name(name)
{
}

Zombie::~Zombie()
{
	std::cout << "<" << this->name << " (" << this->type << ")> Died" << std::endl;
}

void Zombie::setCharacteristics(std::string const &type, std::string const &name)
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
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ _";
    static std::mt19937 rg(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);
    std::string s;

    while(length--)
        s += chrs[pick(rg)];
    return (s);
}

void Zombie::announce(void)
{
	std::cout << "<" << this->name << " (" << this->type << ")> ";
	std::cout << "Braiiiiiiinnnssss ..." << std::endl;
}
