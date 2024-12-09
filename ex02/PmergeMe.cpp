/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:14:50 by dolifero          #+#    #+#             */
/*   Updated: 2024/12/09 16:53:25 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_list = other._list;
	}
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
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
	if (ac < 2)
	{
		std::cerr << "Usage: " << av[0] << " [int1] [int2] ... [intN]" << std::endl;
		return false;
	}
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			if (!isdigit(av[i][j]))
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
	for (int i = 0; str[i]; i++)
		res = res * 10 + str[i] - '0';
	return res;
}

void PmergeMe::setInput(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		_vec.push_back(customAtoi(av[i]));
		_list.push_back(customAtoi(av[i]));
	}
}

template <typename Container>
Container merge(Container left, Container right)
{
	Container result;
	auto itLeft = left.begin();
	auto itRight = right.begin();

	while (itLeft != left.end() && itRight != right.end())
	{
		if (*itLeft < *itRight)
		{
			result.push_back(*itLeft);
			++itLeft;
		}
		else
		{
			result.push_back(*itRight);
			++itRight;
		}
	}
	while (itLeft != left.end())
	{
		result.push_back(*itLeft);
		++itLeft;
	}
	while (itRight != right.end())
	{
		result.push_back(*itRight);
		++itRight;
	}
	return result;
}

template <typename Container>
Container fordJohnsonSort(Container input)
{
	size_t n = input.size();

	if (n < 2)
		return input;
	if (n == 2)
	{
		auto it = input.begin();
		auto it2 = it++;
		if (*it > *it2)
			std::swap(it, it2);
		return input;
	}
	Container sorted;
	Container left;
	auto it = input.begin();
	for (size_t i = 0; i + 1 < n; i += 2)
	{
		auto first = it++;
		auto second = it++;
		if (*first > *second)
			std::swap(*first, *second);
		sorted.push_back(*first);
		left.push_back(*second);
	}
	if (n % 2 == 1)
		left.push_back(input.back());
	Container sortedLeft = fordJohnsonSort(sorted);
	Container sortedRight = fordJohnsonSort(left);
	return (merge(sortedLeft, sortedRight));
}

void PmergeMe::vectorSort()
{
	_vec = fordJohnsonSort(_vec);
}

void PmergeMe::listSort()
{
	_list = fordJohnsonSort(_list);
}

std::vector<int> PmergeMe::getVector() const
{
	return _vec;
}

std::list<int> PmergeMe::getList() const
{
	return _list;
}
