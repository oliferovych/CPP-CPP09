/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:00:25 by dolifero          #+#    #+#             */
/*   Updated: 2024/12/06 21:07:53 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <stack>
#include <queue>

class RPN
{
	private:
		std::stack<double> stack;
	public:
		RPN();
		RPN(RPN const & src);
		RPN & operator=(RPN const & src);
		~RPN();
		bool checkInput(std::string input);
		void calculate(std::string input);
};
