#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;

void get_prime(int bound) {
	prime.push_back(2);
	for (int n = 3;n <= bound;n += 2) {
		bool is_prime = true;
		for (const int& p : prime) {
			if (p * p > n)
				break;
			if (n % p == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime)
			prime.push_back(n);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	
	get_prime(3200);
	
	int N;
	cin >> N;
	
	for (int i = 0;i < N;i++) {
		int K;
		cin >> K;

		int arr[32];
		int idx = 0;
		for (const int& p : prime) {
			for (;K % p == 0;K /= p)
				arr[idx++] = p;
			if (p * p > K)
				break;
		}
		if (K != 1)
			arr[idx++] = K;
		
		cout << arr[0];
		for (int i = 1;i < idx;i++)
			cout << " " << arr[i];
		cout << "\n";
	}
}

/*
//not my code. this code is better. (by 2015152)

#include <iostream>
#include <vector>

using namespace std;

vector<int> buildSPF(int n) {
    vector<int> spf(n + 1);
    for (int i = 0; i <= n; i++) spf[i] = i;

    for (int i = 2; (long long)i * i <= n; i++)
        if (spf[i] == i)                 
            for (int j = i * i; j <= n; j += i)
                if (spf[j] == j)         
                    spf[j] = i;
    return spf;
}

void factorize(int n, const vector<int>& spf) {
    while (n > 1) {
        cout << spf[n] << " ";
        n /= spf[n];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> spf = buildSPF(5000000);
    
    while(n--){
        int k;
        cin >> k;
        factorize(k, spf);
    }
    return 0;
}


*/