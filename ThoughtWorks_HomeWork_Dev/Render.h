#pragma once
#include <string>
class Render
{
public:
	virtual std::string doRender(int m, int n, std::string& command,std::string&initPos) = 0;
};