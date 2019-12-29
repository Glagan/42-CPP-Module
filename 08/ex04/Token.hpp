/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:43:59 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 19:44:02 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_HPP
# define TOKEN_HPP

class Token
{
private:
public:
	Token();
	Token(Token const &other);
	virtual ~Token();

	Token &operator=(Token const &other);

};

#endif
