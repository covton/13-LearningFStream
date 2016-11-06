// Learning FStream.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

//global const of file name
const std::string myfile = "Input.txt";

std::vector<std::string> ReadFileIntoVector(std::string filename)
{
	//define an input file stream called ReadFile
	std::fstream ReadFile;

	//open the file into the stream
	ReadFile.open(filename);

	//define a vector to hold each result 
	std::string strTemp;
	std::vector<std::string> vecResult;

	while (!ReadFile.eof())
	{
		//read each line into a temporary string
		while (std::getline(ReadFile, strTemp))
		{
			while (strTemp.length() > 0)
			{
				//now break on commas and store index, then push into vecResult
				int index = strTemp.find_first_of(',');

					//find_first_of returns std::string::npos if it doesn't find anything
					if (index == std::string::npos)
					{
						vecResult.push_back(strTemp);
					}
					else
					{
						vecResult.push_back(strTemp.substr(0, index));
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
	return vecResult;
}



int main()
{
	std::vector<std::string> vecFile;
	vecFile = ReadFileIntoVector(myfile);
	
	//loop through vector and print
	for (unsigned int i = 0; i < vecFile.size(); i++)
	{
		std::cout << vecFile.at(i) << "\n";
	}

	system("PAUSE");
	
	return 0;
}

