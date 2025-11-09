#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int* A = new int[N + 1];
	map<int, int> G;
	int temp;
	for (int i = 0;i < N;i++) {
		cin >> A[i];
		G[A[i]] = 0;
	}

	int sum = 0;
	for (auto iter = G.begin();iter != G.end();iter++)
		iter->second = sum++;

	cout << G[A[0]];
	for (int i = 1;i < N;i++) {
		cout << " " << G[A[i]];
	}
}
