/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Op.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:46:10 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 19:46:16 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_HPP
# define OP_HPP

# include "Token.hpp"

class Op: public Token
{
private:
public:
	Op();
	Op(Op const &other);
	virtual ~Op();

	Op &operator=(Op const &other);

};

#endif
