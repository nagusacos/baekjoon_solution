#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int A[100001];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	
	for (int k = 0;k < T;k++) {
		string command;
		cin >> command;

		int N;
		cin >> N;

		string str;
		cin >> str;

		int sum = 0;
		int x = 0;
		for (int i = 1;i < str.size() - 1;i++) {
			if (str[i] == ',') {
				A[x++] = sum;
				sum = 0;
			}
			else {
				sum *= 10;
				sum += (int)str[i] - 48;
			}
		}
		if (N != 0)
			A[x++] = sum;

		int i = 0, j = N - 1;
		bool state = true;
		bool error = false;
		for (const char& c : command) {
			if (c == 'R') {
				state = !state;
			}
			else {
				if (i>j) {
					error = true;
					break;
				}
				if (state)
					i++;
				else
					j--;
			}
		}

		if (error)
			cout << "error\n";
		else if (i > j)
			cout << "[]\n";
		else {
			if (state) {
				cout << "[" << A[i++];
				for (;i<=j;) {
					cout << "," << A[i++];
				}
				cout << "]\n";
			}
			else {
				cout << "[" << A[j--];
				for (;i <= j;) {
					cout << "," << A[j--];
				}
				cout << "]\n";
			}
		}
	}
}