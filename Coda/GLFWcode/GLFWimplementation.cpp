#include "../pch.h"

#include "GLFWimplementation.h"

namespace Coda {
	GLFWimplementation::GLFWimplementation() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	void GLFWimplementation::Create(int width, int height, const std::string& windowName) {
		mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
	}
	void GLFWimplementation::SwapBuffers() {
		glfwSwapBuffers(mWindow);
	}
	GLFWimplementation::~GLFWimplementation()
	{
		glfwTerminate();
	}
}