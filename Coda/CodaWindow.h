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
		static CodaWindow* GetWindow();

		virtual void Create(int width, int height, const std::string& windowName);
		virtual void SwapBuffers();

		int GetWidth() const;
		int GetHeight() const;

	private:
		inline static CodaWindow* mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };

		int mWidth{ 0 };
		int mHeight{ 0 };
	};
}
