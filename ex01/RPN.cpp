/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:02:17 by dolifero          #+#    #+#             */
/*   Updated: 2024/12/06 21:10:04 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(RPN const & src) : stack(src.stack)
{
	if(this != &src)
	{
		*this = src;
	}
}

RPN & RPN::operator=(RPN const & src)
{
	if(this != &src)
		stack = src.stack;
	return *this;
}

RPN::~RPN()
{
}

bool RPN::checkInput(std::string input)
{
	for(int i = 0; input[i]; i++)
	{
		if(!std::isdigit(input[i]) && input[i] != ' ' && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/')
		{
			std::cerr << "Error: bad input." << std::endl;
			return false;
		}
	}
	return true;
}

void err(std::string msg)
{
	std::cerr << msg << std::endl;
}

std::queue<std::string> split(const std::string& str, char delimiter)
{
	std::queue<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(str);

	while (std::getline(tokenStream, token, delimiter))
		tokens.push(token);
	return tokens;
}

void RPN::calculate(std::string input)
{
	std::queue<std::string> tokens;
	double tmp;

	tokens = split(input, ' ');
	while(tokens.size())
	{
		std::string token = tokens.front();
		tokens.pop();
		if(token.length() != 1)
			return err("Error: bad input.");
		if(std::isdigit(token[0]))
			tmp = std::stoi(token);
		else
		{
			if(stack.size() < 2)
				return err("Error: not enough operands.");
			double b = stack.top(); stack.pop();
			double a = stack.top(); stack.pop();
			if(token[0] == '+')
				tmp = a + b;
			else if(token[0] == '-')
				tmp = a - b;
			else if(token[0] == '*')
				tmp = a * b;
			else if(token[0] == '/')
			{
				if(b == 0)
					return err("Error: division by zero.");
				tmp = a / b;
			}
		}
		stack.push(tmp);
	}
	if(stack.size() != 1)
		return err("Error: too many operands.");
	std::cout << stack.top() << std::endl;
}
