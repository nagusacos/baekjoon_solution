#include <iostream>
using namespace std;

int main() {
    int A[3];
    int S[3] = { -1,-1,-1 };
    for (int i = 0;i < 3;i++)
        cin >> A[i];
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            if (A[i] == A[j])
                S[j]++;
    int sum = 0;
    int score = 0;
    for (int i = 0;i < 3;i++) {
        score += S[i]*A[i];
        sum += S[i];
    }
    if(sum<=0)
        cout << max(max(A[0], A[1]), A[2]) * 100;
    else {
        score /= sum;
        if (sum >= 6)
            cout << (10000 + score * 1000);
        else
            cout << (1000 + score * 100);
    }
}
