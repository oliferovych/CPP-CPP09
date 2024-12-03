/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:40:27 by dolifero          #+#    #+#             */
/*   Updated: 2024/12/03 22:38:20 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <fstream>

#define DATA_SIZE 1612

class BitcoinExchange
{
	private:
		std::pair<std::string, double> _data[DATA_SIZE];
	public:
	//Constructors
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & src);
		BitcoinExchange & operator=(BitcoinExchange const & src);
	//Methods
		void loadData();
		bool checkInput(std::string input, std::string date, double value);
		void exchange(std::string input);
};
