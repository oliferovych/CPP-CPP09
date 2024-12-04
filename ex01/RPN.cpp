/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:02:17 by dolifero          #+#    #+#             */
/*   Updated: 2024/12/04 14:07:39 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool RPN::checkInput(std::string input)
{
	for(int i = 0; input[i]; i++)
	{
		if(!std::isdigit(input[i]) && input[i] != ' ' && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/')
			return false;
	}
	return true;
}
