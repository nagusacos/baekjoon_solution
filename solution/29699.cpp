#include <iostream>
#include <string>
using namespace std;

int main() {
	int A;
	string str = "WelcomeToSMUPC";
	cin >> A;
	cout << str[(A-1) % str.size()];
}