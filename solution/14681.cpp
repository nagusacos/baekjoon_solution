#include <iostream>
using namespace std;

int main() {
	int X,Y;
	cin >> X >> Y;
	cout << (Y > 0 ? (X > 0 ? "1" : "2") : (X < 0 ? "3" : "4"));
}