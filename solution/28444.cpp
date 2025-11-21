#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int H, I, A, R, C;
	cin >> H >> I >> A >> R >> C;
	cout << H * I - A * R * C;
}
