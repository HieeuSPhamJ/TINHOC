#include<bits/stdc++.h>
using namespace std;

char temp[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};


void Conv(long long n,int a){
    if (n>0){
        Conv(n/a,a);
        cout<<temp[n%a];
    }
}


int main(){
    freopen("DOICOSO.INP","r",stdin);
    freopen("DOICOSO.OUT","w",stdout);
    long long n;
    int a;
    cin>>n>>a;
    Conv(n,a);
    return 0;
}