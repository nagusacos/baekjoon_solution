#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, D;
	cin >> N >> D;
	deque<pair<int, long long>> pre_max;
	pre_max.push_back(make_pair(-(1 << 30), 0));
	long long maximum = -(1 << 30);
	for (int i = 1;i <= N;i++) {
		long long temp;
		cin >> temp;

		long long cur_max = temp;
		if (i - pre_max.front().first > D)
			pre_max.pop_front();
		if (!pre_max.empty())
			cur_max = max(cur_max, pre_max.front().second + temp);
		for (;!pre_max.empty() && pre_max.back().second <= cur_max;)
			pre_max.pop_back();
		pre_max.push_back(make_pair(i, cur_max));

		if (cur_max > maximum)
			maximum = cur_max;
	}
	cout << maximum;
}