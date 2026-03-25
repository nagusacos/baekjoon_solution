#include <iostream>

int sup(int val,int a=0,int b,int* arr) {
	for (;a < b;) {
		int m = (a + b) >> 1;
		if (val <= arr[m])
			b = m;
		else
			a = m + 1;
	}
	return a;
}
int inf(int val,int a=0,int b,int* arr) {
	for (;a < b;) {
		int m = (a + b) >> 1;
		if (arr[m + 1] <= val)
			a = m + 1;
		else
			b = m;
	}
	return a;
}