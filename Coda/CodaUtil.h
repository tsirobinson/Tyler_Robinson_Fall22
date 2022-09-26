#pragma once


#define START_CODA_GAME(GameClass) \
	int main()\
	{\
		GameClass __coda__game;\
		__coda__game.Run();\
		return 0;\
	}

#ifdef CODA_WINDOWS
	#ifdef CODA_LIB
		#define CODA_API __declspec(dllexport)
	#else
		#define CODA_API __declspec(dllimport)
	#endif
#else
	#define CODA_API
#endif

#ifdef CODA_DEBUG
	#define CODA_LOG(x)  std::cout <<x<<std::endl;
#else
	#define CODA_LOG(X)
#endif