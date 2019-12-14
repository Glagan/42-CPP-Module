/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:00:09 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/14 16:46:50 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Annuaire.class.hpp"

int
	main(int argc, char const *argv[])
{
	Annuaire	annuaire;
	bool		run;
	std::string	command;

	(void)argc;
	(void)argv;
	annuaire.show_startup();
	run = true;
	while (run)
	{
		std::cout << ">";
		std::getline(std::cin, command);
		if (command == "HELP")
			annuaire.show_help();
		else if (command == "ADD")
			annuaire.add_contact();
		else if (command == "SEARCH")
			annuaire.search_contact();
		else if (command == "EXIT")
		{
			std::cout << "# Bye." << std::endl;
			run = false;
		}
	}
	return (0);
}
