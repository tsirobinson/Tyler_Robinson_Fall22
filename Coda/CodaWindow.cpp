#include "pch.h"

#include "CodaWindow.h"
#include "GLFWcode/GLFWimplementation.h"

namespace Coda {
	void CodaWindow::Init() {
		if (mInstance == nullptr) {
			mInstance = new CodaWindow;

#ifdef CODA_WINDOWS
			mInstance->mImplementation = new GLFWimplementation;
#elif defined CODA_MAC
			mInstance->mImplementation = new GLFWimplementation;
#else 
			mInstance->mImplementation = new GLFWimplementation;
#endif

		}
	}

	CodaWindow* CodaWindow::GetWindow() {
		return mInstance;
	}

	void CodaWindow::Create(int width, int height, const std::string& windowName) {
		mImplementation->Create(width, height, windowName);

		mWidth = width;
		mHeight = height;
	}

	void CodaWindow::SwapBuffers() {
		mImplementation->SwapBuffers();
	}

	int CodaWindow::GetWidth() const {
		return mWidth;
	}

	int CodaWindow::GetHeight() const {
		return mHeight;
	}

	void CodaWindow::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback) {
		mImplementation->SetKeyPressedCallback(keyPressedCallback);
	}

	void CodaWindow::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback) {
		mImplementation->SetKeyReleasedCallback(keyReleasedCallback);
	}

	void CodaWindow::CloseWindow()
	{
		mInstance->mImplementation->~WindowImplementation();

		if (mInstance != nullptr) {
			delete mInstance;
		}
	}
}