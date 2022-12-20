#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[110];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int res = -1;
    int ans = 1e18;
    vector <int> lists;
    for (int s = 1; s <= a[n]; s++){
        int tans = 0;
        for (int i = 1; i <= n; i++){
            tans += abs(a[i] - s);
        }
        if (tans < ans){
            ans = tans;
            res = s;
            lists.clear();
        }
        if (tans == ans){
            lists.push_back(s);
        }
    }
    cout << res << " " << ans << endl;
    return 0;
}