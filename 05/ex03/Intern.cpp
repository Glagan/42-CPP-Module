/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:04:58 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/02 14:42:25 by ncolomer         ###   ########.fr       */
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

const char* Intern::FormDoesNotExistException::what() const throw()
{
	return "InternException: Form does not exist";
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
		std::cout << "Intern creates " << form << std::endl;
	return (form);
}
