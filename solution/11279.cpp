#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	priority_queue<int> Q;

	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;
		if (temp <= 0) {
			if (Q.empty())
				cout << "0\n";
			else {
				cout << Q.top() << "\n";
				Q.pop();
			}
		}
		else
			Q.push(temp);
	}
}