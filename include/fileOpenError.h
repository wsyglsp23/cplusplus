#pragma once
#include"fileError.h"
#include<string>
#include<iostream>
using namespace std;
class FileOpenError :public FileError
{
public:
	FileOpenError(const std::string& fileNameIn);
};

FileOpenError::FileOpenError(const std::string & fileNameIn):FileError(fileNameIn)
{
	setMessage("Unable to open" + fileNameIn);
}