// gaussElimination.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <math.h>
using namespace std;

vector<double> gaussElim(vector<vector<double>> coefficientMatrix);
vector<vector<double>> inputSysOfEqs();
void timeGaussElim(string fileName);

int main()
{
	vector<double> solution;
	vector<vector<double>> augMat;
	bool keepSolving = true;
	char yOrN;
	
	//timeGaussElim("buttStuff.txt");

	while (keepSolving)
	{
		solution.clear();
		augMat.clear();
		augMat = inputSysOfEqs();

		solution = gaussElim(augMat);


		for (int i = 0; i < (int)solution.size(); i++)
			cout << "x" << i << ": " << solution[i] << endl;

		cout << endl << "Solve another system?(y/n): ";
		cin >> yOrN;
		cout << endl;
		if (yOrN == 'n' || yOrN == 'N')
			keepSolving = false;
	}
	


	return 0;
}

vector<double> gaussElim(vector<vector<double>> coefficientMatrix)
{
	try
	{
		int numEquations = coefficientMatrix.size();
		double pivot;
		vector<double> rtn, swapTemp;
		ofstream errorFile;
		string errorString;
		errorFile.open("Errors.txt", fstream::app);
		for (int i = 0; i < numEquations; i++)
			if (coefficientMatrix[i].size() != numEquations+1)
				throw i;

		for (int i = 0; i < numEquations; i++)
		{
			int maxRowIndex = i;
			for (int j = i; j < numEquations; j++)
				if (coefficientMatrix[j][i] > coefficientMatrix[maxRowIndex][i])
					maxRowIndex = j;
			if (maxRowIndex != i)
			{
				swapTemp = coefficientMatrix[i];
				coefficientMatrix[i] = coefficientMatrix[maxRowIndex];
				coefficientMatrix[maxRowIndex] = swapTemp;
			}
			if (maxRowIndex == i && coefficientMatrix[i][i] == 0.0)
			{
				errorString = "Error in gaussian elimination! Either 0 or infinity solutions. Size of augmented matrix that generated error: ";
				errorString.append(to_string(numEquations));
				errorString.append("x");
				errorString.append(to_string(numEquations+1));
				errorFile.write(errorString.c_str(), errorString.size());
				return rtn;
			}

			for (int j = i + 1; j < numEquations; j++)
			{
				pivot = coefficientMatrix[j][i] / coefficientMatrix[i][i];
				for (int k = 0; k <= numEquations; k++)
					coefficientMatrix[j][k] = coefficientMatrix[j][k] - (coefficientMatrix[i][k] * pivot);
			}
		}

		for (int i = 0; i < numEquations; i++)
			for (int j = i + 1; j < numEquations; j++)
			{
				if (coefficientMatrix[numEquations - 1 - i][numEquations - 1 - i] != 0)
				{
					pivot = coefficientMatrix[numEquations - 1 - j][numEquations - 1 - i] / coefficientMatrix[numEquations - 1 - i][numEquations - 1 - i];
					coefficientMatrix[numEquations - 1 - j][numEquations - 1 - i] = coefficientMatrix[numEquations - 1 - j][numEquations - 1 - i] - (pivot * coefficientMatrix[numEquations - 1 - i][numEquations - 1 - i]);
					coefficientMatrix[numEquations - 1 - j][numEquations] = coefficientMatrix[numEquations - 1 - j][numEquations] - (pivot * coefficientMatrix[numEquations - 1 - i][numEquations]);
				}
			}

		for (int i = 0; i < numEquations; i++)
			rtn.push_back(coefficientMatrix[i][numEquations] / coefficientMatrix[i][i]);

		return rtn;

	}
	catch (int e)
	{
		cout << "Error! Equation " << e << " has too few argument coefficients!";
		while (true)
		{ }
	}



	
}

vector<vector<double>> inputSysOfEqs()
{
	vector<vector<double>> rtn;
	vector<double> workingEq;
	int numEqs;
	double nextCo;

	cout << "Enter the number of equations you would like to create: ";
	cin >> numEqs;
	cout << endl;
	for (int j = 0; j < numEqs; j++)
	{
		cout << "Equation " << j << ":" << endl;
		workingEq.clear();
		for (int i = 0; i < numEqs; i++)
		{
			cout << "Please enter the coefficient of x" << i << " for equation " << j << "(can be int or double): ";
			cin >> nextCo;
			cout << endl;
			workingEq.push_back(nextCo);
		}
		cout << "Please enter the constant on the right of the equal sign for equation " << j << ": ";
		cin >> nextCo;
		cout << endl;
		workingEq.push_back(nextCo);
		rtn.push_back(workingEq);
	}

	return rtn;
}

void timeGaussElim(string fileName)
{
	double t;
	string dataToWrite;
	ofstream addDataFile;
	vector<vector<double>> augMat;
	vector<double> tempVector;

	addDataFile.open(fileName.c_str(), fstream::app);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	addDataFile.write("Gauss Elim,", string("Gauss Elim,").size());
	

	for (int i = 20; i < 100; i += 10)
	{
		dataToWrite = "";
		augMat.clear();
		for (int j = 0; j < i; j++)
		{
			tempVector.clear();
			for (int k = 0; k < i + 1; k++)
			{
				tempVector.push_back((rand() % 100) / ((rand() % 10)+1));
			}
			augMat.push_back(tempVector);
		}
		for (int j = 0; j < 5; j++)
		{
			dataToWrite.clear();
			auto start = std::chrono::high_resolution_clock::now();
			gaussElim(augMat);
			auto finish = std::chrono::high_resolution_clock::now();
			t = (double)std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
			dataToWrite.append(to_string((int)t));
			dataToWrite.append(",");
			addDataFile.write(dataToWrite.c_str(), dataToWrite.size());
		}
		addDataFile.write("\n", string("\n").size());

	}

}