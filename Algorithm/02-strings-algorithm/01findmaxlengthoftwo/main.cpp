#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {

	char* stringa="abcdefasdasdasfadfa";
	char* stringb="abcuefandfasdfadfas";

	int la = strlen(stringa);
	int lb = strlen(stringb);

	int ab[la][lb];// = new int[la][lb];

	cout<<"length of a = " <<la <<" length of b = " <<lb <<endl;

	for (int i=0; i<la; i++) {
		for (int j=0; j<lb; j++) {
			if (stringa[i] != stringb[j]) {
				ab[i][j] = 0;
			} else {
				if (i == 0 || j == 0) {
					ab[i][j] = 1;
				} else {
					ab[i][j] = ab[i-1][j-1] + 1;
				}
			}
		}
	}


	int max = 0;
	int indexofa=0;
	int indexofb=0;
	for (int i=0; i<la; i++) {
		for (int j=0; j<lb; j++) {
			if (ab[i][j] > max)  {
				max = ab[i][j];
				indexofa = i; indexofb = j;
			}
		}
	}
	indexofa -= max - 1;
	indexofb -= max - 1;

	if(max != 0) {
		cout <<"max length string ";
		for (int i = indexofa; i<indexofa + max; i++) {
			cout <<stringa[i];
		}
		cout <<endl;
		cout <<"max length index in string a " <<indexofa <<endl;
		cout <<"max length index in string b " <<indexofb <<endl;
	} else 
		cout <<"max length string is NULL";

	return 0;
}
