#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string A;
    //char C[102];
	for (;;) {
		getline(cin,A); //getline from <string>
        //cin.getline(C,101); //cin.getline from <iostream>
		if (cin.eof())
			break;
		cout << A << "\n";
	}
}

/*

*/
