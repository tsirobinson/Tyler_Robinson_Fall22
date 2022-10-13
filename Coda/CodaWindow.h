#pragma once

#include "pch.h"
#include "CodaUtil.h"
#include "WindowImplementation.h"

namespace Coda
{
	class CODA_API CodaWindow
	{
	public:
		static void Init();
		CodaWindow* GetWindow();
		
		void Create(int width, int height, const std::string& windowName);
		void SwapBuffers();
	private:
		CodaWindow();
		inline static CodaWindow* mInstance{ nullptr };
		WindowImplementation* mImplementation{ nullptr };
	};
}
