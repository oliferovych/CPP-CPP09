/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:15:05 by dolifero          #+#    #+#             */
/*   Updated: 2024/12/06 20:15:17 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <chrono>

long long get_time()
{
	return (std::chrono::duration_cast<std::chrono::microseconds>
		(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
}

int main(int ac, char **av)
{
	PmergeMe p;
	long long init_time;
	long long sort_time;

	init_time = get_time();
	if(!p.checkInput(ac, av))
		return 1;
	p.setInput(ac, av);
	init_time = get_time() - init_time;
	sort_time = get_time();
	p.mergeSort();
	sort_time = get_time() - sort_time;
	std::cout << "Before: ";
	p.printVector(p.getInput());
	std::cout << "After: ";
	p.printVector(p.getOutput());
	std::cout << "Time to process a range of " << p.getInput().size() << " integers: " << init_time << "µs" << std::endl;
	std::cout << "Time to sort a range of " << p.getInput().size() << " integers: " << sort_time << "µs" << std::endl;
	return 0;
}