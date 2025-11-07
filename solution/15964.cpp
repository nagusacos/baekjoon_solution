#include <iostream>
using namespace std;

#define MACRO_FUNCTION(a,b) (a+b)*(a-b)

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	long long int A, B;
	cin >> A >> B;
	cout << MACRO_FUNCTION(A, B);
}
