#pragma once

#include "pch.h"

namespace Coda {
	class PictureImplementation {
	public:
		virtual int GetHeight() const = 0;
		virtual int GetWidth() const = 0;

		virtual void Activate() = 0;

		virtual ~PictureImplementation() {};

	};
}