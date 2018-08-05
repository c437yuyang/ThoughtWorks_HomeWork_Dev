#pragma once
#include <string>
class InputCheck
{
public:
	virtual void checkFormatAndExitIfNotValid(std::string &str) = 0;

	virtual void checkInputAndExitIfNotValid(int row1, int col1, int row2, int col2, int m, int n) = 0;
};