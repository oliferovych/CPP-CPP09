/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:15:05 by dolifero          #+#    #+#             */
/*   Updated: 2024/12/09 17:04:13 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <chrono>

double get_time()
{
	return (std::chrono::duration_cast<std::chrono::microseconds>
		(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
}

int main(int ac, char **av)
{
	PmergeMe p;

	auto init_time = get_time();
	if(!p.checkInput(ac, av))
		return 1;
	p.setInput(ac, av);
	init_time = get_time() - init_time;
	auto vector_sort_time = get_time();
	p.vectorSort();
	vector_sort_time = get_time() - vector_sort_time;
	auto list_sort_time = get_time();
	p.listSort();
	list_sort_time = get_time() - list_sort_time;
	std::cout << "Before: ";
	for (int i = 1; i < ac; i++)
		std::cout << av[i] << " ";
	std::cout << std::endl;
	std::cout << "After: ";
	std::vector<int> vec = p.getVector();
	for (auto i = vec.begin(); i != vec.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "Time to sort given range of " << p.getList().size() << " integers with std::list: " << list_sort_time << "µs" << std::endl;
	std::cout << "Time to sort given range of " << p.getVector().size() << " integers with std::vector: " << vector_sort_time << "µs" << std::endl;
	return 0;
}


//./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
//./PmergeMe `jot -r 30 1 100 | tr '\n' ' '`
