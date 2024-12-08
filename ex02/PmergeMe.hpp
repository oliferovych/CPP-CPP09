/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:14:53 by dolifero          #+#    #+#             */
/*   Updated: 2024/12/06 20:14:54 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>

class PmergeMe
{
	private:
		std::vector<int> _input;
		std::vector<int> _output;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		bool checkInput(int ac, char **av);
		void setInput(int ac, char **av);
		void mergeSort();
		void printVector(std::vector<int> vec);

		std::vector<int> getInput() const;
		std::vector<int> getOutput() const;
};

std::vector<int> fordJohnsonSort(std::vector<int> input);