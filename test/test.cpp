#include <bits/stdc++.h>
using namespace std;

int a[10000];

int main(){
    int n;
    cin>>n;
    while(check(n)==False){
        n++;
    }
    cout<<n;
return 0;
}

