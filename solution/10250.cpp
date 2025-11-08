#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, H, W, num;
	cin >> N;
	cout.fill('0');
	for (int i = 0;i < N;i++) {
		cin >> H >> W >> num;
		cout << (num % H == 0 ? H : num % H);
		cout.width(2);
		cout << (num / H) + (num % H == 0 ? 0 : 1) << "\n";
	}
}