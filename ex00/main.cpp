/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:39:49 by dolifero          #+#    #+#             */
/*   Updated: 2024/12/03 17:30:33 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if(ac == 2)
	{
		BitcoinExchange exchange;
		std::ifstream file(av[1]);
		if(!file.is_open())
		{
			std::cerr << "Error: Couldn't open file" << std::endl;
			return 1;
		}
		exchange.loadData();
		std::string line;
		std::getline(file, line);
		while(std::getline(file, line))
			exchange.exchange(line);
		return(0);
	}
	std::cerr << "Error: Wrong number of arguments" << std::endl;
	return 1;
}
