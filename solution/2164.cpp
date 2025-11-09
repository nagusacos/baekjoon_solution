#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	queue<int> Q;
	for (int i = 1;i <= N;i++)
		Q.push(i);

	int temp;
	for (int i = 1;i<=N-1;i++) {
		Q.pop();
		temp = Q.front();
		Q.pop();
		Q.push(temp);
	}
	cout << Q.front();
}