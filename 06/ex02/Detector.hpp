/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Detector.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 19:04:10 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/27 19:09:14 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DETECTOR_HPP
# define DETECTOR_HPP

# include <iostream>
# include <random>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base *generate(void);

void identify_from_pointer(Base *p);
void identify_from_reference(Base &p);

#endif
