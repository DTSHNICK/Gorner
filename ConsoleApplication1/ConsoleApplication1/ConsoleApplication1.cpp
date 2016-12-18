// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

#define ARRAY_SIZE 4
bool findResolve(int* variable, int* values, int x);
int main()
{
	setlocale(LC_ALL, "Russian");
	int variable[ARRAY_SIZE] =
	{
		1,
		-1,
		-8,
		-4
	};
	int values[ARRAY_SIZE];
	cout << "----------------------------------------------------------\n";
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << "\t" << variable[i] << "\t";
	}
	//Делаем перебор
	bool flag = false;
	for (int i = 0 ; i < 0xFFFF; i++)
	{
		flag = findResolve(variable, values, i);
		if (flag)
		{
			cout << "Корень найден\t" << i;
			break;
		}
		if (i != 0)
			flag = findResolve(variable, values, -1 * i);
		if (flag)
		{
			cout << "Корень найден\t"<< -1*i;
			break;
		}
	}

	
	getchar();
    return 0;
}

bool findResolve(int* variable, int* values, int x)
{
	cout << "\n----------------------------------------------------------\n";
	cout << x << "\t";
	values[0] = variable[0];
	cout << values[0] << "\t\t";
	for (int j = 1; j < ARRAY_SIZE; j++)
	{
		values[j] = values[j - 1] * x + variable[j];
		cout << values[j] << "\t\t";
	}
	cout << "\n";
	if (values[ARRAY_SIZE - 1] == 0)
	{
		return true;
	}
	return false;
}
