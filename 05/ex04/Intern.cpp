/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:04:58 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/03 14:13:34 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Pair::Pair(std::string const &name, Form *(*fct)(std::string const &)):
	name(name), fct(fct)
{
}

Intern::Pair::Pair(Pair const &other):
	name(other.name), fct(other.fct)
{
}

Intern::Pair::~Pair()
{
}

Intern::Pair &Intern::Pair::operator=(Pair const &other)
{
	(void)other;
	return (*this);
}

bool Intern::Pair::correspond(std::string const &name) const
{
	return (this->name == name);
}

Form *Intern::Pair::execute(std::string const &target) const
{
	return ((this->fct)(target));
}

Intern::Intern()
{
	this->generators[0] = new Intern::Pair("Presidential Pardon", PresidentialPardonForm::generate);
	this->generators[1] = new Intern::Pair("PresidentialPardon", PresidentialPardonForm::generate);
	this->generators[2] = new Intern::Pair("Presidential Pardon Form", PresidentialPardonForm::generate);
	this->generators[3] = new Intern::Pair("Robotomy Request", RobotomyRequestForm::generate);
	this->generators[4] = new Intern::Pair("RobotomyRequest", RobotomyRequestForm::generate);
	this->generators[5] = new Intern::Pair("Robotomy Request Form", RobotomyRequestForm::generate);
	this->generators[6] = new Intern::Pair("Shrubbery Creation", ShrubberyCreationForm::generate);
	this->generators[7] = new Intern::Pair("ShrubberyCreation", ShrubberyCreationForm::generate);
	this->generators[8] = new Intern::Pair("Shrubbery Creation Form", ShrubberyCreationForm::generate);
}

Intern::Intern(Intern const &other)
{
	(void)other;
}

Intern::~Intern()
{
	for (size_t i = 0; i < 9; i++)
		delete this->generators[i];
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

	for (size_t i = 0; !form && i < 9; i++)
		if (this->generators[i]->correspond(formName))
			form = this->generators[i]->execute(target);
	if (form == nullptr)
	{
		std::cout << formName << " does not exist" << std::endl;
		throw Intern::FormDoesNotExistException();
	}
	else
		std::cout << "Intern creates " << *form << std::endl;
	return (form);
}
