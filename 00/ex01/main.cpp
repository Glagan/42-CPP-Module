/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:00:09 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/13 20:38:28 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

int
	main(int argc, char const *argv[])
{
	Contact		annuaire[8];
	int			nbr_contacts;
	bool		cont, searching;
	std::string	command;
	int			i;

	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "~~~ANNUAIRE                 ~~~" << std::endl;
	std::cout << "~~~Everything will be erased~~~" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "~~~Enter your command [HELP, ADD, SEARCH, EXIT]:";
	nbr_contacts = 0;
	cont = true;
	while (cont)
	{
		std::cout << "\n>";
		std::getline(std::cin, command);
		if (command == "HELP")
		{
			std::cout << "~~~HELP to display this message" << std::endl;
			std::cout << "~~~ADD to add a contact" << std::endl;
			std::cout << "~~~SEARCH to search your contacts" << std::endl;
			std::cout << "~~~EXIT to exit this program" << std::endl;
		}
		else if (command == "ADD")
		{
			if (nbr_contacts == 8)
				std::cout << "~~~The list is too full !~~~" << std::endl;
			else if (annuaire[nbr_contacts].set_informations())
				nbr_contacts++;
		}
		else if (command == "SEARCH")
		{
			searching = true;
			while (searching)
			{
				std::cout << "~~~Contact List~~~" << std::endl;
				i = 0;
				while (i < nbr_contacts)
					annuaire[i++].display_header();
				std::cout << "~~~Enter Index to display Informations or 0 to Exit~~~\n>";
				std::cin >> i;
				if (i == 0)
					searching = false;
				else if (i < 0 || i > nbr_contacts)
					std::cout << "~~~Invalid Index~~~" << std::endl;
				else
				{
					annuaire[i].display();
					searching = false;
				}
			}
		}
		else if (command == "EXIT")
		{
			std::cout << "Come back soon !" << std::endl;
			cont = false;
		}
	}
	return 0;
}
