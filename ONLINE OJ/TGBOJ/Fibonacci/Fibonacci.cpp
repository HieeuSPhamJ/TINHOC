#include<bits/stdc++.h>
using namespace std;
int a[100];
int fib(int n){
    if (n==0) return 0;
    if (n==1 or n==2) return 1;
    return fib(n-1)+fib(n-2);
}

int main(){
fill(a,a+100,-1);
int n;
cin>>n;
cout<<fib(n);
return 0;
}
