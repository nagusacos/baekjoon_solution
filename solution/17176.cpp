#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int F[53]{};
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;
		F[temp]++;
	}
	{
		cin.ignore();
		char temp[100001];
		cin.getline(temp, 100001, '\n');
		for (int i = 0;i < N;i++) {
			if((int)temp[i]==32)
				F[0]--;
			else if((int)temp[i] <=90)
				F[(int)temp[i] - 64]--;
			else 
				F[(int)temp[i] - 70]--;
		}
	}
	for (int i = 0;i < 53;i++) {
		if (F[i] != 0) {
			cout << "n";
			return 0;
		}
	}
	cout << "y";
	return 0;
}