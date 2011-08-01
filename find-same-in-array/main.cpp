#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/**
** 两个数组安升序排列。将两个数组中一样的内容和下标打印出来。
**/
//void printSameNumInArray(int (&a)[], int (&b)[], int length_a, int length_b) //用数组引用来传递，需要指定数组的长度。
void printSameNumInArray(const int a[], const int b[], const int length_a, const int length_b)		   
//在这里a和b将被降阶为指针，等同与int *a, int *b。所以一定要传入数组的长度。
{
	int ia = 0, ib = 0;
	bool flag = false; //false : a; true : b;
	for ( ; ia < length_a || ib < length_b; ) {
		if ( a[ia] < b[ib] ) {  //如果a组的数值小，那么移动a的坐标
			if ( ia < length_a - 1) {
				flag = false;
				ia++;
			}
		} else if ( b[ib] < a[ia] ) {  //如果b组的数值小，那么移动b的坐标
			if ( ib < length_b - 1) {
				flag = true;
				ib++;
			}
		} else { //如果a和b的值一样大 
			cout <<a[ia] <<":" <<"a[" <<ia<<"]," <<"b[" <<ib <<"]" <<endl;  //打印相同的数值和坐标
			bool f = false;
			if ( ia < length_a-1 && a[ia] == a[ia+1] ) { //如果当前值和下一个值大小相等，那么挪动一下坐标
				ia++;
				f = true;
			}
			if ( ib < length_b-1 &&  b[ib] == b[ib+1] ) {
				ib++;
				f = true;
			}
			if (!f) { //如果前边没有挪动，就挪动被flag标记的数组。flag的原则是，首次使用先标记a，以后标记被挪动过的数组
				if (!flag && (ia < length_a - 1)) {
					ia++;
				}
				else if ( ib < length_b - 1 ) {
					ib++;
				}
			}
		}
		if ( (ia == length_a -1) && (a[ia] < b[ib]))
			break; 
		if ( ib == length_b - 1 && (b[ib] < a[ia]) )
			break;
		if ( ia == length_a -1 && ib == length_b -1 )
			break;
	}
}

int main(int argc, char **argv)
{
	int array_a[] = {1, 2, 2, 3, 3, 4, 7};
	int array_b[] = {2, 3, 3, 5, 7, 8};
	printSameNumInArray(array_a, array_b, sizeof(array_a) / sizeof(int), sizeof(array_b) / sizeof(int));
	cout <<endl;

	int array_c[] = {2, 2};
	int array_d[] = {2, 3, 3};
	printSameNumInArray(array_c, array_d, sizeof(array_c) / sizeof(int), sizeof(array_d) / sizeof(int));
	cout <<endl;

	int array_e[] = {3};
	int array_f[] = {3};
	printSameNumInArray(array_e, array_f, sizeof(array_e) / sizeof(int), sizeof(array_f) / sizeof(int));
	cout <<endl;

	//以下这种情况还是有错
	int array_g[] = {2, 2, 2, 10, 10};
	int array_h[] = {2, 3, 10, 10};
	printSameNumInArray(array_g, array_h, sizeof(array_g) / sizeof(int), sizeof(array_h) / sizeof(int));

	return 0;
}
