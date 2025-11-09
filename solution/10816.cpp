#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	map<int, int> C;
	int temp;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> temp;
		C[temp]++;
	}
	cin >> M;
	cin >> temp;
	cout << C[temp];
	for (int i = 1;i < M;i++) {
		cin >> temp;
		cout << " " << C[temp];
	}
}