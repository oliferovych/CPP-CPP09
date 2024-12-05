/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:59:56 by dolifero          #+#    #+#             */
/*   Updated: 2024/12/05 12:32:53 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if(ac == 2)
	{
		RPN rpn;
		if(rpn.checkInput(av[1]))
		{
			rpn.calculate(av[1]);
			return 0;
		}
	}
	else
		std::cerr << "Usage: ./ex01 \"[RPN expression]\"" << std::endl;
	return 1;
}
