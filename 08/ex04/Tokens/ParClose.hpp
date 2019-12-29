/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParClose.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:46:21 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 19:46:27 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCLOSE_HPP
# define PARCLOSE_HPP

# include "Token.hpp"

class ParClose: public Token
{
private:
public:
	ParClose();
	ParClose(ParClose const &other);
	virtual ~ParClose();

	ParClose &operator=(ParClose const &other);

};

#endif
