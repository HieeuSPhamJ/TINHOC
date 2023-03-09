#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 500010;

int n;
ii a[maxN];

int cal(){
    int ans = 1e18;
    
    multiset <int> low,up;

    for (int i = 1; i <= n; i++){
        up.insert(a[i].se);
    }

    for (int i = 1; i <= n; i++){
        // cout << "With: " << i << endl;
        ii now = a[i];
        
        while(up.size() and *up.begin() < now.fi){
            // cout << "move " << *up.begin() << endl;
            low.insert(*up.begin());
            up.erase(up.begin());
        }

        if (up.find(now.se) != up.end()){
            // cout << "era in up " << now.se << endl;
            up.erase(up.find(now.se));
        }
        if (low.find(now.se) != low.end()){
            // cout << "era in low " << now.se << endl;
            low.erase(low.find(now.se));
        }

        if (up.size()){
            ans = min(ans, *up.rbegin() - now.fi);
        }
        
        // for (auto x: low){
        //     cout << x << " ";
        // }
        // cout << endl;
        // for (auto x: up){
        //     cout << x << " ";
        // }
        // cout << endl;

        if (now.se < now.fi){
            low.insert(now.se);
        }
        else{
            up.insert(now.se);
        }
    }
    return ans;
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i].fi >> a[i].se;
        }

        sort(a + 1, a + 1 + n);

        int ans = cal();

        for (int i = 1; i <= n; i++){
            swap(a[i].fi, a[i].se);
        }
        sort(a + 1, a + 1 + n);

        ans = min(ans, cal());

        cout << ans << endl;
    }
    return 0;
}