#include "stdafx.h"
#include "primeAlgs.h"
#include <cmath>
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

bool primeAlgs::primeOne(int n)
{
	int i;
	bool isPrime;

	if (n < 2)
		return false;

	if (n == 2)
		return true;

	isPrime = true;
	for (i = 2; i < n; i++)
		if ((n % i) == 0)
			isPrime = false;

	return isPrime;
	
}

bool primeAlgs::primeTwo(int n)
{
	int i;
	bool isPrime;

	if (n < 2)
		return false;

	if (n == 2)
		return true;

	isPrime = true;
	for (i = 2; i < sqrt(n); i++)
		if ((n % i) == 0)
			isPrime = false;

	return isPrime;
}

bool primeAlgs::primeThree(int n)
{
	int i;
	bool isPrime;

	if (n < 2)
		return false;

	if (n == 2)
		return true;

	isPrime = true;
	for (i = 2; i < sqrt(n); i++)
	{
		if ((n % i) == 0)
		{
			isPrime = false;
			break;
		}
	}

	return isPrime;
}

void primeAlgs::listPrimesOne(int n)
{
	int j;
	bool isPrime;

	cout << "2 is prime." << endl;

	for (j = 3; j < n + 1; j++)
	{
		isPrime = true;
		isPrime = primeOne(j);
		if (isPrime)
			cout << j << " is prime." << endl;
	}
}

void primeAlgs::listPrimesTwo(int n)
{
	int j;
	bool isPrime;

	cout << "2 is prime." << endl;

	for (j = 3; j < n + 1; j++)
	{
		isPrime = true;
		isPrime = primeTwo(j);
		if (isPrime)
			cout << j << " is prime." << endl;
	}
}

void primeAlgs::listPrimesThree(int n)
{
	int j;
	bool isPrime;

	cout << "2 is prime." << endl;

	for (j = 3; j < n + 1; j++)
	{
		isPrime = true;
		isPrime = primeThree(j);
		if (isPrime)
			cout << j << " is prime." << endl;
	}
}

void primeAlgs::listPrimesFour(int n)
{
	int i, j;
	bool isPrime;
	vector<int> primeList;

	cout << "2 is prime." << endl;
	primeList.push_back(2);

	for (j = 3; j < n + 1; j++)
	{
		isPrime = true;
		i = 0;
		while (primeList[i] < (int)sqrt(double(j)))
		{
			if ((j % primeList[i]) == 0)
			{
				isPrime = false;
				break;
			}
			i++;
		}
		/*for (i = 0; i < primeList.size(); i++)
			if ((j % primeList[i]) == 0)
			{
				isPrime = false;
				break;
			}*/

		if (isPrime)
		{
			cout << j << " is prime." << endl;
			primeList.push_back(j);
		}
	}
}


