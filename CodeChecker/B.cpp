#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int L, H, test;
vector <ii> ask;

int cost(int x){
    int res = 0;
    while(x){
        if (x % 10 == 6 or x % 10 == 8){
            res++;
        }
        x /= 10;
    }
    return res;
}

namespace sub0{
    bool check(){
        if (ask.size() > 10){
            return 0;
        }
        if (H > 10){
            return 0;
        }
        for (auto i: ask){
            if (i.fi > 10){
                return 0;
            }
        }
        return 1;
    }  

    vector <int> adj[1010];

    int ok = 0;
    int n, k;

    vector <int> st;

    void backtrack(int id, int v){
        if (id == n){
            k--;
            if (k == 0){
                // cout << "RES: ";
                for (auto i: st){
                    cout << i << " ";
                }
                cout << endl;
                ok = 1;
            }
            return;
        }
        for (auto i: adj[v]){
            st.push_back(i);
            backtrack(id + 1, i);
            st.pop_back();
        }
    }

    void solve(){
        for (int i = L; i <= H; i++){
            for (int j = L; j <= H; j++){
                int ci = cost(i);
                int cj = cost(j);
                if (ci <= cj){
                    adj[i].push_back(j);
                }
            }
        }

        for (int i = L; i <= H; i++){
            adj[0].push_back(i);
        }

        for (auto i: ask){
            n = i.fi;
            k = i.se;
            ok = 0;
            backtrack(0,0);
            if (!ok){
                cout << -1 << endl;
            }
        }
    }
}

namespace sub14{
    bool check(){
        if (ask.size() > 1000){
            return 0;
        }
        if (H > 1000){
            return 0;
        }
        for (auto i: ask){
            if (i.fi > 1000){
                return 0;
            }
        }
        return 1;
    }  
    
    const int maxN = 1010;

    vector <int> adj[maxN];
    int dp[maxN][maxN];
    int n, k;
    int N;

    int dfs(int id, int v){
        int &res = dp[id][v];
        if (res != 0){
            return res;
        }
        if (id == N){
            // cout << id << " " << v << ": " << 1 << endl;
            return res = 1;
        }
        for (auto i: adj[v]){
            res += dfs(id + 1, i);
        }
        // cout << id << " " << v << ": " << res << endl;
        return res;
    }
    
    bool cmp(int a, int b){
        int ci = cost(a);
        int cj = cost(b);
        if (ci == cj){
            return a < b;
        }
        return ci < cj;
    }

    void solve(){
        for (int i = L; i <= H; i++){
            for (int j = L; j <= H; j++){
                int ci = cost(i);
                int cj = cost(j);
                if (ci <= cj){
                    // cout << i << " " << j << endl;
                    adj[i].push_back(j);
                }
            }
            // sort(all(adj[i]), cmp);
        }

        for (int i = L; i <= H; i++){
            adj[0].push_back(i);
        }
        for (auto i: ask){
            N = max(N, i.fi);
        }
        dfs(0,0);

        for (auto q: ask){
            n = N - q.fi + 1;
            k = q.se;
            vector <int> res;
            bool bad = 0;
            for (int i = n, v = 0; i <= N; i++){
                int s = 0;
                if (k == 0){
                    bad = 1;
                    break;
                }
                // cout << i << " " << v << ": " << endl; 
                for (auto x: adj[v]){
                    // cout << s << " " << x << " " << dp[i][x] << " " << k << endl;
                    if (s + dp[i][x] >= k){
                        k -= s;
                        v = x;
                        // cout << "#" << endl;
                        res.push_back(x);
                        goto bru;
                    }
                    s += dp[i][x];
                }
                bad = 1;
                break;
                bru:;
            }
            if (bad or (int)res.size() != q.fi){
                cout << -1 << endl;
            }
            else{
                for (auto i: res){
                    cout << i << " ";
                }
                cout << endl;
            }
        }
    }
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("incbeauty.inp", "r")) {
        freopen("incbeauty.inp", "r", stdin);
        freopen("incbeauty.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> L >> H >> test;
    for (int i = 1; i <= test; i++){
        int n, k;
        cin >> n >> k;
        ask.push_back({n,k});
    }

        sub14::solve();
    return 0;
}