#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 110;

int n, m, l;
ii a[maxN];
int root[maxN];
int sz[maxN];
vector <int> ls[maxN];
ii d[]{
    {0,1},
    {1,0},
    {-1,0},
    {0,-1}
};

int findroot(int i){
    if (i == root[i]){
        return i;
    }
    return root[i] = findroot(root[i]);
}

int pre[maxN][maxN];
int grid[maxN][maxN];
int p[maxN];

bool check(int i, int j){
    if(i == n and j == n){
        return 1;
    }
    grid[i][j] = 1;
    bool res = 0;
    for (int di = 0; di < 4; di++){
        int ni = i + d[di].fi;
        int nj = j + d[di].se;
        if (min(ni,nj) < 0 or max(ni,nj) > n or grid[ni][nj] != 0){
            continue;
        }
        res = max(res,check(ni,nj));
    }
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> l;
    for (int i = 1; i <= m; i++){
        root[i] = i;
        sz[i] = 1;
        cin >> a[i].fi >> a[i].se;
    }

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= m; j++){
            if ((a[i].fi - a[j].fi) <= l and (a[i].se - a[j].se) <= l){
                int u = findroot(i);
                int v = findroot(j);
                if (u == v){
                    continue;
                }
                root[u] = v; 
                sz[v] += sz[u]; 
            }
        }
    }
    set <int> s;
    for (int i = 1; i <= m; i++){
        ls[findroot(i)].push_back(i);
    }
    vector <ii> ans;
    for (int tu = 1; tu <= m; tu++){
        memset(p,0,sizeof(p));
        memset(pre,0,sizeof(pre));
        for (auto i: ls[tu]){
            int x = a[i].fi;
            int y = a[i].se;
            pre[max(0ll, x - l)][max(0ll, y - l)] += 1;
            pre[max(0ll, x - l)][min(n + 1, y + l + 1)] -= 1;
            pre[min(n + 1, x + l + 1)][max(0ll, y - l)] -= 1;
            pre[min(n + 1, x + l + 1)][min(n + 1, y + l + 1)] += 1;
            // cout << max(0ll, x - l) << " " << max(0ll, y - l) << " " << min(n, x + l + 1) << " " << min(n, y + l + 1) << endl;
        }
        // cout << "Type: " << tu << endl;
        for (int i = 0; i <= n; i++){
            for (int j = 0, te = 0; j <= n; j++){
                te += pre[i][j];
                p[j] += te;
                grid[i][j] = p[j];
                // cout << grid[i][j] << " ";
            }
            // cout << endl;
        }
        int ok = check(0,0);
        // cout << ok << endl;
        if (!ok){
            for (auto x: ls[tu]){
                ans.push_back(a[x]);
            }
        }
    }
    cout << ans.size() << endl;
    for (auto i: ans){
        cout << i.fi << ' ' << i.se << endl;
    }
    return 0;
}