#pragma once
#include <memory>
#include "InputCheck.h"
#include "InputCheckImpl.h"
class InputCheckFactory
{
public:
	static auto getInputChecker()
	{
		//return std::make_shared<InputCheckImpl>();//need C++14
		return std::shared_ptr<InputCheckImpl>(new InputCheckImpl);
	}
};