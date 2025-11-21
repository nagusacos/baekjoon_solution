#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int N, A, B;
	cin >> N >> A >> B;
	cout << (A > max(B, N) ? "Subway" : A < max(B, N) ? "Bus" : "Anything");
}