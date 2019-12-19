/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Annuaire.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:09:26 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/19 17:38:44 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Annuaire.hpp"

Annuaire::Annuaire()
{
	this->amount = 0;
}

Annuaire::~Annuaire()
{
}

void Annuaire::show_startup(void)
{
	std::cout << "# ANNUAIRE" << std::endl;
	std::cout << "# Enter your command [HELP, ADD, SEARCH, EXIT]:" << std::endl;
}

void Annuaire::add_contact(void)
{
	if (this->amount == 8)
		std::cout << "# The directory is full !" << std::endl;
	else if (this->contacts[this->amount].set_informations(this->amount + 1))
		this->amount++;
}

void Annuaire::show_search_header(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < this->amount; i++)
		this->contacts[i].display_header();
	std::cout << "|-------------------------------------------|" << std::endl;
}

void Annuaire::search_contact(void)
{
	int	index;

	if (this->amount == 0)
		std::cout << "# Add a contact before searching !" << std::endl;
	else
	{
		this->show_search_header();
		std::cout << "# Enter Index to display Informations or 0 to Exit\n~";
		while (!(std::cin >> index) || (index < 0 || index > this->amount))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "# Invalid Index\n~";
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (index > 0)
			this->contacts[index - 1].display();
	}
}
