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

<<<<<<< HEAD
struct node{
    int p1,p2,p3,p4;
};

bool maximize(int &a, int b){
    if (a < b){
        a = b;
        return 1;
    }
    return 0;
}

bool minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
}

int a[110][110];
ii id[110][110];
vector <ii> adj[210][110];

int Hash(node x){
    int ha = x.p1;
    ha *= 1000;
    ha += x.p2;
    ha *= 1000;
    ha += x.p3;
    ha *= 1000;
    ha += x.p4;
    return ha;
}

node deHash(int x){
    node res;
    res.p4 = x % 1000;
    x /= 1000;
    res.p3 = x % 1000;
    x /= 1000;
    res.p2 = x % 1000;
    x /= 1000;
    res.p1 = x % 1000;
    return res;
}

void print(node x, char en = endl){
    cout << x.p1 << " " << x.p2 << " " << x.p3 << " " << x.p4 << en;
=======
int dp[310][310];
int a[310];

int cal(int l, int r){
    int &res = dp[l][r];
    if (res != -1){
        return res;
    }

    if (l >= r){
        return res = 0;
    }
    if (r - l == 1){
        if (abs(a[l] - a[r]) <= 1){
            return res = 2;
        }
        else{
            return res = 0;
        }
    }

    if (abs(a[l] - a[r]) <= 1 and cal(l + 1, r - 1) == r - l - 1){
        res = r - l + 1;
        // cout << l << " " << r << " " << res << endl;
    }   

    for (int i = l; i < r; i++){
        res = max(res, cal(l, i) + cal(i + 1, r));
    }
    // cout << l << " " << r << " " << res << endl;
    return res;
>>>>>>> 1c3fc3d43b04e0ee5a2fdac54a286c985133144b
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
<<<<<<< HEAD
    if (fopen("input.inp", "r")) {
        freopen("input.inp", "r", stdin);
        freopen("A.out", "w", stdout);
=======
    if (fopen("daruma.inp", "r")) {
        freopen("daruma.inp", "r", stdin);
        freopen("daruma.out", "w", stdout);
>>>>>>> 1c3fc3d43b04e0ee5a2fdac54a286c985133144b
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
<<<<<<< HEAD
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    int cntlay = 1;
    for (int i = 1; i <= n; i++){
        int x = i;
        int y = 1;
        for (int cnt = 1;x >= 0 and y <= m; x--, y++){
            id[x][y] = {cnt, cntlay};
            cnt++;
        }
        cntlay++;
    }

    for (int i = 2; i <= m; i++){
        int x = n;
        int y = i;
        for (int cnt = 1; x >= 0 and y <= m; x--, y++){
            id[x][y] = {cnt, cntlay};
            cnt++;
        }
        cntlay++;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (i + 1 <= n){
                // cout << id[i][j].se << " " << id[i][j].fi << " " << id[i + 1][j].fi << endl;
                adj[id[i][j].se][id[i][j].fi].push_back({a[i + 1][j], id[i + 1][j].fi});
            }
            if (j + 1 <= m){
                // cout << id[i][j].se << " " << id[i][j].fi << " " << id[i][j + 1].fi << endl;
                adj[id[i][j].se][id[i][j].fi].push_back({a[i][j + 1], id[i][j + 1].fi});
            }
        }
    }

    cntlay--;
    unordered_map<int, int> cur;
    unordered_map<int, int> dp;
    cur[Hash({1,1,1,1})] = a[1][1];
    set <ii> s;
    // node tmp = deHash(Hash({1,1,1,1}));
    // cout << tmp.p1 << " " << tmp.p2 << " " << tmp.p3 << " " << tmp.p4 << endl;
    for (int lay = 1; lay < cntlay; lay++){
        for (auto x: cur){
            node t = deHash(x.fi);
            int dist = x.se;
            // cout << "With: " << lay << " ";
            // print(t, ':');
            // cout << " " << dist << endl;
            for (auto d1: adj[lay][t.p1]){
            for (auto d2: adj[lay][t.p2]){
            for (auto d3: adj[lay][t.p3]){
            for (auto d4: adj[lay][t.p4]){
                int nu = Hash({d1.se, d2.se, d3.se, d4.se});
                s.clear();
                s.insert(d1);
                s.insert(d2);
                s.insert(d3);
                s.insert(d4);
                int co = dist;
                for (auto i: s){
                    // cout << i.se << " " << i.fi << endl;
                    co += i.fi;
                }
                // cout << "---" << endl;
                // print(deHash(nu));
                // cout << co << endl;
                maximize(dp[nu], co);
            }   
            }   
            }   
            }
        }
        swap(cur, dp);
        dp.clear();
    }

    cout << cur[Hash({1,1,1,1})] << endl;

=======
    while(1){
        memset(dp,-1,sizeof(dp));
        int n;
        cin >> n;
        if (n == 0){
            return 0;
        }
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        cout << cal(1,n) << endl;
    }
>>>>>>> 1c3fc3d43b04e0ee5a2fdac54a286c985133144b
    return 0;
}