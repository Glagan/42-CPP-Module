/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.ipp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:54:46 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/28 17:56:12 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename InputIterator>
void Span::addNumber(InputIterator begin, InputIterator end)
{
	if (this->numbers.size() + std::distance(begin, end) > this->max)
		throw Span::FullSpanException();
	for ( ; begin != end; begin++)
		this->numbers.push_back(*begin);
}
