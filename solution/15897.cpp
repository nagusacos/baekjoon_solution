//not solved
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long sum = n;
    int i=2;
    for(;i<=((n-1)>>1);i++){
         int a = ((n - 1) / i + 1);
         sum+=a;
    }
    for (; i <= n;)
    {
        int a = ((n - 1) / i + 1);
        if(a==2){
            sum+=(n-i)*2+1;
            break;
        }
        int b = max(1, i * i / (n - i));//jump
        sum += a * b;
        i += b;
        for (;i <= n;)
        {
            int val = ((n - 1) / i + 1);
            if (a != val)
                break;
            sum += val;
            i++;
        }
    }
    cout << sum;
}