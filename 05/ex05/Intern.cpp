/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:04:58 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/02 17:18:52 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	this->generators[0] = PresidentialPardonForm::generate;
	this->generators[1] = RobotomyRequestForm::generate;
	this->generators[2] = ShrubberyCreationForm::generate;
	this->generators[3] = Form::generate;
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
	int key = 	(formName == PresidentialPardonForm::name) 	? 0 :
				(formName == RobotomyRequestForm::name) 	? 1 :
				(formName == ShrubberyCreationForm::name) 	? 2 : 3;

	form = (*this->generators[key])(target);
	if (form == nullptr)
	{
		std::cout << formName << " does not exist" << std::endl;
		throw Intern::FormDoesNotExistException();
	}
	else
		std::cout << "Intern creates " << *form << std::endl;
	return (form);
}
