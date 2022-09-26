#include "CodaApp.h"
#include <iostream>

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