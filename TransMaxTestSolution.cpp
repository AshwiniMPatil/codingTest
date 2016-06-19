// TransMaxTestSolution.cpp : Defines the exported functions for the DLL application.
//

#include "TransMaxTestSolution.h"


// This is an example of an exported variable
TRANSMAXTESTSOLUTION_API int nTransMaxTestSolution=0;

// This is an example of an exported function.
TRANSMAXTESTSOLUTION_API int fnTransMaxTestSolution(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see TransMaxTestSolution.h for the class definition
CTransMaxTestSolution::CTransMaxTestSolution()
{
	return;
}


void CTransMaxTestSolution::parseLineData(const string &test, std::vector<std::pair<int, string> > &myPair)
{
	//As firstname,lastname,marks. So parsing name and marks.
	int position = test.find_last_of(",");
	int mark = 0;
	if(position > 0)
	{
		string marks = test.substr(position + 1);
		stringstream convertStream;
		convertStream.str("");
		convertStream.str(marks);
		convertStream >> mark;
		
		string name = test.substr(0, position);
		myPair.push_back(std::make_pair(100 - mark, name));
	}
}

int CTransMaxTestSolution::readInputFile(const string &fileName, std::vector<std::pair<int, string> > &items)
{
	ifstream InputFile;
	string fileLineRead;
	int result = 0;
	InputFile.open(fileName.c_str());
	if(!InputFile.is_open())
	{
		cout<< "input file is not present";
		return 1;
	}
	//Reading data from input file line by line
	while (!InputFile.eof()) 
	{
	    getline(InputFile,fileLineRead);
		if(fileLineRead.length() > 0)
			parseLineData(fileLineRead, items);
    }
	InputFile.close();

	if(items.size() > 0)
	{
		return 0;
	}else
	{
		return 1;
	}
}

int CTransMaxTestSolution::writeOutputFile(const string &outputFileName, std::vector<std::pair<int, string> > &items)
{
	ofstream outputFile;
	outputFile.open(outputFileName.c_str());
	if(!outputFile.is_open())
	{
		cout<< "output file is not getting created";
		return 1;
	}
	
	for(unsigned int index = 0; index < items.size(); index++)
	{
		 ostringstream ss;
		 ss << (100 - items[index].first);
		 string outputFormat = items[index].second + " , " + ss.str() + "\n\n";
		 cout << outputFormat;
		 outputFile.write (outputFormat.c_str(),outputFormat.size());
	}
	cout << "Finished: created " << outputFileName;
	outputFile.close();
	return 0;
}
