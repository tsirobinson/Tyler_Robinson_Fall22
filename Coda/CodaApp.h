#pragma once

#include "pch.h"
#include "CodaUtil.h"

constexpr int FRAMES_PER_SECOND = 60;

namespace Coda 
{
	class CODA_API CodaApp
	{
	public:
		virtual void OnUpdate();
		void Run();

	private:
		std::chrono::milliseconds mFrameDuration{ std::chrono::seconds{1} / FRAMES_PER_SECOND };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}
