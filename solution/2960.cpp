#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> prime;
    prime.push_back(2);
    for (int n = 3; n <= N; n += 2)
    {
        bool is_prime = true;
        for (const int &p : prime)
        {
            if (p * p > n)
            {
                break;
            }
            if(n%p==0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            prime.push_back(n);
        }
    }

    bool arr[1001]{};
    for(const int &p : prime){
        for(int i=p;i<=N;i+=p){
            if(!arr[i]){
                arr[i] = true;
                K--;
                if(K<=0){
                    cout<<i;
                    return 0;
                }
            }
        }
    }
}