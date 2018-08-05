#pragma once
#include <memory>
#include "OutputFormat.h"
#include "OutputFormatImpl.h"
class OutputFormatFactory
{
public:
	static std::unique_ptr<OutputFormat> getFormatter()
	{
		//return std::make_unique<OutputFormatImpl>(); //need C++14
		return std::unique_ptr<OutputFormatImpl>(new OutputFormatImpl);
	}
};