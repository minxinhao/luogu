#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;
const int maxn = 2000;


int main(int argc, char const *argv[])
{
	int n = 50;
	srand(time(NULL));
	for (int j = 0; j < n; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			printf("%d",rand()%2);
		}
		printf("\n");
	}
	
	return 0;
}