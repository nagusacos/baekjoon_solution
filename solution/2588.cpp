#include <iostream>
using namespace std;

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int A,B;
    cin>>A>>B;
    for(int i=10;i<=1000;i*=10){
        cout<<A*((B%i)/(i/10))<<"\n";
    }
    cout<<A*B;
}