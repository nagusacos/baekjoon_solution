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