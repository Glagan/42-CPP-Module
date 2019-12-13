/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:04:23 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/13 20:46:49 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string	informations[10];
	int			birthday[3];
public:
	Contact();
	~Contact();

	int 	create();
	int		valid_phone(void);
	int		valid_birthday(void);
	bool	set_informations(void);
	void	display_header(void);
	void	display(void);

	enum Field {
		FirstName = 0,
		LastName,
		Nickname,
		Login,
		Address,
		Email,
		Phone,
		BirthYear,
		BirthMonth,
		BirthDay,
		FavoriteMeal,
		UnderwearColor,
		Secret
	};

	enum BirthdayField {
		Day = 0,
		Month,
		Year
	};
};

#endif