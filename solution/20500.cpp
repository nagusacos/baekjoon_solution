#include <iostream>
using namespace std;

#define M 1000000007

long long dp[3][1520]{};

int main(){
    int N;
    cin>>N;
    dp[2][1] = 1;
    for(int i=2;i<=N;i++){
        dp[0][i] = (dp[1][i-1]+dp[2][i-1])%M;
        dp[1][i] = (dp[0][i-1]+dp[2][i-1])%M;
        dp[2][i] = (dp[0][i-1]+dp[1][i-1])%M;
    }
    cout<<dp[0][N];
}