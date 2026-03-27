#include <iostream>
#include <vector>
using namespace std;

vector<long long> prime;

long long power(long long n, int k)
{
    if (k <= 0)
        return 1;
    long long a = power(n, k >> 1);
    a *= a;
    if (k & 1)
        a *= n;
    return a;
}

void get_prime(int maximum = 32000)
{
    prime.push_back(2);
    for (int n = 3; n <= maximum; n += 2)
    {
        bool is_prime = true;
        for (const int &p : prime)
        {
            if (p * p > n)
                break;
            if (n % p == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            prime.push_back(n);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    get_prime();

    for (;;)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        if (n == 1)
        {
            cout << 0 << "\n";
            continue;
        }
        long long phi = 1;
        for (const long long &p : prime)
        {
            if (p * p > n)
                break;

            int k = 0;
            for (; n % p == 0;)
            {
                k++;
                n /= p;
            }
            if (k != 0)
                phi *= (power(p, k) - power(p, k - 1));
        }
        if (n != 1)
            phi *= (n - 1);
        cout << phi << "\n";
    }
}