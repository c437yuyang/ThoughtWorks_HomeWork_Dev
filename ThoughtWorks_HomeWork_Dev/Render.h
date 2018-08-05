#pragma once
#include <string>
class Render
{
public:
	virtual std::string doRender(int m, int n, const std::string& command) = 0;
};