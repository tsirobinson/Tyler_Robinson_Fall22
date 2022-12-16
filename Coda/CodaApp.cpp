#include "pch.h"

#include "CodaApp.h"
#include "CodaUtil.h"
#include "CodaWindow.h"
#include "Picture.h"
#include "Renderer.h"
#include "Event.h"
#include "Keys.h"
#include "Unit.h"

namespace Coda {
	CodaApp::CodaApp() {
		CodaWindow::Init();
		CodaWindow::GetWindow()->Create(1000, 800, "CODA");

		Renderer::Init();
	}

	void CodaApp::OnUpdate() {

	}

	void CodaApp::Run() {
		CODA_LOG("Coda running...");

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true) {
			
			Renderer::Clear();

			OnUpdate();
			
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
