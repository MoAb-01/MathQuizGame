#pragma once
#include<iostream>
using namespace std;

namespace MySetScreen
{
	void ResetScreen()
	{
		system("cls");
		system("color 07");
	}
	void SetBackgroundGreen()
	{
		system("color 2f");
	}
	void SetBackgroundRed()
	{
		system("color 4f");
	}
		
	
}
