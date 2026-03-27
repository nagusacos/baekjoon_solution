#include <iostream>
using namespace std;

#define bound 1000000

int mpf[bound + 1]{}; // minimum prime factor

void init_mpf(int maximum = bound)
{
    mpf[1] = 1;
    int n = 2;
    for (; n * n <= maximum; n++)
    {
        if (mpf[n] == 0)
        {
            mpf[n] = n;
            for (int i = n * n; i <= maximum; i += n)
                if (mpf[i] == 0)
                    mpf[i] = n;
        }
    }
    for (; n < maximum; n++)
        if (mpf[n] == 0)
            mpf[n] = n;
}

long long factor_sum(int n)
{
    long long pre = 0;
    long long q = 1;
    long long sum = 1;
    for (; n > mpf[n]; n /= mpf[n])
    {
        if (pre != mpf[n])
        {
            sum *= q;
            pre = mpf[n];
            q = 1 + pre;
        }
        else
        {
            q *= pre;
            q += 1;
        }
    }

    if (pre != mpf[n])
    {
        sum *= q;
        pre = mpf[n];
        q = 1 + pre;
    }
    else
    {
        q *= pre;
        q += 1;
    }
    sum *= q;

    return sum;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    init_mpf();

    long long g[bound + 1]{};
    g[1] = 1;
    for (int i = 2; i <= bound; i++)
    {
        g[i] = g[i - 1] + factor_sum(i);
    }

    int T;
    cin >> T;
    for (; T-- > 0;)
    {
        int N;
        cin >> N;
        cout << g[N] << "\n";
    }
}