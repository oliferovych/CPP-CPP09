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
		_vec = other._vec;
		_list = other._list;
	}
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if(this != &other)
	{
		_vec = other._vec;
		_list = other._list;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
	_vec.clear();
	_list.clear();
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
	{
		_vec.push_back(customAtoi(av[i]));
		_list.push_back(customAtoi(av[i]));
	}
}


template <typename Container>
Container merge(Container left, Container right)
{
	Container result;
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

template <typename Container>
Container fordJohnsonSort(Container input)
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
	Container sorted;
	Container left;
	for(size_t i = 0; i + 1 < n; i += 2)
	{
		if(input[i] > input[i + 1])
			std::swap(input[i], input[i + 1]);
		sorted.push_back(input[i]);
		left.push_back(input[i + 1]);
	}
	if(n % 2 == 1)
		left.push_back(input.back());
	Container sortedLeft = fordJohnsonSort(sorted);
	Container sortedRight = fordJohnsonSort(left);
	return (merge(sortedLeft, sortedRight));
}

template <typename Container>
void PmergeMe::printContainer(Container vec)
{
	for(size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::vectorSort()
{
	_vec = fordJohnsonSort(_vec);
}

std::vector<int> PmergeMe::getVector() const
{
	return _vec;
}

std::list<int> PmergeMe::getList() const
{
	return _list;
}
