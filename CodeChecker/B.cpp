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

const int maxN = 110;

int a[maxN];
vector <pair<ii,int>> ts;
int res = 0;
int mk[maxN];
int tres = 0;
int k;
// vector <int> les;
void backtrack(int id){
    if (id >= ts.size()){
        // if (res < tres){
        //     cout << tres << endl;
        //     for (auto i: les){
        //         cout << ts[i].fi.fi << " " << ts[i].fi.se << endl;
        //     }
        // }
        res = max(res,tres);
        return;
    }
    backtrack(id + 1);
    auto cur = ts[id];
    if (mk[cur.fi.fi] or mk[cur.fi.se] or k - abs(cur.fi.fi - cur.fi.se) < 0){
        return;
    }
    k -= abs(cur.fi.fi - cur.fi.se);
    tres += cur.se;
    mk[cur.fi.fi] = 1;
    mk[cur.fi.se] = 1;
    // les.push_back(id);
    // cout << "add " << cur.fi.fi << " " << cur.fi.se << endl;
    backtrack(id + 1);
    // les.pop_back();
    // cout << "era " << cur.fi.fi << " " << cur.fi.se << endl;
    k += abs(cur.fi.fi - cur.fi.se);
    tres -= cur.se;
    mk[cur.fi.fi] = 0;
    mk[cur.fi.se] = 0;
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("DEBT.inp", "r")) {
        freopen("DEBT.inp", "r", stdin);
        freopen("DEBT.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, l, r;
    cin >> n >> l >> r >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector <int> ls;
    for (int i = 1; i <= n; i++){
        if (i < l or r < i){
            ls.push_back(i);
        }
    }
    for (int i = l; i <= r; i++){
        for (auto j: ls){
            if (a[i] - a[j] > 0){
                ts.push_back({{i,j}, a[i] - a[j]});
            }
            
        }
    }

    backtrack(0);

    res = -res;

    for (int i = l; i <= r; i++){
        res += a[i];
    }

    cout << res << endl;

    return 0;
}

/*
dp[i][j][k]
dp[i - 1][l][k]


4 5 3 1 2 6

3

4 0 4
4 1 3
4 2 2
4 3 1
5 0 5
5 1 4
5 2 3
5 3 2
6 0 6
6 1 5
6 2 4
6 3 3

*/