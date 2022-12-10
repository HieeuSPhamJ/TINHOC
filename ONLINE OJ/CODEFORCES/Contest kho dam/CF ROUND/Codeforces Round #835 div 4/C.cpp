#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2 * 1e5 + 10;

int ans[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector <ii> a;
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;
            a.push_back({inp, i});
        }
        sort(all(a));
        for (int i = 0; i < n - 1; i++){
            ans[a[i].se] = a[i].fi - a.back().fi;
        }
        ans[a.back().se] = a.back().fi - a[n - 2].fi;
        for (int i = 1; i <= n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}