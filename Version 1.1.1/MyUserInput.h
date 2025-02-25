#pragma once
#include<iostream>
using namespace std;

namespace MyUserInput
{

	int ReadPositiveNumber(string mssg)
	{
		int number;
		do
		{
			cout << mssg;
			cin >> number;
		} while (number < 0);
		return number;
	}


	float ReadNumber(string mssg)
	{
		float number;
	
		cout << mssg;
		cin >> number;
		return number;
	}

	int ReadValue()
	{
		int number;
		cin >> number;
		return number;
	}

	

	int ReadNumberInRange(string mssg, int from, int to)
	{
		int number;
		do
		{
			cout << mssg;
			cin >> number;
		} while (number<from || number>to);
		return number;
	}

}
