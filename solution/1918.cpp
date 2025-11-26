#include <iostream>
#include <string>
#include <stack>
using namespace std;

int order(char c) {
	if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '(' || c == ')')
		return -1;
	return 0;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;
	stack<pair<char, int>> S;
	S.push(make_pair('e', -1));
	for (const char &c : str) {
		int d = order(c);
		if (d != 0) {
			if (c == '(') {
				S.push(make_pair(c, d));
			}
			else if (c == ')') {
				for (;S.top().first != '(';) {
					cout << S.top().first;
					S.pop();
				}
				S.pop();
			}
			else {
				if (S.top().second < d)
					S.push(make_pair(c, d));
				else {
					for (;!S.empty() && S.top().second >= d;) {
						cout << S.top().first;
						S.pop();
					}
					S.push(make_pair(c, d));
				}
			}
		}
		else
			cout << c;
	}
	for (;S.top().first != 'e';) {
		cout << S.top().first;
		S.pop();
	}
}