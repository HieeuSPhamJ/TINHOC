#include<bits/stdc++.h>
using namespace std;

int main(){
    // freopen("Snail.inp","r",stdin);
    // freopen("Snail.out","w",stdout);
    long long a,b,s;
    cin>>a>>b>>s;
    if (a==s) cout<<1;
    else{
        // if (!((s-b)%(a-b))) cout<<(s-b)/(a-b);
        // else cout<<(s-b)/(a-b)+1;
        cout<<(s-b)/(a-b)+bool((s-b)%(a-b));
    }
    return 0;
}