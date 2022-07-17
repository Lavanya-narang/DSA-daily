#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0)
    {
        return 1;
    }
    
    int mn1=factorial(n-1);
    return mn1*n;
}
int main(){
    int n; cin>>n;
    cout<<factorial(n);
}
