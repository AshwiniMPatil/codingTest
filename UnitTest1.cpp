
#include "TransMaxTestSolution.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace UnitTest_application
{
	[TestClass]
	public ref class UnitTest1
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Use ClassCleanup to run code after all tests in a class have run
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

		[TestMethod]
		void parseLineData_Success()
		{
			CTransMaxTestSolution obj;
	
			std::vector<std::pair<int, string> > myPair;
			std::string test = "a,b,2";
			int expectedMark = 98; //because inseting 100-marks
		
			obj.parseLineData(test, myPair);
	
			int ActualMarks = 0;
	    	        std::vector<std::pair<int, string> > ::iterator iter = myPair.begin();
	    	        if(iter != myPair.end())
	    	        {
				ActualMarks = iter->first;
	    	        }
			Assert::AreEqual(expectedMark , ActualMarks);
		};
		
		[TestMethod]
		void parseLineData_FailData()
		{
			CTransMaxTestSolution obj;
	
			std::vector<std::pair<int, string> > myPair;
			std::string test = "ab2";
			int expectedMark = 0; 
		
			obj.parseLineData(test, myPair);
	
			int ActualMarks = 0;
	    	        std::vector<std::pair<int, string> > ::iterator iter = myPair.begin();
	    	        if(iter != myPair.end())
	    	        {
				ActualMarks = iter->first;
	    	        }
			Assert::AreEqual(expectedMark , ActualMarks);
		};
		
		[TestMethod]
		void parseLineData_FailNoData()
		{
			CTransMaxTestSolution obj;
	
			std::vector<std::pair<int, string> > myPair;
			std::string test = "";
			int expectedMark = 0; 
		
			obj.parseLineData(test, myPair);
	
			int ActualMarks = 0;
	    	        std::vector<std::pair<int, string> > ::iterator iter = myPair.begin();
	    	        if(iter != myPair.end())
	    	        {
				ActualMarks = iter->first;
	    	        }
			Assert::AreEqual(expectedMark , ActualMarks);
		};
		
		[TestMethod]
		void parseLineData_FailNoCommaData()
		{
			CTransMaxTestSolution obj;
	
			std::vector<std::pair<int, string> > myPair;
			std::string test = "ab2";
			int expectedMark = 0; 
		
			obj.parseLineData(test, myPair);
	
			int ActualMarks = 0;
	    	        std::vector<std::pair<int, string> > ::iterator iter = myPair.begin();
	    	        if(iter != myPair.end())
	    	        {
				ActualMarks = iter->first;
	    	        }
			Assert::AreEqual(expectedMark , ActualMarks);
		};
		
		[TestMethod]
		void parseLineData_FailNoNumberData()
		{
			CTransMaxTestSolution obj;
	
			std::vector<std::pair<int, string> > myPair;
			std::string test = "a,b";
			int expectedMark =100; 
		
			obj.parseLineData(test, myPair);
	
			int ActualMarks = 0;
	    	        std::vector<std::pair<int, string> > ::iterator iter = myPair.begin();
	    	        if(iter != myPair.end())
	    	        {
				ActualMarks = iter->first;
	    	        }
			Assert::AreEqual(expectedMark , ActualMarks);
		};
		
		//Test Cases of readInputFile
		[TestMethod]
		void readInputFile_noFilePresent()
		{
			CTransMaxTestSolution obj;
			int  expectedRes = 1;
			std::vector<std::pair<int, string> > myPair;
			std::string fileName = "c:\\projects\\codingtest\\NoFile.txt";
			
			int actualRes  = obj.readInputFile(fileName, myPair);
			
			Assert::AreEqual(expectedRes , actualRes);
		};
		
		[TestMethod]
		void readInputFile_FilePresent_noData()
		{
			CTransMaxTestSolution obj;
			int  expectedRes = 1;
			std::vector<std::pair<int, string> > myPair;
			std::string fileName = "c:\\projects\\codingtest\\emptyFile.txt";
			
			int actualRes  = obj.readInputFile(fileName, myPair);
			
			Assert::AreEqual(expectedRes , actualRes);
		};
		
		[TestMethod]
		void readInputFile_FilePresent_withData()
		{
			CTransMaxTestSolution obj;
			int  expectedRes = 0;
			std::vector<std::pair<int, string> > myPair;
			std::string fileName = "c:\\projects\\codingtest\\File_1.txt";
			
			int actualRes  = obj.readInputFile(fileName, myPair);
			
			Assert::AreEqual(expectedRes , actualRes);
		};
		
		//Test cases for writeOutputFile
		
		[TestMethod]
		void writeOutputFile_wrongPath()
		{
			CTransMaxTestSolution obj;
			int  expectedRes = 1;
			std::vector<std::pair<int, string> > myPair;
			std::string fileName = "c:\\projects\\test\\File_1.txt";
			
			int actualRes  = obj.writeOutputFile(fileName, myPair);
			
			Assert::AreEqual(expectedRes , actualRes);
		};
		
		[TestMethod]
		void writeOutputFile_success()
		{
			CTransMaxTestSolution obj;
			int  expectedRes = 0;
			std::vector<std::pair<int, string> > myPair;
			std::string fileName = "c:\\projects\\codingtest\\File_2.txt";
			
			myPair.push_back(std::make_pair(100, "name"));
			int actualRes  = obj.writeOutputFile(fileName, myPair);
			
			Assert::AreEqual(expectedRes , actualRes);
		};
		
		//UnitTesting for sorting application run after build
			//Test Cases of readInputFile
		[TestMethod]
		void readInputFile_sortSuccess()
		{
			CTransMaxTestSolution obj;
			int  expectedRes = 0;
			std::vector<std::pair<int, string> > myPair;
			std::vector<std::pair<int, string> >::iterator iter  = myPair.begin();
			std::string fileName = "c:\\projects\\codingtest\\names-graded.txt";
			int actualRes  = obj.readInputFile(fileName, myPair);
			Assert::AreEqual(expectedRes , actualRes);
			
			 ::iterator
			std::vector<std::pair<int, string> > myExpectedRes;
			fileName = "c:\\projects\\codingtest\\ExpectedRes.txt";
			int actualRes  = obj.readInputFile(fileName, myExpectedRes);
			std::vector<std::pair<int, string> >::iterator iterExpected = myExpectedRes.begin();
			
			for(;iter!=myPair.end() && iterExpected != myExpectedRes.end(); ++iter,++iterExpected)
			{
				int marksActual = iter->first;
				string nameActual = iter->second;
				
				int marksExpected = iterExpected->first;
				string nameExpected = iterExpected->second;
				
				int res = nameActual.compare(nameExpected);
				
				Assert::AreEqual(0 , res);
				Assert::AreEqual(marksActual , marksExpected);
			}
			
		};
		
	};
}
