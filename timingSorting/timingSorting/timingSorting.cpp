// timingSorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <fstream>
#include <ostream>
#include <istream>
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <string>
#include <ctime>
#include <chrono>
using namespace std;


void bubbleSort(vector<double> &target);
void selectionSort(vector<double> &target);
void mergeSort(vector<double> &target);
void insertionSort(vector<double> &target);
void shellSort(vector<double> &target);
void quickSort(vector<double> &target, int low, int high);
int partition(vector<double> &target, int low, int high);

void swap(vector<double> &target, int i, int j);

void timeBubbleSort(vector<vector<double>> target, string fileName);
void timeSelectionSort(vector<vector<double>> target, string fileName);
void timeMergeSort(vector<vector<double>> target, string fileName);
void timeInsertionSort(vector<vector<double>> target, string fileName);
void timeShellSort(vector<vector<double>> target, string fileName);
void timeSTLSort(vector<vector<double>> target, string fileName);
void timeQuickSort(vector<vector<double>> target, string fileName);
void testSortingAlgs(string fileName);

int main()
{	
	testSortingAlgs("buttsInACan.txt");
	while (true)
	{ }
	return 0;
	///////////////////////write code for quick sort//////////////////////
}

void bubbleSort(vector<double> &target)
{
	bool sorted = false;
	int i = 0;
	while (!sorted)
	{
		sorted = true;
		for (int j = 0; j < target.size() - i - 1; j++)
		{
			if (target[j] > target[j + 1])
			{
				sorted = false;
				swap(target, j, j + 1);
			}
		}
		i++;
	}
}

void selectionSort(vector<double> &target)
{
	int minValInd;
	for (int i = 0; i < target.size() - 1; i++)
	{
		minValInd = i;
		for (int j = i; j < target.size(); j++)
			if (target[j] < target[minValInd])
				minValInd = j;
		if (minValInd != i)
			swap(target, i, minValInd);
	}

}

void mergeSort(vector<double> &target)
{
	vector<double> left, right;
	int size = target.size();
	if (size > 1)
	{
		for (int i = 0; i < size / 2; i++)
			left.push_back(target[i]);
		for (int i = size / 2; i < size; i++)
			right.push_back(target[i]);
		mergeSort(left);
		mergeSort(right);
	}
	else
		return;
	target.clear();
	while (left.size() != 0 && right.size() != 0)
	{
		if (left[0] < right[0])
		{
			target.push_back(left[0]);
			left.erase(left.begin());
		}
		else
		{
			target.push_back(right[0]);
			right.erase(right.begin());
		}
	}
	if (left.size() != 0)
		for (int i = 0; i < left.size(); i++)
			target.push_back(left[i]);
	else if (right.size() != 0)
		for (int i = 0; i < right.size(); i++)
			target.push_back(right[i]);
}

void insertionSort(vector<double> &target)
{
	double val;
	int holePos = 0;

	for (int i = 1; i < target.size(); i++)
	{
		val = target[i];

		holePos = i;

		while (holePos > 0 && target[holePos - 1] > val)
		{
			target[holePos] = target[holePos - 1];
			holePos--;
		}
		target[holePos] = val;
	}
}

void shellSort(vector<double> &target)
{
	int i, j, increment;
	int size = target.size();
	double temp;
	increment = size / 2;
	while (increment > 0)
	{

		for (i = 0; i < size; i++)
		{
			j = i;
			temp = target[i];
			while ((j >= increment) && (target[j - increment] > temp))
			{
				target[j] = target[j - increment];
				j = j - increment;
			}
			target[j] = temp;
		}
		if (increment == 2)
			increment = 1;
		else
			increment = increment * 5 / 11;

	}
}

/*This function swaps two elements in a vector
target -> Vector of interest
i, j -> indicies for elements in target to swap*/
void swap(vector<double> &target, int i, int j)
{
	double temp = target[i];
	target[i] = target[j];
	target[j] = temp;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(vector<double> &target, int low, int high)
{
	int pivot = target[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (target[j] <= pivot)
		{
			i++;    // increment index of smaller element
			swap(target, i, j);
		}
	}
	swap(target, i + 1, high);
	return (i + 1);
}

/* The main function that implements QuickSort
target --> Vector to be sorted,
low  --> Starting index,
high  --> Ending index */
void quickSort(vector<double> &target, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(target, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(target, low, pi - 1);
		quickSort(target, pi + 1, high);
	}
}

void timeBubbleSort(vector<vector<double>> target, string fileName)
{
	double t;
	string dataToWrite;
	ofstream addDataFile;

	addDataFile.open(fileName.c_str(), fstream::app);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	addDataFile.write("Bubble sort,", string("Bubble sort,").size());

	for (int i = 0; i < target.size(); i++)
	{
		dataToWrite.clear();
		cout << "bubble " << target[i].size() << endl;
		start = std::chrono::high_resolution_clock::now();
		for (int k = 0; k < 25; k++)
			bubbleSort(target[i]);
		finish = std::chrono::high_resolution_clock::now();
		t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() / 25;


		dataToWrite.append(to_string(t));
		dataToWrite.append(",");

		addDataFile.write(dataToWrite.c_str(), dataToWrite.size());
	}


	addDataFile.write("\n", string("\n").size());
	addDataFile.close();


}

void timeSelectionSort(vector<vector<double>> target, string fileName)
{
	double t;
	string dataToWrite;
	ofstream addDataFile;

	addDataFile.open(fileName.c_str(), fstream::app);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	addDataFile.write("Selection sort,", string("Selection sort,").size());

	for (int i = 0; i < target.size(); i++)
	{
		dataToWrite.clear();
		cout << "selection " << target[i].size() << endl;
		start = std::chrono::high_resolution_clock::now();
		for (int k = 0; k < 25; k++)
			selectionSort(target[i]);
		finish = std::chrono::high_resolution_clock::now();
		t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() / 25;


		dataToWrite.append(to_string(t));
		dataToWrite.append(",");

		addDataFile.write(dataToWrite.c_str(), dataToWrite.size());
	}


	addDataFile.write("\n", string("\n").size());
	addDataFile.close();
}

void timeMergeSort(vector<vector<double>> target, string fileName)
{
	double t;
	string dataToWrite;
	ofstream addDataFile;

	addDataFile.open(fileName.c_str(), fstream::app);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	addDataFile.write("Merge sort,", string("Merge sort,").size());

	for (int i = 0; i < target.size(); i++)
	{
		dataToWrite.clear();
		cout << "merge " << target[i].size() << endl;
		start = std::chrono::high_resolution_clock::now();
		for (int k = 0; k < 25; k++)
			mergeSort(target[i]);
		finish = std::chrono::high_resolution_clock::now();
		t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() / 25;


		dataToWrite.append(to_string(t));
		dataToWrite.append(",");

		addDataFile.write(dataToWrite.c_str(), dataToWrite.size());
	}


	addDataFile.write("\n", string("\n").size());
	addDataFile.close();
}

void timeInsertionSort(vector<vector<double>> target, string fileName)
{
	double t;
	string dataToWrite;
	ofstream addDataFile;

	addDataFile.open(fileName.c_str(), fstream::app);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	addDataFile.write("Insertion sort,", string("Insertion sort,").size());

	for (int i = 0; i < target.size(); i++)
	{
		dataToWrite.clear();
		cout << "Insertion " << target[i].size() << endl;
		start = std::chrono::high_resolution_clock::now();
		for (int k = 0; k < 25; k++)
			insertionSort(target[i]);
		finish = std::chrono::high_resolution_clock::now();
		t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() / 25;


		dataToWrite.append(to_string(t));
		dataToWrite.append(",");

		addDataFile.write(dataToWrite.c_str(), dataToWrite.size());
	}


	addDataFile.write("\n", string("\n").size());
	addDataFile.close();
}

void timeShellSort(vector<vector<double>> target, string fileName)
{
	double t;
	string dataToWrite;
	ofstream addDataFile;

	addDataFile.open(fileName.c_str(), fstream::app);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	addDataFile.write("Shell sort,", string("Shell sort,").size());

	for (int i = 0; i < target.size(); i++)
	{
		dataToWrite.clear();
		cout << "Shell " << target[i].size() << endl;
		start = std::chrono::high_resolution_clock::now();
		for (int k = 0; k < 25; k++)
			shellSort(target[i]);
		finish = std::chrono::high_resolution_clock::now();
		t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() / 25;


		dataToWrite.append(to_string(t));
		dataToWrite.append(",");

		addDataFile.write(dataToWrite.c_str(), dataToWrite.size());
	}


	addDataFile.write("\n", string("\n").size());
	addDataFile.close();
}

void timeSTLSort(vector<vector<double>> target, string fileName)
{
	double t;
	string dataToWrite;
	ofstream addDataFile;

	addDataFile.open(fileName.c_str(), fstream::app);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	addDataFile.write("STL sort,", string("STL sort,").size());

	for (int i = 0; i < target.size(); i++)
	{
		dataToWrite.clear();
		cout << "stl " << target[i].size() << endl;
		start = std::chrono::high_resolution_clock::now();
		for (int k = 0; k < 25; k++)
			sort(target[i].begin(),target[i].end());
		finish = std::chrono::high_resolution_clock::now();
		t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() / 25;


		dataToWrite.append(to_string(t));
		dataToWrite.append(",");

		addDataFile.write(dataToWrite.c_str(), dataToWrite.size());
	}


	addDataFile.write("\n", string("\n").size());
	addDataFile.close();
}

void timeQuickSort(vector<vector<double>> target, string fileName)
{
	double t;
	string dataToWrite;
	ofstream addDataFile;

	addDataFile.open(fileName.c_str(), fstream::app);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	addDataFile.write("Quick sort,", string("Quick sort,").size());

	for (int i = 0; i < target.size(); i++)
	{
		dataToWrite.clear();
		cout << "quick " << target[i].size() << endl;
		start = std::chrono::high_resolution_clock::now();
		for (int k = 0; k < 25; k++)
			quickSort(target[i], 0, target[i].size() - 1);
		finish = std::chrono::high_resolution_clock::now();
		t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() / 25;


		dataToWrite.append(to_string(t));
		dataToWrite.append(",");

		addDataFile.write(dataToWrite.c_str(), dataToWrite.size());
	}


	addDataFile.write("\n", string("\n").size());
	addDataFile.close();
}



void testSortingAlgs(string fileName)
{
	int sizeList = 1000;
	vector<double> tempList;
	vector<vector<double>> testLists;
	for (int i = 0; i < 10; i++)
	{
		tempList.clear();
		for (int j = 0; j < sizeList; j++)
			tempList.push_back(((double)(rand() % 1000)) / 5);
		testLists.push_back(tempList);
		sizeList = sizeList + 1000;
	}
	/*timeBubbleSort(testLists, fileName);
	cout << "bubble done" << endl;*/
	timeSelectionSort(testLists, fileName);
	cout << "selection done" << endl;
	timeMergeSort(testLists, fileName);
	cout << "merge done" << endl;
	timeInsertionSort(testLists, fileName);
	cout << "insertion done" << endl;
	timeShellSort(testLists, fileName);
	cout << "shell done" << endl;
	timeSTLSort(testLists, fileName);
	cout << "stl done" << endl;
	timeQuickSort(testLists, fileName);
	cout << "Quick done" << endl;
	
	

}
