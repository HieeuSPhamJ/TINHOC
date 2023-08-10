#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define iii pair<ii,int>
using namespace std;

const int maxN = 2e5 + 10;

int n, m, k;
vector <ii> adj[maxN];
vector <int> oneadj[maxN];
vector <int> ls;
bool mk[maxN];
ii vis[maxN];
set <int> res;
int child[maxN];
int dp[maxN];
int last[maxN];
bool OK = 1;

struct compare{
    bool operator()(iii a, iii b){
        if (a.fi.fi == b.fi.fi){
            return a.fi.se < b.fi.se;
        }
        return a.fi.fi > b.fi.fi;
    }
};

void dickcha(int s){
    for (int i = 1; i <= n; i++){
        vis[i] = {1e18,0};
    }
    priority_queue <iii,vector <iii>, compare> q;
    q.push({{0,mk[s]},s});
    vis[s] = {0,mk[s]};
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        if (t.fi != vis[t.se]){
            continue;
        }
        // cout << "With: " << t.se << "," << t.fi.se << ": ";
        for (auto i: adj[t.se]){
            ii nw = t.fi;
            nw.fi += i.fi;
            nw.se += mk[i.se];
            if (nw.fi < vis[i.se].fi){
                // cout << i.se << "," << nw.se << " ";
                vis[i.se] = nw;
                q.push({nw,i.se});
                continue;
            }
            if (nw.fi == vis[i.se].fi){
                vis[i.se].se = max(vis[i.se].se, nw.se);
                continue;
            }
        }
        // cout << endl;
    }

    for (int i = 1; i <= n; i++){
        // cout << i << ": " << vis[i].fi << ' ' << vis[i].se << endl;
        if (vis[i].se == k){
            res.insert(i);
        }
    }
}

void get(int nu, int fa){
    res.insert(nu);
    for (auto i: oneadj[nu]){
        if (i == fa){
            continue;
        }
        get(i,nu);
    }
}

void dfs(int nu, int fa){
    // cout << nu << endl;
    dp[nu] = mk[nu];
    child[nu] = 1;
    if (mk[nu]){
        last[nu] = nu;
    }
    vector <int> lsa;
    for (auto i: oneadj[nu]){
        if (i == fa){
            continue;
        }
        dfs(i,nu);
        dp[nu] += dp[i];
        child[nu] += child[i];
        if (last[i]){
            last[nu] = last[i];
        }
        if (dp[i]){
            lsa.push_back(i);
        }
    }
    // cout << nu << ": " << dp[nu] << " " << lsa.size() << endl;
    if (lsa.size() > 2){
        cout << 0 << endl;
        exit(0);
    }
    if (dp[nu] == 1 and mk[nu] == 1){
        // cout << nu << ": " << dp[nu] << endl;
        get(nu,fa);
    }
    if (lsa.size() == 2){
        // cout <<"end in: " << nu << endl;
        if (dp[nu] == k){
            cout << res.size() << endl;
            for (auto i: res){
                cout << i << " ";
            }
            cout << endl;
            exit(0);
        }
    }
}

int gogo(int nu, int fa){
    // cout << nu << endl;
    res.insert(nu);
    if (mk[nu]){
        return nu;
    }
    for (auto i: oneadj[nu]){
        if (i == fa){
            continue;
        }
        if (dp[i]){
            return gogo(i,nu);
        }
    }
    return 0;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k; 
    if (k == 1){
        cout << n << endl;
        for (int i = 1; i <= m; i++){
            cout << i << " ";
        }
        cout << endl;
        return 0;
    }
    if (n * (n + m) * log2(n) <= 3e8){
        for (int i = 1; i <= k; i++){
            int x;
            cin >> x;
            ls.push_back(x);
            mk[x] = 1;
        }

        for (int i = 1; i <= m; i++){
            int x, y, w;
            cin >> x >> y >> w;
            adj[x].push_back({w,y});
            adj[y].push_back({w,x});
        }

        for (int i = 1; i <= n; i++){
            dickcha(i);
        }
        // dickcha(1);

        cout << res.size() << endl;

        for (auto i: res){
            cout << i << " ";
        }
        cout << endl;
    }
    else if (n - 1 == m){
        for (int i = 1; i <= k; i++){
            int x;
            cin >> x;
            ls.push_back(x);
            mk[x] = 1;
        }

        for (int i = 1; i <= m; i++){
            int x, y, w;
            cin >> x >> y >> w;
            oneadj[x].push_back(y);
            oneadj[y].push_back(x);
            // cout << x << " " << y << endl;
        }
        dfs(1,1);
        int t = gogo(1,1);
        int fa = -1;
        for (auto i: oneadj[t]){
            if (dp[i] + 1 == dp[t]){
                fa = i;
                continue;
            }
        }
        // cout << t << " " << fa << endl;
        get(t,fa);
        cout << res.size() << endl;
        for (auto i: res){
            cout << i << " ";
        }
        cout << endl;
        // for (int i = 1; i <= n; i++){
        //     cout << i << ": " << last[i] << " " << child[i] << ' ' << dp[i] << endl;
        // }
    }
    else{
        cout << 0 << endl;
    }

    return 0;
}