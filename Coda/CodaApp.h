#pragma once
#include "CodaUtil.h"
namespace Coda 
{
	class CODA_API CodaApp
	{
	public:
		virtual void OnUpdate();
		void Run();
	};
}
