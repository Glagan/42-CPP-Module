/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:46:16 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 19:59:51 by ncolomer         ###   ########.fr       */
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

void OfficeBlock::setIntern(Intern const &intern)
{
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
		return ;
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
