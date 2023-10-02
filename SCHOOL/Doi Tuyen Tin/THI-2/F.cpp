#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e6 + 10;

map <ii,int> color;
vector <ii> adj[maxN];

void add(int a, int b, int w){
    adj[a].push_back({b,w});
    adj[b].push_back({a,w});
    color[{a,b}] = w;
    color[{b,a}] = w;
}

void solve(){
    int n;
    cin >> n;
    color.clear();
    for (int i = 1; i <= n; i++){
        adj[i].clear();
    }
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        int w = c - '0';
        if (i == n){
            add(n, 1, w);
        }
        else{
            add(i, i + 1, w);
        }
    }
    for (int i = 1; i <= n - 3; i++){
        int a, b, w;
        cin >> a >> b >> w;
        add(a,b,w);
    }
    int ok = 1;
    for (int t = 1; t <= n; t++){
        sort(rall(adj[t]));
        vector <ii> fis;
        while(adj[t].size() and adj[t].back().fi < t){
            fis.push_back(adj[t].back());
            adj[t].pop_back();
        }
        reverse(all(adj[t]));
        for (auto i: fis){
            adj[t].push_back(i);
        }
        // cout << t << ": " << endl;
        // for (auto i: adj[t]){
        //     cout << i.fi << ' ';
        // }
        // cout << endl;

        for (int i = 1; i < (int)adj[t].size(); i++){
            ii le = adj[t][i];
            ii re = adj[t][i - 1];
            int mid = color[{le.fi,re.fi}];
            if (mid == 0){
                cout << -1 << endl;
                // cout << "neispravna triangulacija" << endl;
                return;
            }
            set <int> ss;
            ss.insert(le.se);
            ss.insert(re.se);
            ss.insert(mid);
            if (ss.size() != 3){
                ok = 0;
            }
        }
    }
    // if (ok){
    //     cout << "tocno" << endl;
    // }
    // else{
    //     cout << "neispravno bojenje" << endl;
    // }
    cout << ok << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}