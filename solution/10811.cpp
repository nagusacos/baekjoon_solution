#include <iostream>
using namespace std;

int N, M;
int num[101]{};

void reverse(int i,int j) {
	int a = i;
	int b = j;
	for (;a < b;)
		swap(num[a++], num[b--]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	
	cin >> N >> M;
	for (int i = 1;i <= N;i++)
		num[i] = i;

	for (int i = 0;i < M;i++) {
		int A, B;
		cin >> A >> B;
		reverse(A, B);
	}
	cout << num[1];
	for (int i = 2;i <= N;i++)
		cout << " " << num[i];
}
