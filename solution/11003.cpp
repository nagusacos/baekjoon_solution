#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	deque<pair<int, int>> D;

	int N, L;
	cin >> N >> L;
	int A;
	cin >> A;
	cout << A;
	D.push_back(make_pair(1, A));
	for (int i = 2; i <= N; i++) {
		cin >> A;
		if (D.front().first < i - L + 1)
			D.pop_front();
		for (;!D.empty();) {
			if (D.back().second >= A)
				D.pop_back();
			else
				break;
		}
		D.push_back(make_pair(i, A));
		cout << " " << D.front().second;
	}
}