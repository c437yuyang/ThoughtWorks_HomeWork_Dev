#pragma once
#include "Render.h"
#include "RenderImpl.h"
class RenderFactory
{
public:
	static std::unique_ptr<Render> getRender()
	{
		//return std::make_unique<RenderImpl>();//need C++14
		return std::unique_ptr<RenderImpl>(new RenderImpl);
	}
};