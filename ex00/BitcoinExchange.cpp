/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:45:28 by dolifero          #+#    #+#             */
/*   Updated: 2024/12/03 22:35:21 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	if(this != &other)
	{
		for(int i = 0; i < DATA_SIZE; i++)
			this->_data[i] = other._data[i];
	}
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if(this != &other)
	{
		for(int i = 0; i < DATA_SIZE; i++)
			this->_data[i] = other._data[i];
	}
	return *this;
}

void BitcoinExchange::loadData(void)
{
	std::ifstream file("data.csv");
	std::string line;
	std::string date;
	std::string value;
	if(!file.is_open())
	{
		std::cerr << "Error: Couldn't open file" << std::endl;
		exit(1);
	}
	std::getline(file, line);
	for(int i = 0; i < DATA_SIZE; i++)
	{
		std::getline(file, line);
		date = line.substr(0, line.find(','));
		value = line.substr(line.find(',') + 1);
		this->_data[i] = std::make_pair(date, std::stod(value));
	}
	file.close();
}

bool BitcoinExchange::checkInput(std::string input, std::string date, double value)
{
	int year;
	int month;
	int day;

	if(input.find(" | ") == std::string::npos)
	{
		std::cerr << "Error: bad input => " << input << std::endl;
		return (false);
	}
	if(date.length() != 10)
	{
		std::cerr << "Error: wrong date length." << std::endl;
		return (false);
	}
	if(value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	if(value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	year = std::stoi(date.substr(0, date.find('-')));
	month = std::stoi(date.substr(date.find('-') + 1, 2));
	day = std::stoi(date.substr(date.rfind('-') + 1));
	if(year < 2009 || year > 2024 || month < 1 || month > 12 || day < 1 || day > 31)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return (false);
	}
	return (true);
}

std::string removeDashes(const std::string& date)
{
	std::string result;

	for (char c : date)
	{
		if (c != '-')
			result += c;
	}
	return result;
}

void BitcoinExchange::exchange(std::string input)
{
	std::string date;
	double value;

	date = input.substr(0, input.find(' '));
	value = std::stod(input.substr(input.rfind(' ') + 1));
	if(checkInput(input, date, value))
	{
		std::pair<std::string, double> closest = {"", 0};
		int diff = stoi(removeDashes(date)) - stoi(removeDashes(this->_data[0].first));
		for(int i = 0; i < DATA_SIZE; i++)
		{
			int num_date = stoi(removeDashes(date));
			int num_data_date = stoi(removeDashes(this->_data[i].first));
			if(std::abs(num_data_date - num_date) < diff && num_data_date < num_date)
			{
				diff = std::abs(num_data_date - num_date);
				closest = this->_data[i];
			}
		}
		std::cout << date << " => " << value << " = " << closest.second * value << std::endl;
	}
}
