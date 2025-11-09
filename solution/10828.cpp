#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	stack<int> S;
	for (int i = 0;i < N;i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int temp;
			cin >> temp;
			S.push(temp);
		}
		else if (str == "pop") {
			if (S.empty())
				cout << "-1\n";
			else {
				cout << S.top() << "\n";
				S.pop();
			}
		}
		else if (str == "size") {
			cout << S.size() << "\n";
		}
		else if (str == "empty") {
			cout << S.empty() << "\n";
		}
		else if (str == "top") {
			if (S.empty())
				cout << "-1\n";
			else
				cout << S.top() << "\n";
		}
	}
}