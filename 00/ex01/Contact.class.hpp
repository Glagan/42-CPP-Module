/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:04:23 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/14 16:10:23 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
private:
	int					index;
	static std::string	fields_name[11];
	std::string			informations[11];
public:
	Contact();
	~Contact();

	void	set_informations(int index);
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
		Birthday,
		FavoriteMeal,
		UnderwearColor,
		Secret
	};
};

#endif