/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LoopReference.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:39:22 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/30 14:41:23 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOPREFERENCE_HPP
# define LOOPREFERENCE_HPP

class LoopReference
{
private:
	int entryInt;
	int exitInt;
public:
	LoopReference(int entryInt, int exitInt);
	LoopReference(LoopReference const &other);
	virtual ~LoopReference();

	LoopReference &operator=(LoopReference const &other);

	int getEntryInt(void) const;
	int getExitInt(void) const;
};

#endif
