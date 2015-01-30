#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 8

int main(int argc, char* argv[])
{
	int mush[MAX];
	int result = 0;
	int res_temp[MAX];

	cout << "Please enter the amount of mushroom in each piece of the pizza :" << endl;
	for(int i = 0 ; i < MAX ; i++)
	{
		cin >> mush[i];
		res_temp[i] = 0;
	}

	int pos;
	for(int i = 0 ; i < MAX ; i++)
	{
		for(int j = 0 ; j < MAX/2 ; j++)
		{
			pos = (i+j > 7) ? i+j-8 : i+j;
			res_temp[i] += mush[pos];
		}
	}

	for(int i = 0 ; i < MAX ; i++)
	{
		result = (result < res_temp[i]) ? res_temp[i] : result;
	}

	cout << result << endl;

	return EXIT_SUCCESS;
}