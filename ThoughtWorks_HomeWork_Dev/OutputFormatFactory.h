#pragma once
#include <memory>
#include "OutputFormat.h"
#include "OutputFormatImpl.h"
class OutputFormatFactory
{
public:
	static auto getFormatter()
	{
		//return std::make_shared<OutputFormatImpl>(); //need C++14
		return std::shared_ptr<OutputFormatImpl>(new OutputFormatImpl);
	}
};