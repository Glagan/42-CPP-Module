/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:28:22 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 19:17:50 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "OfficeBlock.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	srand(time(NULL));
	Intern idiotOne;
	Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat jack = Bureaucrat("Jack K", 25);
	Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob;

	ob.setIntern(idiotOne);
	ob.setSigner(bob);

	try
	{
		ob.doBureaucracy("Shrubbery Creation", "home");
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		ob.setExecutor(bob);
	}
	catch(OfficeBlock::BureaucratAlreadyAssignedException & e)
	{
		std::cerr << bob << " has already a position in this Office Block" << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	ob.setExecutor(hermes);

	try
	{
		ob.doBureaucracy("Shrubbery Creation", "home");
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		ob.doBureaucracy("Presidential Pardon", "Morty");
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	ob.setSigner(jack);
	try
	{
		ob.doBureaucracy("Presidential Pardon", "Morty");
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
