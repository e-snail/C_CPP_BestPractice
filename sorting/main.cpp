#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int Partition(int array[], int low, int high)
{
	return low;
}

void QuickSorting(int array[], int low, int high)
{
	if (low < high)
	{
		int n = Partition(array, low, high);
		QuickSorting(array, low, n);
		QuickSorting(array, n+1, high);
	}
}

int main(int argc, char **argv)
{
	return 0;
}
