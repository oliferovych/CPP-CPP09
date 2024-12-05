/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:02:17 by dolifero          #+#    #+#             */
/*   Updated: 2024/12/05 12:35:54 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(RPN const & src)
{
	if(this != &src)
	{
		if(src.stack.size())
		{
			for(unsigned int i = 0; i < src.stack.size(); i++)
				stack.push_back(src.stack[i]);
		}
		*this = src;
	}
}

RPN & RPN::operator=(RPN const & src)
{
	if(this != &src)
	{
		if(src.stack.size())
		{
			for(unsigned int i = 0; i < src.stack.size(); i++)
				stack.push_back(src.stack[i]);
		}
	}
	return *this;
}

RPN::~RPN()
{
	if(stack.size())
		stack.clear();
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

std::vector<std::string> split(const std::string& str, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(str);

	while (std::getline(tokenStream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

void RPN::calculate(std::string input)
{
	std::vector<std::string> tokens;
	unsigned int tmp;

	tokens = split(input, ' ');
	while(tokens.size())
	{
		if(tokens[0].length() != 1)
			return err("Error: bad input.");
		if(std::isdigit(tokens[0][0]))
			tmp = std::stoi(tokens[0]);
		if(tokens[0][0] == '+')
		{
			if(stack.size() < 2)
				return err("Error: not enough operands.");
			tmp = stack[stack.size() - 2] + stack[stack.size() - 1];
			stack.pop_back();
			stack.pop_back();
		}
		if(tokens[0][0] == '-')
		{
			if(stack.size() < 2)
				return err("Error: not enough operands.");
			tmp = stack[stack.size() - 2] - stack[stack.size() - 1];
			stack.pop_back();
			stack.pop_back();
		}
		if(tokens[0][0] == '*')
		{
			if(stack.size() < 2)
				return err("Error: not enough operands.");
			tmp = stack[stack.size() - 2] * stack[stack.size() - 1];
			stack.pop_back();
			stack.pop_back();
		}
		if(tokens[0][0] == '/')
		{
			if(stack.size() < 2)
				return err("Error: not enough operands.");
			if(stack[stack.size() - 1] == 0)
				return err("Error: division by zero.");
			tmp = stack[stack.size() - 2] / stack[stack.size() - 1];
			stack.pop_back();
			stack.pop_back();
		}
		stack.push_back(tmp);
		tokens.erase(tokens.begin());
	}
	std::cout << stack[0] << std::endl;
}
