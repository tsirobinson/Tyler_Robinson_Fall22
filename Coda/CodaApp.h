#pragma once

#include "pch.h"
#include "CodaUtil.h"

constexpr int FRAMES_PER_SECOND = 60;

namespace Coda 
{
	class CODA_API CodaApp
	{
	public:
		CodaApp();
		virtual void OnUpdate();
		virtual bool CheckGameOver() = 0;;
		void Run();

	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / FRAMES_PER_SECOND };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}
