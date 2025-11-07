#include <iostream>
using namespace std;

int main() {
	int S;
	cin >> S;
	cout << (S < 90 ? S < 80 ? S < 70 ? S < 60 ? "F" : "D" : "C" : "B" : "A");
}