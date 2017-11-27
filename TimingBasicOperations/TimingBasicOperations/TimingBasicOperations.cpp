// TimingBasicOperations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <math.h>
#include <vector>
using namespace std;

void timeIntAddition(int a, int b, string fileName);
void timeIntMultiplication(int a, int b, string fileName);
void timeIntDivision(int a, int b, string fileName);

void timeDoubleAddition(double a, double b, string fileName);
void timeDoubleMultiplication(double a, double b, string fileName);
void timeDoubleDivision(double a, double b, string fileName);

void timeSine(double a, string fileName);
void timePow(double a, double b, string fileName);
void timePrint(string fileName);

int main()
{	
	
	string fileName = "dataYay.txt";
	
	timeIntAddition(23, 38, fileName);
	timeIntAddition(7261852, 4917528, fileName);
	timeIntMultiplication(23, 38, fileName);
	timeIntMultiplication(7261852, 4917528, fileName);
	timeIntDivision(23, 38, fileName);
	timeIntDivision(7261852, 4917528, fileName);
	
	timeDoubleAddition(23.3, 38.1, fileName);
	timeDoubleAddition(7261852.6, 4917528.9, fileName);
	timeDoubleMultiplication(23.3, 38.1, fileName);
	timeDoubleMultiplication(7261852.6, 4917528.9, fileName);
	timeDoubleDivision(23.3, 38.1, fileName);
	timeDoubleDivision(7261852.6, 4917528.9, fileName);

	timeSine(1.23, fileName);
	timePow(3.12, 2.78, fileName);
	timePrint(fileName);


	
	
	
	return 0;
}

void timeIntAddition(int a, int b, string fileName)
{
	double t;
	string dataToWrite;
	ofstream addDataFile;
	vector<double> twentyOneTimes;
	
	addDataFile.open(fileName.c_str(), fstream::app);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	addDataFile.write("Int add,", string("Int add,").size());

	for (int i = 5000; i < 10000; i += 1000)
	{
		dataToWrite.clear();
		for (int j = 0; j < 21; j++)
		{
			start = std::chrono::high_resolution_clock::now();
			for (int k = 0; k < i; k++)
				a + b;
			finish = std::chrono::high_resolution_clock::now();
			t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
			twentyOneTimes.push_back(t/i);
		}
		bool sorted = false;
		double temp;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < twentyOneTimes.size() - 1; i++)
			{
				if (twentyOneTimes[i] > twentyOneTimes[i + 1])
				{
					sorted = false;
					temp = twentyOneTimes[i];
					twentyOneTimes[i] = twentyOneTimes[i + 1];
					twentyOneTimes[i + 1] = temp;
				}
			}
		}
		
		
		dataToWrite.append(to_string((float)twentyOneTimes[15]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[20]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[0]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[5]));
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");

		addDataFile.write(dataToWrite.c_str(), dataToWrite.size());



	}
	addDataFile.write("\n", string("\n").size());
	/*addDataFile.write("One Opp", string("One Opp").size());
	addDataFile.write("\n", string("\n").size());*/

	
}

void timeIntMultiplication(int a, int b, string fileName)
{
	double t;
	string dataToWrite;
	ofstream addDataFile;
	vector<double> twentyOneTimes;

	addDataFile.open(fileName.c_str(), fstream::app);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	addDataFile.write("Int mult,", string("Int mult,").size());

	for (int i = 5000; i < 10000; i += 1000)
	{
		dataToWrite.clear();
		for (int j = 0; j < 21; j++)
		{
			start = std::chrono::high_resolution_clock::now();
			for (int k = 0; k < i; k++)
				a * b;
			finish = std::chrono::high_resolution_clock::now();
			t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
			twentyOneTimes.push_back(t/i);
		}
		bool sorted = false;
		double temp;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < twentyOneTimes.size() - 1; i++)
			{
				if (twentyOneTimes[i] > twentyOneTimes[i + 1])
				{
					sorted = false;
					temp = twentyOneTimes[i];
					twentyOneTimes[i] = twentyOneTimes[i + 1];
					twentyOneTimes[i + 1] = temp;
				}
			}
		}


		dataToWrite.append(to_string((float)twentyOneTimes[15]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[20]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[0]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[5]));
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");

		addDataFile.write(dataToWrite.c_str(), dataToWrite.size());



	}
	addDataFile.write("\n", string("\n").size());
	/*addDataFile.write("One Opp", string("One Opp").size());
	addDataFile.write("\n", string("\n").size());*/


}

void timeIntDivision(int a, int b, string fileName)
{
	double t;
	string dataToWrite;
	ofstream addDataFile;
	vector<double> twentyOneTimes;

	addDataFile.open(fileName.c_str(), fstream::app);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	addDataFile.write("Int div,", string("Int div,").size());

	for (int i = 5000; i < 10000; i += 1000)
	{
		dataToWrite.clear();
		for (int j = 0; j < 21; j++)
		{
			start = std::chrono::high_resolution_clock::now();
			for (int k = 0; k < i; k++)
				a / b;
			finish = std::chrono::high_resolution_clock::now();
			t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
			twentyOneTimes.push_back(t/i);
		}
		bool sorted = false;
		double temp;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < twentyOneTimes.size() - 1; i++)
			{
				if (twentyOneTimes[i] > twentyOneTimes[i + 1])
				{
					sorted = false;
					temp = twentyOneTimes[i];
					twentyOneTimes[i] = twentyOneTimes[i + 1];
					twentyOneTimes[i + 1] = temp;
				}
			}
		}


		dataToWrite.append(to_string((float)twentyOneTimes[15]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[20]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[0]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[5]));
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");

		addDataFile.write(dataToWrite.c_str(), dataToWrite.size());



	}
	addDataFile.write("\n", string("\n").size());
	/*addDataFile.write("One Opp", string("One Opp").size());
	addDataFile.write("\n", string("\n").size());*/


}

void timeDoubleAddition(double a, double b, string fileName)
{
	double t;
	string dataToWrite;
	ofstream addDataFile;
	vector<double> twentyOneTimes;

	addDataFile.open(fileName.c_str(), fstream::app);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	addDataFile.write("Double add,", string("Double add,").size());

	for (int i = 5000; i < 10000; i += 1000)
	{
		dataToWrite.clear();
		for (int j = 0; j < 21; j++)
		{
			start = std::chrono::high_resolution_clock::now();
			for (int k = 0; k < i; k++)
				a + b;
			finish = std::chrono::high_resolution_clock::now();
			t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
			twentyOneTimes.push_back(t/i);
		}
		bool sorted = false;
		double temp;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < twentyOneTimes.size() - 1; i++)
			{
				if (twentyOneTimes[i] > twentyOneTimes[i + 1])
				{
					sorted = false;
					temp = twentyOneTimes[i];
					twentyOneTimes[i] = twentyOneTimes[i + 1];
					twentyOneTimes[i + 1] = temp;
				}
			}
		}


		dataToWrite.append(to_string((float)twentyOneTimes[15]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[20]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[0]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[5]));
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");

		addDataFile.write(dataToWrite.c_str(), dataToWrite.size());



	}
	addDataFile.write("\n", string("\n").size());
	/*addDataFile.write("One Opp", string("One Opp").size());
	addDataFile.write("\n", string("\n").size());*/


}

void timeDoubleMultiplication(double a, double b, string fileName)
{
	double t;
	string dataToWrite;
	ofstream addDataFile;
	vector<double> twentyOneTimes;

	addDataFile.open(fileName.c_str(), fstream::app);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	addDataFile.write("Double mult,", string("Double mult,").size());

	for (int i = 5000; i < 10000; i += 1000)
	{
		dataToWrite.clear();
		for (int j = 0; j < 21; j++)
		{
			start = std::chrono::high_resolution_clock::now();
			for (int k = 0; k < i; k++)
				a * b;
			finish = std::chrono::high_resolution_clock::now();
			t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
			twentyOneTimes.push_back(t/i);
		}
		bool sorted = false;
		double temp;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < twentyOneTimes.size() - 1; i++)
			{
				if (twentyOneTimes[i] > twentyOneTimes[i + 1])
				{
					sorted = false;
					temp = twentyOneTimes[i];
					twentyOneTimes[i] = twentyOneTimes[i + 1];
					twentyOneTimes[i + 1] = temp;
				}
			}
		}


		dataToWrite.append(to_string((float)twentyOneTimes[15]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[20]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[0]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[5]));
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");

		addDataFile.write(dataToWrite.c_str(), dataToWrite.size());



	}
	addDataFile.write("\n", string("\n").size());
	/*addDataFile.write("One Opp", string("One Opp").size());
	addDataFile.write("\n", string("\n").size());*/


}

void timeDoubleDivision(double a, double b, string fileName)
{
	double t;
	string dataToWrite;
	ofstream addDataFile;
	vector<double> twentyOneTimes;

	addDataFile.open(fileName.c_str(), fstream::app);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	addDataFile.write("Double div,", string("Double div,").size());

	for (int i = 5000; i < 10000; i += 1000)
	{
		dataToWrite.clear();
		for (int j = 0; j < 21; j++)
		{
			start = std::chrono::high_resolution_clock::now();
			for (int k = 0; k < i; k++)
				a / b;
			finish = std::chrono::high_resolution_clock::now();
			t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
			twentyOneTimes.push_back(t/i);
		}
		bool sorted = false;
		double temp;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < twentyOneTimes.size() - 1; i++)
			{
				if (twentyOneTimes[i] > twentyOneTimes[i + 1])
				{
					sorted = false;
					temp = twentyOneTimes[i];
					twentyOneTimes[i] = twentyOneTimes[i + 1];
					twentyOneTimes[i + 1] = temp;
				}
			}
		}


		dataToWrite.append(to_string((float)twentyOneTimes[15]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[20]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[0]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[5]));
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");

		addDataFile.write(dataToWrite.c_str(), dataToWrite.size());



	}
	addDataFile.write("\n", string("\n").size());
	/*addDataFile.write("One Opp", string("One Opp").size());
	addDataFile.write("\n", string("\n").size());*/


}

void timeSine(double a, string fileName)
{
	double t;
	string dataToWrite;
	ofstream addDataFile;
	vector<double> twentyOneTimes;

	addDataFile.open(fileName.c_str(), fstream::app);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	addDataFile.write("Sin,", string("Sin,").size());

	for (int i = 5000; i < 10000; i += 1000)
	{
		dataToWrite.clear();
		for (int j = 0; j < 21; j++)
		{
			start = std::chrono::high_resolution_clock::now();
			for (int k = 0; k < i; k++)
				sin(a);
			finish = std::chrono::high_resolution_clock::now();
			t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
			twentyOneTimes.push_back(t/i);
		}
		bool sorted = false;
		double temp;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < twentyOneTimes.size() - 1; i++)
			{
				if (twentyOneTimes[i] > twentyOneTimes[i + 1])
				{
					sorted = false;
					temp = twentyOneTimes[i];
					twentyOneTimes[i] = twentyOneTimes[i + 1];
					twentyOneTimes[i + 1] = temp;
				}
			}
		}


		dataToWrite.append(to_string((float)twentyOneTimes[15]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[20]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[0]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[5]));
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");

		addDataFile.write(dataToWrite.c_str(), dataToWrite.size());



	}
	addDataFile.write("\n", string("\n").size());
	/*addDataFile.write("One Opp", string("One Opp").size());
	addDataFile.write("\n", string("\n").size());*/


}

void timePow(double a, double b, string fileName)
{
	double t;
	string dataToWrite;
	ofstream addDataFile;
	vector<double> twentyOneTimes;

	addDataFile.open(fileName.c_str(), fstream::app);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	addDataFile.write("Pow,", string("Pow,").size());

	for (int i = 5000; i < 10000; i += 1000)
	{
		dataToWrite.clear();
		for (int j = 0; j < 21; j++)
		{
			start = std::chrono::high_resolution_clock::now();
			for (int k = 0; k < i; k++)
				pow(a,b);
			finish = std::chrono::high_resolution_clock::now();
			t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
			twentyOneTimes.push_back(t/i);
		}
		bool sorted = false;
		double temp;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < twentyOneTimes.size() - 1; i++)
			{
				if (twentyOneTimes[i] > twentyOneTimes[i + 1])
				{
					sorted = false;
					temp = twentyOneTimes[i];
					twentyOneTimes[i] = twentyOneTimes[i + 1];
					twentyOneTimes[i + 1] = temp;
				}
			}
		}


		dataToWrite.append(to_string((float)twentyOneTimes[15]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[20]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[0]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[5]));
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");

		addDataFile.write(dataToWrite.c_str(), dataToWrite.size());



	}
	addDataFile.write("\n", string("\n").size());
	/*addDataFile.write("One Opp", string("One Opp").size());
	addDataFile.write("\n", string("\n").size());*/


}

void timePrint(string fileName)
{
	double t;
	string dataToWrite;
	ofstream addDataFile;
	vector<double> twentyOneTimes;

	addDataFile.open(fileName.c_str(), fstream::app);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	addDataFile.write("Print,", string("Print,").size());

	for (int i = 5000; i < 10000; i += 1000)
	{
		dataToWrite.clear();
		for (int j = 0; j < 21; j++)
		{
			start = std::chrono::high_resolution_clock::now();
			for (int k = 0; k < i; k++)
				cout << 2;
			finish = std::chrono::high_resolution_clock::now();
			t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
			twentyOneTimes.push_back(t/i);
		}
		bool sorted = false;
		double temp;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < twentyOneTimes.size() - 1; i++)
			{
				if (twentyOneTimes[i] > twentyOneTimes[i + 1])
				{
					sorted = false;
					temp = twentyOneTimes[i];
					twentyOneTimes[i] = twentyOneTimes[i + 1];
					twentyOneTimes[i + 1] = temp;
				}
			}
		}


		dataToWrite.append(to_string((float)twentyOneTimes[15]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[20]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[0]));
		dataToWrite.append(",");
		dataToWrite.append(to_string((float)twentyOneTimes[5]));
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");
		dataToWrite.append(" ");
		dataToWrite.append(",");

		addDataFile.write(dataToWrite.c_str(), dataToWrite.size());



	}
	addDataFile.write("\n", string("\n").size());
	/*addDataFile.write("One Opp", string("One Opp").size());
	addDataFile.write("\n", string("\n").size());*/


}