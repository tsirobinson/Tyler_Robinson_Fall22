#pragma once

#include "pch.h"
#include "CodaUtil.h"
#include "ShaderImplementation.h"

namespace Coda {
	class CODA_API Shader {
	public:
		Shader(const std::string& vertexFile, const std::string& fragmentShader);
		Shader(std::string&& vertexFile, std::string&& fragmentShader);
	private:
		ShaderImplementation* mImplementation;
	};
}