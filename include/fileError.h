#pragma once
#include<iostream>
#include<exception>
#include<string>
using namespace std;
class FileError :public exception
{
public:
	FileError(const string& fileIn) :mFile(fileIn) {};
	virtual const char* what() const noexcept override { return mMgs.c_str(); }
	const string& getFileName() { return mFile; }
protected:
	void setMessage(const string &message) { mMgs = message; }
private:
	string mFile, mMgs;
};