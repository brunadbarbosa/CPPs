/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

/* Returns an iterator to the first occurrence of value in container.   */
/* Like the standard containers, "not found" is signaled by an error:   */
/* here a std::runtime_error is thrown.                                 */
template <typename T>
typename T::iterator easyfind(T &container, int value);

template <typename T>
typename T::const_iterator easyfind(T const &container, int value);

# include "easyfind.tpp"

#endif
