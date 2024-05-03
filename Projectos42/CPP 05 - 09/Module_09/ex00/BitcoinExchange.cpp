/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:35:16 by mikferna          #+#    #+#             */
/*   Updated: 2024/04/16 15:32:54 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	cvs_parser("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::cvs_parser(const std::string &database1)
{
    std::ifstream input(database1.c_str());
    if (!input.is_open())
    {
        std::cout << "No se puede abrir el archivo" << std::endl;
        return ;
    }
    std::string line;
    while (std::getline(input, line))
    {
        size_t pos = line.find(",");
        if (pos == line.npos)
        {
            std::cout << "Formato incorrecto de data.csv" << std::endl;
            return ;
        }
        std::string date = line.substr(0, line.find(","));
        std::string rate = line.substr(line.find(",") + 1);
		this->_data[date] = std::atof(rate.c_str());
    }
    input.close();
}

bool isLeapYear(int year)
{
	if (year % 4 != 0)
		return false;
	else if (year % 100 != 0)
		return true;
	else if (year % 400 != 0)
		return false;
	else
		return true;
}

int BitcoinExchange::isValidDateFormat(const std::string &date)
{
	if (date.size() != 10 && date.size() != 11)
		return 0;
	if (date[4] != '-' || date[7] != '-')
		return 0;
	int year = stoi(date.substr(0, 4));
	int month = stoi(date.substr(5, 2));
	int day = stoi(date.substr(8, 2));
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return 0;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return 0;
	if (month == 2) {
		if (isLeapYear(year)) {
			if (day > 29)
				return 0;
		} else {
			if (day > 28)
				return 0;
		}
	}
	size_t saguton = date.size();
	if (date[date.size() - 1] == ' ')
		saguton--;
	for (size_t i = 0; i < saguton; i++) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return 0;
	}
	return 1;
}

int BitcoinExchange::isValidValueFormat(const std::string &value)
{
	if (value.size() == 0)
		return 0;
	for (size_t i = 0; i < value.size(); i++) {
		if (i == 0 && value[0] == ' ')
			i++;
		if ((i == 0 || i == 1) && value[i] == '-')
			continue;
		if (!isdigit(value[i]) && value[i] != '.')
			return 0;
		}
	float val = stof(value);
	if (val < 0 || val > 1000)
		return 0;
	return 1;
}

void BitcoinExchange::processLine(std::string date, std::string value)
{
	std::map<std::string, float>::iterator it = _data.lower_bound(date);
	if (it == _data.begin() && date < it->first)
	{
		std::cout << "No se encontró una fecha igual o anterior a " << date << std::endl;
		return;
	}
	if (it->first > date && it != _data.begin())
		it--;
	float enteringRate = it->second;
	float floatValue = std::stof(value);
	float result = enteringRate * floatValue;
	std::cout << date << "=>" << value << " = " << result << std::endl;
}

void BitcoinExchange::read_file(std::string filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
		throw std::runtime_error("File not found");
	std::string line;
	std::string date;
	std::string value;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		if (!std::getline(ss, date, '|') || !std::getline(ss, value))
		{
			std::cout << "Invalid line format : " << line << std::endl;
			continue;
		}
		try
		{
			if (!isValidDateFormat(date))
				throw std::runtime_error("Invalid date format");
			if (!isValidValueFormat(value))
				throw std::runtime_error("Invalid value format");
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			continue;
		}
		processLine(date, value);
	}
	file.close();
}
