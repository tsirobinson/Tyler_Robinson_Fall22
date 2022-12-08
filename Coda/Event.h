#pragma once

#include "CodaUtil.h"

namespace Coda {
	class CODA_API KeyPressedEvent {
	public:
		KeyPressedEvent(int codeOfKey);
		KeyPressedEvent() = delete;

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	class CODA_API KeyReleasedEvent {
	public:
		KeyReleasedEvent(int codeOfKey);
		KeyReleasedEvent() = delete;

		int GetKeyCode() const;
	
	private:
		int mKeyCode;
	};
}