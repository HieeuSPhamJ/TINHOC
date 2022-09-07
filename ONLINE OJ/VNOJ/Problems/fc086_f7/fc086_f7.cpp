#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

ii a[300010];

bool cmp(ii x, ii y){
    return x.first > y.first;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; i++){
        int n;
        
    }

    return 0;
}