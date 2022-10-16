#pragma once

#include "GLFW/glfw3.h"
#include "../WindowImplementation.h"

namespace Coda {
	class GLFWimplementation : public WindowImplementation {
	public:
		GLFWimplementation();
		virtual void Create(int width, int height, const std::string& windowName) override;
		virtual void SwapBuffers() override;

		~GLFWimplementation();
	private:
		GLFWwindow* mWindow{ nullptr };
	};
}