#include <iostream>
using namespace std;

int main() {
	int Y;
	cin >> Y;
	cout << (Y % 4 == 0 ? Y % 400 == 0 ? "1" : (Y % 100 == 0 ? "0" : "1") : "0");
}