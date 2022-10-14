/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:58:23 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/13 10:23:40 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <iostream>
# include <iterator>
# include <vector>

template <typename T>
int	easyfind(T arr, int sec) {
	typename T::iterator iter_begin;
	typename T::iterator iter_end;
	iter_end = arr.end();
	iter_begin = arr.begin(); 
	for (int i = 0; iter_begin != iter_end; iter_begin++) {
		if (*iter_begin == sec)
			return i;
		i++;
	}
	return -1;
}

#endif