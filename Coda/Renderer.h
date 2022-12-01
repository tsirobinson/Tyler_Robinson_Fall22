#pragma once

#include "CodaUtil.h"
#include "Shader.h"
#include "Picture.h"
#include "RendererImplementation.h"

namespace Coda {
	class CODA_API Renderer {
	public:
		static void Init();
		static Renderer* GetRenderer();

		static void Draw(Picture& picture, int x, int y, int z, Shader& shader = mDefaultShader);

	private:
		inline static Renderer* mInstance{ nullptr };

		RendererImplementation* mImplementation;

		Renderer();

		inline static Shader mDefaultShader{ "Assets/Shaders/defaultCodaVertex.glsl", 
			"Assets/Shaders/defaultCodaFragment.glsl" };
	};
}