/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:45:57 by clundber          #+#    #+#             */
/*   Updated: 2024/11/04 10:41:29 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "ScalarConverter.hpp"



int	inputType(std::string& input);
void printType(std::string input, int _type);
template <typename T>
void printOutput(const T& output, int _type);
void printSpecial(std::string input);

//constructors and destructor
ScalarConverter::ScalarConverter(){};

ScalarConverter::ScalarConverter(ScalarConverter&){};

ScalarConverter::~ScalarConverter(){};
	
//overloads
ScalarConverter& ScalarConverter::operator=(ScalarConverter& other){
	if (this != &other)
		;
	return(*this);
}

//methods
void ScalarConverter::convert(std::string input)
{
	if (input.empty())
		throw std::invalid_argument("incorrect argument");
	int _type = inputType(input);
	if (_type == _wrong)
	{
		if (input.compare("-inff") == 0 || input.compare("+inff") == 0 || input.compare("nanf") == 0 || \
		input.compare("-inf") == 0 || input.compare("+inf") == 0 || input.compare("nan") == 0)
			printSpecial(input);
		else
			throw std::invalid_argument("incorrect argument");
	}
	else if (_type == _char)
	{
		char output = input.c_str()[0];
		printOutput(output, _type);
	}
	else if (_type == _int)
	{
		if (input.length() < 12)
		{
			long temp = stol(input);
			if (temp > INT_MAX || temp < INT_MIN)
				throw std::invalid_argument("incorrect argument");
			else
			{
			int output = stoi(input);
			printOutput(output, _type);
			}
		}
		else
			throw std::invalid_argument("incorrect argument");
	}
	else if (_type ==_float)
	{
		double temp = stod(input);
		if (temp > __FLT_MAX__ || temp < __FLT_MIN__)
			throw std::invalid_argument("incorrect argument");
		else
		{
			float output = stof(input);
			printOutput(output, _type);
		}
	}
	else if (_type == _double)
	{
		long double temp = stold(input);
		if (temp > __DBL_MAX__ || temp < __DBL_MIN__)
			throw std::invalid_argument("incorrect argument");
		else
		{
			double output = stod(input);
			printOutput(output, _type);
		}
	}
}

void printSpecial(std::string input)
{
	std::cout << "char: impossible\n" << "int: impossible\n";
	if (input.front() == '+')
		std::cout << "float: +inff\n" << "double: +inf\n";
	else if (input.front() == '-')
		std::cout << "float: -inff\n" << "double: -inf\n";
	else
		std::cout << "float: nanf\n" << "double: nan\n";
}

template <typename T>
void printOutput(const T& output, int _type)
{
	//char
	if (output < 32)
		std::cout << "char: Non displayable\n";
	else if (output > 127)
	 	std::cout << "char: impossible\n";
	else
		std::cout << "char: " << static_cast<char>(output) << "\n";
	
	//int
	if (_type == _double && (static_cast<long>(output) > INT_MAX || output < INT_MIN))
		std::cout << "int: impossible\n";
	else
	 	std::cout << "int: " << static_cast<int>(output) << "\n";
	
	//float
	std::cout << std::fixed << std::setprecision(1);
	if (_type == _double && (output > __FLT_MAX__ || output < __FLT_MIN__))
		std::cout << "float: impossible\n";
	else
		std::cout << "float: " << static_cast<float>(output) << "f\n";
	
	//double
	std::cout << "double: " << static_cast<double>(output) << "\n";
}

void printType(std::string input, int _type)
{
	std::string types[5]{"int", "float", "double", "char", "wrong"};
	std::cout << input << " = " << types[_type] << std::endl;
}

int	inputType(std::string& input)
{
	bool _dot, _alpha = false;
	int _type;
	
	if (input.length() == 1 || (input.length() == 3 && input.front() == '\'' && input.back() == '\''))
	{
		if (isdigit(input.at(0)))		
			_type = _int;
		else
		{
			_type = _char;
			if (input.length() == 3)
				input = input.at(1);
		}
	}
	else if (input.back() == 'f')
	{
		for (unsigned long i = 0; i < input.length() -1; i++)
		{
			if (i == 0 && (input.front() == '-' || input.front() == '+'))
				i++;
			if (input.at(i) == '.')
			{
				if (_dot == false)	
					_dot = true;
				else
					_alpha = true;
			}
			else if (!isdigit(input.at(i)))
				_alpha = true;
		}
		if (_alpha == false && _dot == true && (input.front() != '.' && input.at(input.length() -2) != '.'))
			_type = _float;
		else
			_type = _wrong;
	}
	else
	{
		for (unsigned long i = 0; i < input.length(); i++)
		{
			if (i == 0 && (input.front() == '-' || input.front() == '+'))
				i++;
			if (input.at(i) == '.')
			{
				if (_dot == false)	
					_dot = true;
				else
					_alpha = true;
			}
			else if (!isdigit(input.at(i)))
				_alpha = true;
		}
		if (_alpha == true)
			_type = _wrong;
		else if (_dot == true)
		{
			if (input.front() == '.' || input.back() == '.')
				_type = _wrong;
			else
				_type = _double;
		}
		else
			_type = _int;
	}
	return (_type);
}
