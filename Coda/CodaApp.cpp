#include "pch.h"

#include "CodaApp.h"
#include "CodaUtil.h"
#include "CodaWindow.h"
#include "Picture.h"
#include "Renderer.h"
#include "Event.h"
#include "Keys.h"

namespace Coda {
	void CodaApp::OnUpdate() {

	}

	void CodaApp::Run() {
		CODA_LOG("Coda running...");

		CodaWindow::Init();
		CodaWindow::GetWindow()->Create(600, 400, "TestWindow");

		
		Renderer::Init();

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		int x{200}, y{ 200 };
		CodaWindow::GetWindow()->SetKeyPressedCallback([&](const KeyPressedEvent& event) {
			if (event.GetKeyCode() == CODA_KEY_LEFT) x -= 10;
			else if (event.GetKeyCode() == CODA_KEY_RIGHT) x += 10; 
		});

		Picture pic{ "Assets/Textures/test.png" };

		while (true) {
			
			Renderer::Clear();

			OnUpdate();

			Renderer::Draw(pic, 100, 100, 1);
			
			std::this_thread::sleep_until(mNextFrameTime);

			CodaWindow::GetWindow()->SwapBuffers();
			
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}

	
	}
}

/*
	Coda::Picture pic1{"Assets/pic1.png"};
	Coda::Shader shade{"Assets/vertex.glsl", "Assets/fragment.glsl"};

	Coda::Renderer::Draw(pic1, shade, 110, 222, 10);
*/
