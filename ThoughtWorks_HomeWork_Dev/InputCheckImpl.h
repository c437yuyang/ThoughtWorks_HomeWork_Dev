#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include "InputCheck.h"
class InputCheckImpl :public InputCheck
{
public:
	void checkFormatAndExitIfNotValid(std::string& str) override
	{
		if (str == "")
			return;
		if (str.back() != ';')
			str += ';';
		std::string regexPattern = "([+-]?\\d+,[+-]?\\d+ [+-]?\\d+,[+-]?\\d+;){1,}";
		std::regex pattern(regexPattern);
		if (!std::regex_match(str, pattern))
		{
			std::cerr << "Incorrect command format." << std::endl;
			exit(EXIT_FAILURE);
		}
	}

	void checkInputAndExitIfNotValid(int row1, int col1, int row2, int col2, int m, int n) override
	{
		if (!checkNumValidConvert(row1, col1, row2, col2))
		{
			std::cerr << "Invalid number format." << std::endl;
			exit(EXIT_FAILURE);
		}
		if (!checkRange(row1, col1, row2, col2, m, n))
		{
			std::cerr << "Number out of range." << std::endl;
			exit(EXIT_FAILURE);
		}
		if (!checkConnectivity(row1, col1, row2, col2))
		{
			std::cerr << "Maze format error." << std::endl;
			exit(EXIT_FAILURE);
		}
	}
private:
	bool validNumberRangeWith0ToLim(int num, int lim)
	{
		return num >= 0 && num < lim;
	}

	bool checkRange(int row1, int col1, int row2, int col2, int m, int n)
	{
		if (!validNumberRangeWith0ToLim(row1, m) ||
			!validNumberRangeWith0ToLim(row2, m) ||
			!validNumberRangeWith0ToLim(col1, n) ||
			!validNumberRangeWith0ToLim(col2, n))
			return false;
		return true;
	}

	bool checkConnectivity(int row1, int col1, int row2, int col2)
	{
		if (row1 != row2 && col1 != col2)
			return false;
		else if (std::abs(col1 - col2) > 1)
			return false;
		else if (std::abs(row1 - row2) > 1)
			return false;
		return true;
	}

	bool checkNumValidConvert(int num)
	{
		return num != std::numeric_limits<int>::min() && std::numeric_limits<int>::max();
	}

	bool checkNumValidConvert(int row1, int col1, int row2, int col2)
	{
		return checkNumValidConvert(row1) &&
			checkNumValidConvert(col1) &&
			checkNumValidConvert(row2) &&
			checkNumValidConvert(col2);
	}
};

