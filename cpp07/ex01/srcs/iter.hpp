/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

/* T is deduced as "const X" for a const array, so the same template works */
/* for const and non-const elements. F can be a function pointer (e.g. an */
/* instantiated function template) taking T by reference or const ref.    */
template <typename T, typename F>
void iter(T *array, size_t const length, F func) {
	if (!array)
		return ;
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif
