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

vector <int> adj[maxN];

int dep[maxN];
int lvl[maxN];

void getmdep(int nu, int fa){
    dep[nu] = 1;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        lvl[i] = lvl[nu] + 1;
        getmdep(i, nu);
        dep[nu] = max(dep[nu], dep[i] + 1);
    }
}

unordered_set <int> sto[maxN];

int ans = 0;

void dfs(int nu, int fa){
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs(i,nu);
    }

    // cout << "With: " << nu << endl;

    vector <int> ls;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        ls.push_back(dep[i] + lvl[nu]);
    }
    // cout << "ls: ";
    // for (auto i: ls){
    //     cout << i << " ";
    // }
    // cout << endl;

    if (ls.size() == 1){
        int t1 = ls.front();
        dep[nu] = 2; 
    }
    else if(ls.size() == 2){
        int t1 = ls.front();
        int t2 = ls.back();
        if (t1 != t2){
            dep[nu] = min(t1,t2) - lvl[nu] + 2; 
        }
    }

    // cout << "dep: " << dep[nu] << endl;
}

void setdep(int nu, int fa){
    if (dep[nu] <= 0){
        ans++;
    }
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dep[i] = min(dep[i],dep[nu] - 1);
        setdep(i, nu);
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    lvl[1] = 1;
    getmdep(1,1);

    dfs(1,1);

    setdep(1,1);
    
    // for (int i = 1; i <= n; i++){
    //     cout << i << ": " << dep[i] << endl;
    // }

    cout << ans << endl;

    return 0;
}