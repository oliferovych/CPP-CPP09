/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:00:25 by dolifero          #+#    #+#             */
/*   Updated: 2024/12/05 12:33:28 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>

class RPN
{
	private:
		std::vector<unsigned int> stack;
	public:
		RPN();
		RPN(RPN const & src);
		RPN & operator=(RPN const & src);
		~RPN();
		bool checkInput(std::string input);
		void calculate(std::string input);
};
