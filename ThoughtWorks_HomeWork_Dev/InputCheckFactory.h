#pragma once
#include <memory>
#include "InputCheck.h"
#include "InputCheckImpl.h"
class InputCheckFactory
{
public:
	static std::unique_ptr<InputCheck> getInputChecker()
	{
		//return std::make_unique<InputCheckImpl>();//need C++14
		return std::unique_ptr<InputCheckImpl>(new InputCheckImpl);
	}
};