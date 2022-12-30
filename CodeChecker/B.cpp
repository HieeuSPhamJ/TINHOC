#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <ii> lists;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        lists.push_back({x,i});
    }

    sort(lists.begin(), lists.end());
    
    int mi = 1e18;
    int ans = -1;
    for (auto i: lists){
        if (mi > i.se){
            mi = min(mi, i.se);
            continue;
        }
        ans = max(ans, i.se - mi);
        mi = min(mi, i.se);
    }

    cout << ans;
    return 0;
}