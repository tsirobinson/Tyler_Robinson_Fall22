#include "pch.h"

#include "CodaApp.h"
#include "CodaUtil.h"
#include "CodaWindow.h"
#include "glad/glad.h"
#include "Picture.h"
#include "Renderer.h"


namespace Coda {
	void CodaApp::OnUpdate() {

	}

	void CodaApp::Run() {
		CODA_LOG("Coda running...");

		CodaWindow::Init();
		CodaWindow::GetWindow()->Create(600, 400, "TestWindow");

		Picture pic{ "Assets/Textures/test.png" };
		Renderer::Init();

		while (true) {
			
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        	glClear(GL_COLOR_BUFFER_BIT);
			
			Renderer::Draw(pic, 100, 100, 1);
			
			CodaWindow::GetWindow()->SwapBuffers();
			OnUpdate();
		}

	
	}
}

/*
	Coda::Picture pic1{"Assets/pic1.png"};
	Coda::Shader shade{"Assets/vertex.glsl", "Assets/fragment.glsl"};

	Coda::Renderer::Draw(pic1, shade, 110, 222, 10);
*/
