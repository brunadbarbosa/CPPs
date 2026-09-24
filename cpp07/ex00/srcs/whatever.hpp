/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b) {
	T tmp = a;

	a = b;
	b = tmp;
}

/* if they are equal, the second one is returned */
template <typename T>
T const &min(T const &a, T const &b) {
	return ((a < b) ? a : b);
}

/* if they are equal, the second one is returned */
template <typename T>
T const &max(T const &a, T const &b) {
	return ((a > b) ? a : b);
}

#endif
