// Learning FStream.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>

//global const of file name
const std::string myfile = "Input.txt";

std::string ReadFileIntoString(std::string filename)
{
	//define an input file stream called ReadFile
	std::fstream ReadFile;

	//open the file into the stream
	ReadFile.open(filename);

	//define a string to hold the final and each temporary output
	std::string strResult;
	std::string strTemp;

	while (!ReadFile.eof())
	{
		std::getline(ReadFile, strTemp);
		if (strResult.empty())
		{
			strResult = strTemp;
		}
		else
		{
			strResult = strResult + "\n" + strTemp;
		}
	}
	ReadFile.close();

	return strResult;
}



int main()
{
	std::string strFile;

	strFile = ReadFileIntoString(myfile);
	std::cout << strFile << "\n";

	system("PAUSE");
	
	return 0;
}

