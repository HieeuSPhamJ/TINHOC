#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("TRUCNHAT.INP","r",stdin);
    freopen("TRUCNHAT.OUT","w",stdout);
    long long n,m,k;
    cin>>n>>m>>k;
    cout<<min((n+m-k)/5,min(n/3,m/2));
    return 0;
}
