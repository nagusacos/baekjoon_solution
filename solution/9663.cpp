#include <iostream>
using namespace std;

int N;
unsigned int U[16]{};
unsigned int F = 0;
bool oob(int i, int j)
{
	return i < 0 || N <= i || j < 0 || N <= j;
}
void fill_diag(int i, int j)
{
	for (int k = 0;; k++)
	{
		if (oob(i + k, j + k))
			break;
		U[i + k] |= (1 << (j + k));
	}
	for (int k = 0;; k++)
	{
		if (oob(i + k, j - k))
			break;
		U[i + k] |= (1 << (j - k));
	}
}
int queen(int q, int N)
{
	if (N - q <= 0)
		return 1;

	unsigned int M[16]{};
	for (int l = q; l < N; l++)
		M[l] = U[l];

	int sum = 0;
	for (int k = 0; k < N; k++)
	{
		if ((F & (1 << k)) || (U[q] & (1 << k)))
			continue;
		F |= (1 << k);
		fill_diag(q, k);
		sum += queen(q + 1, N);

		F &= ~(1 << k);
		for (int l = q; l < N; l++)
			U[l] = M[l];
	}
	return sum;
}
void print()//debug
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << ((U[i] & (1 << j)) > 0);
		}
		cout << "\n";
	}
	cout << "---------\n";
}

int main()
{
	cin >> N;
	cout << queen(0, N);
	return 0;
}
