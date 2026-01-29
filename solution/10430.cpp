#include <iostream>
using namespace std;

int main(){
    int A,B,C;
    cin>>A>>B>>C;
    int a = (A+B)%C;
    int b = (A*B)%C;
    int c = ((A%C)*(B%C))%C;
    cout<<a<<"\n"<<a<<"\n"<<b<<"\n"<<c<<"\n";
}