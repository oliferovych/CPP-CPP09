/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:14:53 by dolifero          #+#    #+#             */
/*   Updated: 2024/12/09 16:53:12 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <list>
#include <iostream>

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::list<int> _list;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		bool checkInput(int ac, char **av);
		void setInput(int ac, char **av);

		void vectorSort();
		void listSort();

		std::vector<int> getVector() const;
		std::list<int> getList() const;
};

template <typename Container>
Container fordJohnsonSort(Container input);
