/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:04:58 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/23 16:49:15 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &other)
{
	(void)other;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return (*this);
}

Form *Intern::makeForm(std::string const &formName, std::string const &target) const
{
	Form *form = nullptr;

	if (PresidentialPardonForm::name == formName)
		form = new PresidentialPardonForm(target);
	else if (RobotomyRequestForm::name == formName)
		form = new RobotomyRequestForm(target);
	else if (ShrubberyCreationForm::name == formName)
		form = new ShrubberyCreationForm(target);
	if (form == nullptr)
	{
		std::cout << formName << " does not exist" << std::endl;
		throw Intern::FormDoesNotExistException();
	}
	else
		std::cout << "Intern creates " << *form << " targeted at " << target << std::endl;
	return (form);
}
