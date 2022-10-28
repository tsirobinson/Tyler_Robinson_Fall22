#include "pch.h"

#include "CodaApp.h"
#include "CodaUtil.h"
#include "CodaWindow.h"


namespace Coda {
	void CodaApp::OnUpdate() {

	}

	void CodaApp::Run() {
		CODA_LOG("Coda running...");

		CodaWindow::Init();
		CodaWindow::GetWindow()->Create(600, 400, "TestWindow");
		//CodaWindow gameWindow;
		//gameWindow.Create(600, 400, "Test window");

		while (true) {
			CodaWindow::GetWindow()->SwapBuffers();
			//gameWindow.SwapBuffers();

			OnUpdate();
		}

	
	}
}