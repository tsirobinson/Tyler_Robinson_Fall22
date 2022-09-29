#include "CodaApp.h"
#include "pch.h"

namespace Coda {
	void CodaApp::OnUpdate() {

	}

	void CodaApp::Run() {
		CODA_LOG("Coda running...");
		while (true) {
			
			OnUpdate();
		}
	}
}