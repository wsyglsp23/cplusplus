#pragma once
#include<iostream>
#include<string>
#include"fileError.h"
#include<sstream>
using namespace std;
class FileReadError :public FileError
{
public:
	FileReadError(const string&fileNameIn, int lineNumIn);
	int getLineNum() { return mLineNum; }
private:
	int mLineNum;
};
FileReadError::FileReadError(const string & fileNameIn, int lineNumIn):FileError(fileNameIn),mLineNum(lineNumIn)
{
	ostringstream ostr;
	ostr << "Error reading " << fileNameIn << " at line " << lineNumIn;
	setMessage(ostr.str());
}