#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (;T-- > 0;) {
		int X, Y;
		cin >> X >> Y;

		char DSLR[10001]{ 0, };
		int order[10001]{ 0, };
		int Q[10002]{ 0, };
		int q = 0;

		char command[4] = { 'D','S','L','R' };

		Q[q++] = X;
		DSLR[Q[0]] = 0;
		order[Q[0]] = 1;
		for (int n = 0;n < q;n++) {
			int calculate[4] = { (Q[n] * 2) % 10000 ,(Q[n] - 1 < 0 ? 9999 : Q[n] - 1),(Q[n] % 1000) * 10 + (Q[n] / 1000),(Q[n] / 10) + (Q[n] % 10) * 1000 };
			for (int i = 0;i < 4;i++) {
				if (order[calculate[i]] <= 0) {

					Q[q] = calculate[i];

					order[Q[q]] = order[Q[n]] + 1;
					DSLR[Q[q]] = command[i];

					if (Q[q] == Y) {
						n = q;
						break;
					}
					q++;
				}
			}
		}

		char* value = new char[order[Q[q]] + 1];
		int len = 0;

		for (int pre = Q[q];pre != X;) {
			value[len++] = DSLR[pre];

			if (DSLR[pre] == 'D') {
				pre /= 2;
				if (order[pre] <= 0 || order[pre] >= order[pre * 2])
					pre += 5000;
			}
			else if (DSLR[pre] == 'S') {
				pre += 1;
				if (pre > 9999)
					pre = 0;
			}
			else if (DSLR[pre] == 'L') {
				pre = (pre / 10) + (pre % 10) * 1000;
			}
			else if (DSLR[pre] == 'R') {
				pre = (pre % 1000) * 10 + (pre / 1000);
			}
		}
		len--;
		for (;len >= 0;)
			cout << value[len--];
		cout << "\n";

		delete[] value;
	}
}//This code is about twice as fast. It is a more efficient code in reverse tracking.



//first solution
/*
#include <iostream>
#include <queue>
using namespace std;

char DSLR[10001][200];//200 is upper bound of DSLR command length(just assumtion)

void command_add(const int &value, const int &current,const int &len,const char &cmd) {
	for (int i = 0;i < len;i++)
		DSLR[value][i] = DSLR[current][i];
	DSLR[value][len] = cmd;
	DSLR[value][len + 1] = '\0';
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int k = 0;k < N;k++) {
		int start, end;
		cin >> start >> end;

		int len[10001]{ 0, };
		queue<int> Q;
		Q.push(start);

		int current;
		for (;!Q.empty();) {
			current = Q.front();
			Q.pop();

			int D = (current * 2) % 10000;
			int S = (current - 1 < 0 ? 9999 : current - 1);
			int L = (current * 10) % 10000 + (current / 1000);
			int R = current / 10 + (current % 10) * 1000;
			//cout << current << "=>" << D << " " << S << " " << L << " " << R << "\n";
			if (len[D] == 0 && D!=start) {
				len[D] = len[current] + 1;
				command_add(D, current, len[current], 'D');
				Q.push(D);
				if (D == end)
					break;
			}
			if (len[S] == 0 && S != start) {
				len[S] = len[current] + 1;
				command_add(S, current, len[current], 'S');
				Q.push(S);
				if (S == end)
					break;
			}
			if (len[L] == 0 && L != start) {
				len[L] = len[current] + 1;
				command_add(L, current, len[current], 'L');
				Q.push(L);
				if (L == end)
					break;
			}
			if (len[R] == 0 && R != start) {
				len[R] = len[current] + 1;
				command_add(R, current, len[current], 'R');
				Q.push(R);
				if (R == end)
					break;
			}
		}
		cout << DSLR[end];
		cout << "\n";
	}
}
*/
