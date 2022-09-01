#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
#define bua 1
#define keo 2
#define bao 3
using namespace std;

int a[4];
int b[4];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    cin >> a[bua] >> a[keo] >> a[bao];
    cin >> b[bua] >> b[keo] >> b[bao];
    int r,s,p;
    r= a[bua]-b[bua]-b[bao];
    s= a[keo]-b[keo]-b[bua];
    p= a[bao]-b[bao]-b[keo];
    
    int ans= max(r,s);
    ans = max(ans,p);
    if(ans<0){
        ans=0;
    }
    
    cout<<ans;
    return 0;
}