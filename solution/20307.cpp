#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long integer;

void debug(integer** system, int N,int M) {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cout << system[i][j] << " ";
		}
		cout << "\n";
	}
}
integer gcd(integer A,integer B) {
	if (A > B) swap(A, B);
	for (;A > 0;A %= B) swap(A, B);
	return B;
}
integer lcm(integer A, integer B) {
	return A * B / gcd(A, B);
}

void del(integer** system, int M, int from, int to, int identity = 0) {
	integer a = system[from][identity];
	integer b = system[to][identity];
	if (b == 0)
		return;
	for (int j = 0;j < M;j++)
		system[to][j] = a * system[to][j] - b * system[from][j];
}
void change(integer** system, int M, int a, int b, int identity = 0) {
	for (int j = identity;j < M;j++)
		swap(system[a][j], system[b][j]);
}
void div(integer** system, int M, int a, int identity = 0) {
	integer d = abs(system[a][identity]);
	for (int j = identity;j < M;j++)
		d = gcd(d, abs(system[a][j]));
	if(d>1)
		for (int j = identity;j < M;j++)
			system[a][j] /= d;
}

void solve(integer** system, int N, int M) {
	int identity = 0;
	vector<int> id;
	for (int i = 0;i < N && identity < M;i++, identity++) {
		if (system[i][identity] == 0) {
			bool found = false;
			for (;identity < M;identity++) {
				for (int j = i;j < N;j++) {
					if (system[j][identity]) {
						found = true;
						change(system, M, i, j, identity);
						//cout << "change===\n";
						//debug(system, N, M);
						break;
					}
				}
				if (found)
					break;
			}
			if (!found)
				break;
			
		}
		div(system, M, i, identity);
		for (int j = i + 1;j < N;j++)
			del(system, M, i, j, identity);
		id.push_back(identity);

		//cout << i << ": identitiy=" << identity << " ===>\n";
		//debug(system, N, M);
	}
	for (int i = id.size() - 1;i >= 0;i--) {
		div(system, M, i, id[i]);
		for (int j = i - 1;j >= 0;j--)
			del(system, M, i, j, id[i]);
		//cout << i << ": identitiy=" << id[i] << " del===>\n";
		//debug(system, N, M);
	}
	//cout << "===end===\n";
	//debug(system, N, M);
	//cout << "===\n";


	int i = 0;
	for (;i < id.size();i++) {
		integer a = system[i][id[i]];
		for (int j = 0;j < M;j++) {
			integer d = gcd(abs(a), abs(system[i][j])) * (a > 0 ? 1 : -1);
			cout << system[i][j] / d;
			if (d != a)
				cout << "/" << a / d;
			if (j != M - 1)
				cout << " ";
		}
		cout << "\n";
	}
	for (;i < N;i++) {
		for (int j = 0;j < M - 1;j++)
			cout << "0 ";
		cout << "0\n";
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	
	integer** system = new integer*[N];

	integer* p = new integer[M];
	integer* q = new integer[M];
	for (int i = 0;i < N;i++) {
		system[i] = new integer[M];
		integer d = 1;
		for (int j = 0;j < M;j++) {
			string temp;
			cin >> temp;
			string::iterator iter = find(temp.begin(), temp.end(), '/');
			if (iter != temp.end()) {
				string a(temp.begin(), iter);
				string b(iter + 1, temp.end());
				p[j] = stoi(a);
				q[j] = stoi(b);
			}
			else {
				p[j] = stoi(temp);
				q[j] = 1;
			}
			d = lcm(d, abs(q[j]));
		}
		for (int j = 0;j < M;j++)
			system[i][j] = p[j] * (d / q[j]);
	}
	//cout << "===\n";
	//debug(system, N, M);
	//cout << "===\n";
	solve(system, N, M);
}

/*
5 5
8/9 9/8 9/7 9/5 8/3
-8/9 9/8 9/7 9/5 8/3
-8/9 -9/8 9/7 9/5 8/3
-8/9 -9/8 -9/7 9/5 8/3
-8/9 -9/8 -9/7 -9/5 8/3


5 5
1/9 1/9 1/9 1/9 9
-1/9 1/9 1/9 1/9 9
-1/9 -1/9 1/9 1/9 9
-1/9 -1/9 -1/9 1/9 9
-1/9 -1/9 -1/9 -1/9 9

4 5
0 0 0 0 0
1 0 0 1 2
0 2 0 2 6
0 1 2 1 3

4 5
0 0 0 0 0
1/7 0 0 1/7 2/7
0 1/3 0 1/3 1
0 1/6 1/3 1/6 1/2

5 5
0 0 0 0 0
1 0 0 1 2
0 0 0 0 0
0 2 0 2 6
0 1 2 1 3

8 5
1 0 0 1 2
0 0 0 0 0
0 2 0 2 6
0 0 0 0 0
0 0 0 0 0
0 1 2 1 3
0 0 0 0 0
0 0 0 0 0

4 5
0 0 0 0 0
1 0 0 1 2
0 2 0 2 6
0 1 2 1 3
4 5
0 0 0 0 0
1 0 0 1 2
0 2 0 2 6
0 1 2 1 3


4 5
1 2 3 4 5
1 4 2 4 2
2 3 4 2 1
2 3 4 0 2

3
4 8 7 1427
10 7 1 1206
1 9 10 1582

*/

