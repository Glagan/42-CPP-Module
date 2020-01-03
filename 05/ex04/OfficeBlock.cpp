/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:46:16 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/03 14:18:13 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock():
	intern(nullptr), signer(nullptr), executor(nullptr)
{
}

OfficeBlock::OfficeBlock(Intern const &intern, Bureaucrat const &signer, Bureaucrat const &executor):
	intern(&intern), signer(&signer), executor(&executor)
{
}

OfficeBlock::~OfficeBlock()
{
}

const char* OfficeBlock::InternAlreadyAssignedException::what() const throw()
{
	return "OfficeBlockException: Intern already assigned to another position";
}

const char* OfficeBlock::BureaucratAlreadyAssignedException::what() const throw()
{
	return "OfficeBlockException: Bureaucrat already assigned to another position";
}

const char* OfficeBlock::MissingOfficeMember::what() const throw()
{
	return "OfficeBlockException: Missing intern, signer or executor";
}

void OfficeBlock::setIntern(Intern const &intern)
{
	if (this->intern == &intern)
		throw InternAlreadyAssignedException();
	this->intern = &intern;
}

void OfficeBlock::setSigner(Bureaucrat const &signer)
{
	if (this->executor == &signer)
		throw BureaucratAlreadyAssignedException();
	this->signer = &signer;
}

void OfficeBlock::setExecutor(Bureaucrat const &executor)
{
	if (this->signer == &executor)
		throw BureaucratAlreadyAssignedException();
	this->executor = &executor;
}

void OfficeBlock::doBureaucracy(std::string const &formName, std::string const &target)
{
	if (!this->intern || !this->signer || !this->executor)
		throw MissingOfficeMember();
	Form *form = this->intern->makeForm(formName, target);
	try
	{
		this->signer->signForm(*form);
		this->executor->executeForm(*form);
	}
	catch(const std::exception& e)
	{
		delete form;
		throw;
	}
	delete form;
}
