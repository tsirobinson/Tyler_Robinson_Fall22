/*
- Included Coda.h
- Inherit a class from CodaApp and override OnUpdate
- Feed the name of your class into START_CODA_GAME macro
*/

#include "Coda.h"

class GEFall22 : public Coda::CodaApp
{
public:
	void OnUpdate() override {

	}
};

START_CODA_GAME(GEFall22)