#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int D[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	string M[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	int X, Y;
	cin >> X >> Y;
	int day = Y;
	for (int i = 1;i < X;i++)
		day += D[i];
	cout << M[day % 7];
}
