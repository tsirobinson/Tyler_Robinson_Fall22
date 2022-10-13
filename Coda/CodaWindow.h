#pragma once

#include "pch.h"
#include "CodaUtil.h"

namespace Coda
{
	class CODA_API CodaWindow
	{
	public:
		void Init();
		CodaWindow* GetWindow();
		
		void Create(int width, int height, const std::string& windowName);
		void SwapBuffers();
	private:
		CodaWindow();
		inline static CodaWindow* instance{ nullptr };
	};
}
