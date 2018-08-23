#pragma once
#include "Render.h"
#include "RenderImpl.h"
class RenderFactory
{
public:
	static auto getRender()
	{
		//return std::make_shared<RenderImpl>();//need C++14
		return std::shared_ptr<RenderImpl>(new RenderImpl);
	}
};