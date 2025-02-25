#pragma once
#include <cmath>
namespace MyEvaluate
{
	string CheckPass(int Questions, int CorrectAns)
	{
		string Result = "";
		int HalfQuestions = ceil((float)Questions / 2);
		if (CorrectAns >= HalfQuestions)
			Result = "Pass :-)";
		else if (CorrectAns == 0 || CorrectAns < HalfQuestions)
			Result = "Failed :-(";
		return Result;
	}
}
