#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>

int _tmain(int argc, _TCHAR* argv[]) 
{
	const int iNumNumbers = 100000;
	const int iNumMathOps = 500;
	// ------
	std::vector<double> vInput;
	for (int i = 0; i < iNumNumbers; i++) {
		vInput.push_back(std::rand());
	}
	std::vector<double> vOutput(iNumNumbers);
	// ------
	const clock_t timeStart1 = std::clock();
	for (int j = 0; j < iNumMathOps; j++) {
		for (int i = 0; i < iNumNumbers; i++) {
			vOutput[i] = std::sqrt(vInput[i]); // sin, sqrt
		}
	}
	const clock_t timeMath = std::clock() - timeStart1;
	// ------
	std::cout << "Math:           " << timeMath << "ms" << std::endl;

	return 0;
}
