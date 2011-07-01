#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

//快速排序, 复杂度为NxlogN
//http://baike.baidu.com/view/19016.htm
int Partition(int array[], int low, int high)
{
	int key = array[low];
	while (low < high)
	{ 
		while ((low < high) && key <= array[high] )
			high--;
		array[low] = array[high];

		while ((low < high) && key > array[low] )
			low++;
		array[high] = array[low];
	}

	array[low] = key;

	return low;
}

//快速排序
void QuickSorting(int array[], int low, int high)
{
	if (low < high)
	{
		int n = Partition(array, low, high);
		//cout <<n <<endl;

		QuickSorting(array, low, n);
		QuickSorting(array, n+1, high);
	}
}

//快速排序 2
void quickSort2(int v[], int left, int right)
{
	int j, last;
	if (left >= right) {
		return;
	}
	last = left;
	for (j=left+1; j<=right; j++) {
		if(v[j] < v[last]) {
			for (int i=j; i>last; i--) {
				int tmp = v[i-1];
				v[i-1] = v[i];
				v[i] = tmp;
			}
		}
		last=j;
	}
	quickSort2(v, left, last-1);
	quickSort2(v, last+1, right);
}

int main(int argc, char **argv)
{
	int array[] = {10, 9, 78, 100, 30, 4, 58, 74, 74, 14};
	//QuickSorting(array, 0, 9);
	quickSort2(array, 0, 9);

	for (int i=0; i<10; i++)
		cout <<array[i] <<endl; 
	printf("\n");

	return 0;
}
