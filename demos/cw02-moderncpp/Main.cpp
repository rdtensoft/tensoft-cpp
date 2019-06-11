#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream>
#include "BasicDemos.h"
#include "ParallelDemos.h"

void runBasicsDemos() {
	std::cout << "[demo] C++11 Smart Pointers \n";
	demoSmartPointers();
	std::cout << "[demo] C++11 Move Constructor \n";
	demoMoveConstructor ();
	std::cout << "[demo] C++17 auto type declaration... \n";
	demoCPP17auto();
}

void runParallelDemos() {
	std::cout << "[demo] Use std::mutex and locking priority... \n";
	demoLowAndHighPriorityLocksWithMutex();
	std::cout << "[demo] HTTP get (std::mutex & std::thread) ... \n";
	demoParallerHttpGet();
	std::cout << "[demo] atomics ... \n";
	demoAtomics();
}


int _tmain(int argc, _TCHAR* argv[])
{
	runBasicsDemos();
	// runParallelDemos();
	std::cin.ignore();
	return 0;
}
