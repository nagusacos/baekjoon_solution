#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	bool S[21]{ false, };
	string str;
	int temp;
	for (int i = 0;i < N;i++) {
		cin >> str;
		if (str == "add") {
			cin >> temp;
			S[temp] = true;
		}
		else if (str == "remove") {
			cin >> temp;
			S[temp] = false;
		}
		else if (str == "check") {
			cin >> temp;
			cout << S[temp] << "\n";
		}
		else if (str == "toggle") {
			cin >> temp;
			S[temp] = !S[temp];
		}
		else if (str == "all") {
			for (int i = 1;i <= 20;i++)
				S[i] = true;
		}
		else {
			for (int i = 1;i <= 20;i++)
				S[i] = false;
		}
	}
}