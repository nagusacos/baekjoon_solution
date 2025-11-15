#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	set<string> S;

	int N, M;
	cin >> N >> M;

	string term;
	for (int i = 0;i < N;i++) {
		cin >> term;
		S.insert(term);
	}
	vector<string> L;
	for (int i = 0;i < M;i++) {
		cin >> term;
		if (S.find(term) != S.end())
			L.push_back(term);
	}
	sort(L.begin(), L.end());
	cout << L.size() << "\n";
	for (string str : L)
		cout << str << "\n";
}