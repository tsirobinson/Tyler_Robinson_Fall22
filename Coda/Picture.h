#pragma once

#include "pch.h"
#include "CodaUtil.h"
#include "PictureImplementation.h"

namespace Coda {
	class CODA_API Picture {
	public:
		Picture(const std::string& sourceFile);
		Picture(std::string&& sourceFile);

		int GetHeight() const;
		int GetWidth() const;

		void Activate();

	private:
		PictureImplementation* mImplementation{ nullptr };
	};
}