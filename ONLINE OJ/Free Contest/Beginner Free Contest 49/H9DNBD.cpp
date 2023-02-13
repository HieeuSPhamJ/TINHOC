#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

map <int,int> lists;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        lists[x]++;
    }

    int ans = 0;
    int cnt = 0;
    for (auto i: lists){
        if (i.se >= k){
            ans += i.fi;
            cnt++;
        }
    }
    cout << cnt << " " << ans;
    return 0;
}