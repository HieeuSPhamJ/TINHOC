#include <bits/stdc++.h>
using namespace std;

long long n,k;
bool counta[1000000001];

int main() {
    freopen("COIN.INP","r",stdin);
    freopen("COIN.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        long long inp;
        cin>>inp;
        counta[inp]=1;
    }
    long long ans=0;
    for (int i=1;i<=1000000001;i++){
        if (i>k){
            break;
        }
        if (counta[i]==0){
            ans++;
            counta[i]=1;
            k-=i;
        }
    }
    cout<<ans;
    return 0;
}