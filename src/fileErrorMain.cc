//#include"stdafx.h"
#include<iostream>
#include"fileOpenError.h"
#include"fileReadError.h"
#include<fstream>
#include<vector>
using namespace std;
/**
readIntegerFile()函数
正确设置行号，跟踪所读取的行号
*/
void readIntegerFile(const string& fileName, vector<int>&dest)
{
	ifstream istr;
	int temp;
	string line;
	int lineNumber = 0;
	istr.open(fileName);
	if (istr.fail())
	{
		throw FileOpenError(fileName);
	}
	while (!istr.eof())
	{
		//read one line from the file
		getline(istr, line);
		lineNumber++;
		//Create a string stream out of the line.
		istringstream lineStream(line);
		//Read the integers one by one and add them to the vector
		while (lineStream >> temp)
		{
			dest.push_back(temp);
		}
		if (!lineStream.eof())
		{
			//we did not reach the end of the string stream
			//this means that some error occurred while reading this line.
			//throw an exception
			throw FileReadError(fileName, lineNumber);
		}
	}
}
int main()
{
	vector<int> myInts;
	const string fileName = "/mnt/xzj/cplusplus/src/1.txt";
	try {
		readIntegerFile(fileName, myInts);
	}
	catch (const FileError&e) {
		cerr << e.what() << endl;
		return 1;
	}
	for (const auto element : myInts)
	{
		cout << element << " ";
	}
	cout << endl;
	return 0;
}