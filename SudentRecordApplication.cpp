// SudentRecordApplication.cpp : Defines the entry point for the console application.
//

#include "TransMaxTestSolution.h"

int main(int argc, char* argv[])
{
	CTransMaxTestSolution obj;
	std::vector<std::pair<int, string> > items;
    int res = obj.readInputFile(argv[1], items);

	//Creating output file name.
	string fileName = argv[1];
	int pos = fileName.find_last_of(".");
	fileName = fileName.substr(0,pos);
	string outputFileName = fileName + "-graded.txt";
	
	if(0 == res)
	{
		std::sort(items.begin(), items.end());
		res = obj.writeOutputFile(outputFileName, items);
		if(0 != res)
			return 1;
	}
	return 0;
}

