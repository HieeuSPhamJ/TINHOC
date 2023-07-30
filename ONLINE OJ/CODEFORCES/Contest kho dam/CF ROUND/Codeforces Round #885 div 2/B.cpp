#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

multiset <int> adj[maxN];
int la[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= k; i++){
            adj[i].clear();
            la[i] = 0;
        }
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            adj[x].insert(i - la[x] - 1);
            la[x] = i;
        }
        for (int i = 1; i <= k; i++){
            adj[i].insert(n - la[i]);
            // cout << i << ": ";
            // for (auto x: adj[i]){
            //     cout << x << " ";
            // }
            // cout << endl;
        }
        int res = 1e18;

        for (int i = 1; i <= k; i++){
            // cout << "With: ";
            auto last = adj[i].end();
            last--;
            // cout << *last << " ";
            int te = (*last) / 2;
            adj[i].erase(last);
            if (adj[i].size()){
                // cout << *adj[i].rbegin();
                te = max(te, *adj[i].rbegin());
            }
            // cout << endl;
            res = min(res,te);
        }

        cout << res << endl;
    }
    return 0;
}