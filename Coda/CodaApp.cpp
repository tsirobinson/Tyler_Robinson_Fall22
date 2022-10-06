#include "pch.h"

#include "CodaApp.h"
#include "CodaUtil.h"

#include "GLFW/glfw3.h"

namespace Coda {
	void CodaApp::OnUpdate() {

	}

	void CodaApp::Run() {
		CODA_LOG("Coda running...");

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		//make into singleton and keep glfw code away from user
		GLFWwindow* win{ glfwCreateWindow(600, 400, "Test Window", NULL, NULL)};
		glfwMakeContextCurrent(win);

		while (true) {
			
			glfwSwapBuffers(win);
			glfwPollEvents();

			OnUpdate();
		}

		glfwTerminate();
	}
}