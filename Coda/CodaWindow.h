#pragma once

#include "pch.h"
#include "CodaUtil.h"
#include "WindowImplementation.h"
#include "Event.h"

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

		void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback);
		void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback);

	private:
		inline static CodaWindow* mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };

		int mWidth{ 0 };
		int mHeight{ 0 };
	};
}
