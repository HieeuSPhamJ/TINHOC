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
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int x, n;
        cin >> x >> n;
        int l = 1;
        int r = n;
        int res = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            int t = cal(mid)
        }
        cout << res << endl;
    }
    return 0;
}