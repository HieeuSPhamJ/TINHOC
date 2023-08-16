#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    vector<bool> nb;
    cin>>t;
    while(t--){
        cin>>n;
        nb=vector<bool>(n+1, 0);
        for(int i=1; i<=n; i++){
            for(int j=i; j<=n && !nb[j]; j*=2){
                cout<<j<<" ";
                nb[j]=1;
            }
        }
        cout<<endl;
    }
    return 0;
}