/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:08:41 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/02 14:34:31 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const &name, int const signGrade, int const executeGrade):
	name(name), _signed(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &other):
	name(other.name), _signed(other._signed), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "FormException: Grade too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "FormException: Grade too Low";
}

const char* Form::FormAlreadySignedException::what() const throw()
{
	return "FormException: The Form is already signed";
}

Form &Form::operator=(Form const &other)
{
	this->_signed = other._signed;
	return (*this);
}

std::string const &Form::getName(void) const
{
	return (this->name);
}

bool Form::isSigned(void) const
{
	return (this->_signed);
}

int Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int Form::getExecuteGrade(void) const
{
	return (this->executeGrade);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	else if (this->_signed)
		throw Form::FormAlreadySignedException();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "(" << form.getName() << ")[" << ((form.isSigned()) ? "Signed" : "Unsigned")
		<< "]<Sign:" << form.getSignGrade() << ",Execute:"
		<< form.getExecuteGrade() << ">";
	return (out);
}