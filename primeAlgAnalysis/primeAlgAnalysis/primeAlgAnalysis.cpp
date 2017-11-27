#include "stdafx.h"
#include "primeAlgs.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
//#include <time.h>
using namespace std;

void timePrimeOne(int topTestRange);
void timePrimeTwo(int topTestRange);
void timePrimeThree(int topTestRange);
void timePrimeFour(int topTestRange);

int main()
{
	timePrimeOne(10000);
	timePrimeTwo(10000);
	timePrimeThree(10000);
	timePrimeFour(10000);

	return 0;
}

void timePrimeOne(int topTestRange)
{
	long double t;
	string dataToWrite;
	ofstream p1dataFile;
	p1dataFile.open("timingPrimeOneAlg.txt");
	if (p1dataFile.fail())
	{
		cout << "Failed to open file for writing." << endl;
		exit(1);
	}
	for (int k = 0; k < 10; k++)
	{
		for (int i = 3; i < topTestRange; i = i + 1000)
		{
			auto start = std::chrono::high_resolution_clock::now();
			//for (int j = 0; j < 10; j++)
			//{
			primeAlgs::listPrimesOne(i);
			//}
			auto finish = std::chrono::high_resolution_clock::now();
			t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();// long double(endC - startC) / (1000);
			t = t / 1000000;
			dataToWrite = to_string(i);
			dataToWrite.append(",");
			dataToWrite.append(to_string(t).c_str());
			dataToWrite.append("\n");
			p1dataFile.write(dataToWrite.c_str(), dataToWrite.size()); //<< t << ",";
		}
		p1dataFile.write("\n\n", string("\n\n").size());
	}

	p1dataFile.close();
}

void timePrimeTwo(int topTestRange)
{
	long double t;
	string dataToWrite;
	ofstream p1dataFile;
	p1dataFile.open("timingPrimeTwoAlg.txt");
	if (p1dataFile.fail())
	{
		cout << "Failed to open file for writing." << endl;
		exit(1);
	}

	for (int k = 0; k < 10; k++)
	{
		for (int i = 3; i < topTestRange; i = i + 1000)
		{
			auto start = std::chrono::high_resolution_clock::now();
			//for (int j = 0; j < 10; j++)
			//{
			primeAlgs::listPrimesTwo(i);
			//}
			auto finish = std::chrono::high_resolution_clock::now();
			t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();// long double(endC - startC) / (1000);
			t = t / 1000000;
			dataToWrite = to_string(i);
			dataToWrite.append(",");
			dataToWrite.append(to_string(t).c_str());
			dataToWrite.append("\n");
			p1dataFile.write(dataToWrite.c_str(), dataToWrite.size()); //<< t << ",";
		}
		p1dataFile.write("\n\n", string("\n\n").size());
	}

	p1dataFile.close();
}

void timePrimeThree(int topTestRange)
{
	long double t;
	string dataToWrite;
	ofstream p1dataFile;
	p1dataFile.open("timingPrimeThreeAlg.txt");
	if (p1dataFile.fail())
	{
		cout << "Failed to open file for writing." << endl;
		exit(1);
	}
	
	for (int k = 0; k < 10; k++)
	{
		for (int i = 3; i < topTestRange; i = i + 1000)
		{
			auto start = std::chrono::high_resolution_clock::now();
			//for (int j = 0; j < 10; j++)
			//{
			primeAlgs::listPrimesThree(i);
			//}
			auto finish = std::chrono::high_resolution_clock::now();
			t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();// long double(endC - startC) / (1000);
			t = t / 1000000;
			dataToWrite = to_string(i);
			dataToWrite.append(",");
			dataToWrite.append(to_string(t).c_str());
			dataToWrite.append("\n");
			p1dataFile.write(dataToWrite.c_str(), dataToWrite.size()); //<< t << ",";
		}
		p1dataFile.write("\n\n", string("\n\n").size());
	}

	p1dataFile.close();
}

void timePrimeFour(int topTestRange)
{
	long double t;
	string dataToWrite;
	ofstream p1dataFile;
	p1dataFile.open("timingPrimeFourAlg.txt");
	if (p1dataFile.fail())
	{
		cout << "Failed to open file for writing." << endl;
		exit(1);
	}

	for (int k = 0; k < 10; k++)
	{
		for (int i = 3; i < topTestRange; i = i + 1000)
		{
			auto start = std::chrono::high_resolution_clock::now();
			//for (int j = 0; j < 10; j++)
			//{
			primeAlgs::listPrimesFour(i);
			//}
			auto finish = std::chrono::high_resolution_clock::now();
			t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();// long double(endC - startC) / (1000);
			t = t / 1000000;
			dataToWrite = to_string(i);
			dataToWrite.append(",");
			dataToWrite.append(to_string(t).c_str());
			dataToWrite.append("\n");
			p1dataFile.write(dataToWrite.c_str(), dataToWrite.size()); //<< t << ",";
		}
		p1dataFile.write("\n\n", string("\n\n").size());
	}

	p1dataFile.close();
}