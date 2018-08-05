#pragma once
#include <string>
#include <vector>
class OutputFormat
{
public:
	virtual std::string output(const std::vector<std::vector<int>>& mat) = 0;
};
