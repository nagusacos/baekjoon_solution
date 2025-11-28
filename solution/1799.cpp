#include <iostream>
using namespace std;

//12:00

int N, D;
int di[25]{};
int dj[25]{};
int dc[25]{};
unsigned int F[12];

/*void print() {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (F[i] & (1 << j))
				cout << 1;
			else
				cout << 0;
		}
		cout << "\n";
	}
	cout << "-----\n";
}*/

bool oob(int i, int j) {
	return i < 0 || N <= i || j < 0 || N < j;
}

unsigned int  fill_diag(int i,int j) {
	unsigned int diag_save = 0;
	for (int k = 1;!oob(i + k, j + k); k++) {
		if (F[i + k] & (1 << (j + k)))
			diag_save |= (1 << k);
		F[i + k] &= ~(1 << (j + k));
	}
	return diag_save;
}

void recover_diag(int i, int j,unsigned int diag_save) {
	for (int k = 1;!oob(i + k, j + k); k++) {
		if (diag_save & (1 << k))
			F[i + k] |= (1 << (j + k));
		else
			F[i + k] &= ~(1 << (j + k));
	}
}

int f(int d) {//diagonal, to right bottom 
	//cout << "call: " << d << "\n";
	if (d >= D) {
		if(d == D)
			return (bool)(F[N - 1] & (1 << (N - 1)));
		return 0;
	}
	int maximum = 0;
	for (int k = 0;k < dc[d];k++) {
		int i = di[d] - k;
		int j = dj[d] + k;
		if (F[i] & (1 << j)) {
			unsigned int save = fill_diag(i, j);
			//cout << "take: " << i << ", " << j << "\n";
			//print();
			maximum = max(f(d + 2) + 1, maximum);
			recover_diag(i, j, save);
		}
	}
	//cout << "take: none at" << d << '\n';
	maximum = max(f(d + 2), maximum);
	return maximum;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			bool temp;
			cin >> temp;
			if (temp)
				F[i] |= (1 << j);
		}
	}

	int i = 0;
	int k = 1;
	for (;k < N;k++) {
		di[i] = i;
		dc[i] = k;
		i++;
	}
	for (;k >= 1;k--) {
		di[i] = N - 1;
		dj[i] = i - N + 1;
		dc[i] = k;
		i++; 
	}
	D = i - 1;

	cout << f(0) + (N > 1 ? f(1) : 0);
}