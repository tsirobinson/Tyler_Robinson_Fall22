#include "pch.h"
#include "Shader.h"

namespace Coda{
	void Shader::Activate() {
		mImplementation->Activate();
	}

	void Shader::ProvideFloatValues(const std::string& valueName, const std::vector<float>& vals) {
		mImplementation->ProvideFloatValues(valueName, vals);
	}

	void Shader::ProvideFloatValues(std::string&& valueName, const std::vector<float>& vals) {
		mImplementation->ProvideFloatValues(valueName, vals);
	}
}