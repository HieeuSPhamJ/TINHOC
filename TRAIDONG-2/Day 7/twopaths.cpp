#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e6 + 10;

int w[maxN];
vector <int> adj[maxN];
int single[2][maxN];
int done[2][maxN];
multiset <int> singles[maxN];
multiset <int> dones[maxN];
int father[maxN];
int res = 0;

void dfs(int nu, int fa){
    father[nu] = fa;
    single[0][nu] = done[0][nu] = w[nu];
    multiset <int> s;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs(i,nu);
        done[0][nu] = max(done[0][nu], done[0][i]);
        single[0][nu] = max(single[0][nu], single[0][i] + w[nu]);
        s.insert(single[0][i]);
        while(s.size() > 2){
            s.erase(s.begin());
        }
    }
    // cout << "With: " << nu << endl;
    // for (auto i: s){
    //     cout << i << " ";
    // }
    // cout << endl;
    done[0][nu] = max(done[0][nu], single[0][nu]);
    if (s.size() == 2){
        done[0][nu] = max(done[0][nu], *s.begin() + *s.rbegin() + w[nu]);
    }
}

void reroot(int nu, int fa){
    // cout << "With: " << nu << endl;
    if (nu != fa){
        multiset <int> s = singles[fa];
        s.insert(0);
        auto it = s.find(single[0][nu]);
        if (it != s.end()){
            s.erase(it);
        }
        if (fa != 1){
            multiset <int> ts;
            ts.insert(single[1][father[fa]]);
            // cout << '!' << " + " << single[1][father[fa]] << endl;
            for (auto i: singles[father[fa]]){
                ts.insert(i + w[father[fa]] );
                // cout << i << " + " << w[father[fa]] << endl;
            }
            if (ts.find(single[0][fa] + w[father[fa]]) != ts.end()){
                ts.erase(ts.find(single[0][fa] + w[father[fa]]));
            }
            if (ts.size()){
                s.insert(*ts.rbegin());
            }
        }
        if (s.size()){
            // for (auto i: s){
            //     cout << i << " ";
            // }
            // cout << endl;
            while (s.size() > 2){
                s.erase(s.begin());
            }   
            done[1][nu] = max(done[1][nu], *s.rbegin() + w[fa]);
            if (s.size() == 2){
                done[1][nu] = max(done[1][nu], *s.begin() + *s.rbegin() + w[fa]);
            }
            single[1][nu] = *s.rbegin() + w[fa] + w[nu];
            // cout << "s: " << single[1][nu] << endl;
        }
    }
    for (auto i: adj[nu]){
        if (i == fa){
            dones[nu].insert(done[1][nu]);
            continue;
        }
        // cout << i << " - " << single[0][i] << endl; 
        singles[nu].insert(single[0][i]);
        dones[nu].insert(done[0][i]);
        while(singles[nu].size() > 3){
            singles[nu].erase(singles[nu].begin());
        }
        while(dones[nu].size() > 2){
            dones[nu].erase(dones[nu].begin());
        }
        
    }
    // cout << "in " << nu << ": ";
    // for (auto i: singles[nu]){
    //     cout << i << " ";
    // }
    // cout << endl;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        reroot(i,nu);
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("twopaths.inp", "r")) {
        freopen("twopaths.inp", "r", stdin);
        freopen("twopaths.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }

    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,1);
    single[1][1] = w[1];
    reroot(1,1);

    for (int i = 1; i <= n; i++){
        if (i != 1){
            multiset <int> s = dones[father[i]];
            if (s.find(done[0][i]) != s.end()){
                s.erase(s.find(done[0][i]));
            }
            if (s.size()){
                done[1][i] = max(done[1][i], *s.rbegin());
            }
        }
        res = max(res, done[0][i] + done[1][i]);
        // cout << i << ": " << done[0][i] << " " << done[1][i] << endl;
    }

    cout << res << endl;
    return 0;
}