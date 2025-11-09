#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	map<int, bool> A;
	int N, M;
	cin >> N;
	int temp;
	for (int i = 0;i < N;i++) {
		cin >> temp;
		A[temp] = true;
	}
	cin >> M;
	for (int i = 0;i < M;i++) {
		cin >> temp;
		cout << A[temp] << "\n";
	}
}

//using hash map

/*
#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	unordered_map<int, bool> A;
	int N, M;
	cin >> N;
	int temp;
	for (int i = 0;i < N;i++) {
		cin >> temp;
		A[temp] = true;
	}
	cin >> M;
	for (int i = 0;i < M;i++) {
		cin >> temp;
		cout << A[temp] << "\n";
	}
}
*/