#pragma once

#include "RendererImplementation.h"

namespace Coda {
	class OpenGLRenderer : public RendererImplementation {
	public:
		OpenGLRenderer();
		virtual void Draw(Picture& picture, int x, int y, int z, Shader& shader) override;
		virtual void Clear() override;
	};
}