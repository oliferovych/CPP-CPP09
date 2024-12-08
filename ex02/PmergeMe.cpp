/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:14:50 by dolifero          #+#    #+#             */
/*   Updated: 2024/12/06 20:14:51 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	if(this != &other)
	{
		_input = other._input;
		_output = other._output;
	}
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if(this != &other)
	{
		_input = other._input;
		_output = other._output;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::checkInput(int ac, char **av)
{
	if(ac < 2)
	{
		std::cerr << "Usage: " << av[0] << " [int1] [int2] ... [intN]" << std::endl;
		return false;
	}
	for(int i = 1; i < ac; i++)
	{
		for(int j = 1; j < ac; j++)
		{
			if(av[j] == av[i] && i != j)
			{
				std::cerr << "Error: input indexes " << j << " & " << i << ": duplicate input" << std::endl;
				return false;
			}
		}
		for(int j = 0; av[i][j]; j++)
		{
			if(!isdigit(av[i][j]))
			{
				std::cerr << "Error: " << av[i] << ": bad input" << std::endl;
				return false;
			}
		}
	}
	return true;
}

int customAtoi(char *str)
{
	int res = 0;
	for(int i = 0; str[i]; i++)
		res = res * 10 + str[i] - '0';
	return res;
}

void PmergeMe::setInput(int ac, char **av)
{
	for(int i = 1; i < ac; i++)
		_input.push_back(customAtoi(av[i]));
}

std::vector<int> merge(std::vector<int> left, std::vector<int> right)
{
	std::vector<int> result;
	size_t i = 0, j = 0;

	while(i < left.size() && j < right.size())
	{
		if(left[i] < right[j])
		{
			result.push_back(left[i]);
			i++;
		}
		else
		{
			result.push_back(right[j]);
			j++;
		}
	}
	while(i < left.size())
	{
		result.push_back(left[i]);
		i++;
	}
	while(j < right.size())
	{
		result.push_back(right[j]);
		j++;
	}
	return result;
}

std::vector<int> fordJohnsonSort(std::vector<int> input)
{
	size_t n = input.size();

	if(n < 2)
		return input;
	if(n == 2)
	{
		if(input[0] > input[1])
			std::swap(input[0], input[1]);
		return input;
	}
	std::vector<int> sorted;
	std::vector<int> left;
	for(size_t i = 0; i + 1 < n; i += 2)
	{
		if(input[i] > input[i + 1])
			std::swap(input[i], input[i + 1]);
		sorted.push_back(input[i]);
		left.push_back(input[i + 1]);
	}
	if(n % 2 == 1)
		left.push_back(input.back());
	std::vector<int> sortedLeft = fordJohnsonSort(sorted);
	std::vector<int> sortedRight = fordJohnsonSort(left);
	return (merge(sortedLeft, sortedRight));
}

void PmergeMe::printVector(std::vector<int> vec)
{
	for(size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::mergeSort()
{
	_output = fordJohnsonSort(_input);
}

std::vector<int> PmergeMe::getInput() const
{
	return _input;
}

std::vector<int> PmergeMe::getOutput() const
{
	return _output;
}
