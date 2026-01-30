#include <iostream>
using namespace std;

int main(){
    int A,B,T;
    cin>>A>>B>>T;
    B+=T;
    A+=B/60;
    B%=60;
    A%=24;
    cout<<A<<" "<<B;
}