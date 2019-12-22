/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:46:28 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 19:17:39 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include "Intern.hpp"
# include "Bureaucrat.hpp"

class OfficeBlock
{
private:
	Intern *intern;
	Bureaucrat *signer;
	Bureaucrat *executor;
public:
	OfficeBlock();
	OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executor);
	virtual ~OfficeBlock();

	class BureaucratAlreadyAssignedException: public std::exception {
		virtual const char* what() const throw() {
			return "OfficeBlockException: Bureaucrat already assigned to another position";
		}
	};

	void setIntern(Intern &intern);
	void setSigner(Bureaucrat &signer);
	void setExecutor(Bureaucrat &executor);

	void doBureaucracy(std::string const &formName, std::string const &target);
};

#endif
