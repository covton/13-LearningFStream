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
	std::string strTemp;
	std::string strResult;

	while (!ReadFile.eof())
	{
		//read each line into a temporary string
		while (std::getline(ReadFile, strTemp))
		{
			while (strTemp.length() > 0)
			{
				//now break on commas and store index, then push into strResult
				int index = strTemp.find_first_of(',');

				if (strResult.empty())
				{
					//find_first_of return std::string::npos if it doesn't find anything
					if (index == std::string::npos)
					{
						strResult = strTemp;
					}
					else
					{
						strResult = strTemp.substr(0, index);
					}
				}
				else
				{
					if (index == std::string::npos)
					{
						strResult = strResult + "\n" + strTemp;
					}
					else
					{
						strResult = strResult + "\n" + strTemp.substr(0, index);
					}
				}
				//remove the start of strTemp and loop
				if (index == std::string::npos)
				{
					strTemp = "";
				}
				else
				{
					strTemp = strTemp.substr(index + 2);
				}
			}
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

