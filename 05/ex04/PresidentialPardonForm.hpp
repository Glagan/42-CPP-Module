/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:41:12 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/02 17:19:03 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
private:
	PresidentialPardonForm();

	std::string const target;
public:
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	virtual ~PresidentialPardonForm();

	static std::string const &name;

	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

	void execute(Bureaucrat const &executor) const;

	static Form *generate(std::string const &target);
};

#endif
