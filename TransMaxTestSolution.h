// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the TRANSMAXTESTSOLUTION_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// TRANSMAXTESTSOLUTION_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TRANSMAXTESTSOLUTION_EXPORTS
#define TRANSMAXTESTSOLUTION_API __declspec(dllexport)
#else
#define TRANSMAXTESTSOLUTION_API __declspec(dllimport)
#endif


#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std; 

//int const MAX_MARKS = 100;

// This class is exported from the TransMaxTestSolution.dll
class TRANSMAXTESTSOLUTION_API CTransMaxTestSolution {
public:
	CTransMaxTestSolution(void);

void parseLineData(const string &test, std::vector<std::pair<int, string> > &myPair);

	int readInputFile(const string &fileName, std::vector<std::pair<int, string> > &items);

	int writeOutputFile(const string &outputFileName, std::vector<std::pair<int, string> > &items);
};

extern TRANSMAXTESTSOLUTION_API int nTransMaxTestSolution;

TRANSMAXTESTSOLUTION_API int fnTransMaxTestSolution(void);

