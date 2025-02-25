#pragma once
#include <cstdlib>

namespace MyRandomOperation
{
	int GetRandom(int from, int to) 
	{
		return from + rand() % (to - from + 1);
	}


}
