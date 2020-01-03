/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:46:28 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/03 14:18:09 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include "Intern.hpp"
# include "Bureaucrat.hpp"

class OfficeBlock
{
private:
	Intern const *intern;
	Bureaucrat const *signer;
	Bureaucrat const *executor;
public:
	OfficeBlock();
	OfficeBlock(Intern const &intern, Bureaucrat const &signer, Bureaucrat const &executor);
	virtual ~OfficeBlock();

	class InternAlreadyAssignedException: public std::exception {
		virtual const char* what() const throw();
	};
	class BureaucratAlreadyAssignedException: public std::exception {
		virtual const char* what() const throw();
	};
	class MissingOfficeMember: public std::exception {
		virtual const char* what() const throw();
	};

	void setIntern(Intern const &intern);
	void setSigner(Bureaucrat const &signer);
	void setExecutor(Bureaucrat const &executor);

	void doBureaucracy(std::string const &formName, std::string const &target);
};

#endif
