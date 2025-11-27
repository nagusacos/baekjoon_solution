#include <iostream>
using namespace std;

void print(bool A[32]) {
	for (int i = 31;i >= 0;i--)
		cout << A[i];
	cout << "\n";
	return;
}
void print(unsigned int bit_A) {
	for (int i = 31;i >= 0;i--)
		cout << (bool)(bit_A & (1 << i));
	cout << "\n";
	return;
}
unsigned int bitcount(unsigned int bit_A) {
	if (bit_A == 0) return 0;
	return (bit_A & 1) + bitcount(bit_A >> 1);
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cout << "declare\n";
	bool A[32]{};
	unsigned int bit_A = 0;

	print(A);
	print(bit_A);



	cout << "append\n";
	A[5] = true;
	bit_A |= (1 << 5);

	print(A);
	print(bit_A);



	cout << "delete\n";
	A[5] = false;
	bit_A &= ~(1 << 5);

	print(A);
	print(bit_A);



	cout << "toggle\n";
	A[5] = !A[5];
	bit_A ^= (1 << 5);

	print(A);
	print(bit_A);



	cout << "check\n";
	cout << A[5] << "\n";
	cout << (bool)(bit_A & (1 << 5)) << "\n";



	cout << "zero init\n";
	for (int i = 0;i < 32;i++)
		A[i] = false;
	bit_A = 0;

	print(A);
	print(bit_A);



    cout << "full to 5\n";
	for (int i = 0;i < 5;i++)
		A[i] = true;
	bit_A = ((1 << 5) + ~0);

	print(A);
	print(bit_A);



	cout << "full init\n";
	for (int i = 0;i < 32;i++)
		A[i] = true;
	bit_A = ~0;

	print(A);
	print(bit_A);

    

    



	cout << "-------------------\n";

	unsigned int bit_B = 0;
	unsigned int bit_C = 0;

	bit_B |= (1 << 1) | (1 << 2) | (1 << 4) | (1 << 5) | (1 << 7);
	bit_C |= (1 << 2) | (1 << 3) | (1 << 4) | (1 << 6);

	print(bit_B);
	print(bit_C);

	cout << "union\n";
	print(bit_B | bit_C);

	cout << "intersection\n";
	print(bit_B & bit_C);

	cout << "difference\n";
	print(bit_B & (~bit_C));//B-C
	print(bit_C & (~bit_B));//C-B

	cout << "symmetric difference\n";
	print(bit_B ^ bit_C);

	cout << "set size\n";
	cout << bitcount(bit_B) << "\n";
	cout << bitcount(bit_C) << "\n";

	cout << "first element\n";
	print((bit_B & (~bit_B + 1)));
	print((bit_C & (~bit_C + 1)));

	cout << "first delete\n";
	print((bit_B & (bit_B + ~0)));
	print((bit_C & (bit_C + ~0)));

	cout << "first toggle\n";
	print((bit_B ^ (~bit_B + 1)));
	print((bit_C ^ (~bit_C + 1)));

	cout << "all subset\n";
	for (unsigned int subset = bit_B; subset; subset = ((subset + ~0) & bit_B))
		print(subset);
}
