#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1510;

int n, m;
int a[maxN];
int b[maxN];

int bit[maxN][maxN];

void update(int i, int j, int v){
    int x = i;
    while(x <= n){
        int y = j;
        while(y <= m){
            bit[x][y] = max(bit[x][y], v);
            y += y & (-y);
        }
        x += x & (-x);
    }
}

int get(int i, int j){
    int x = i;
    int res = 0;
    while(x){
        int y = j;
        while(y){
            res = max(res, bit[x][y]);
            y -= y & (-y);
        }
        x -= x & (-x);
    }
    return res;
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i];
    }
    vector <pair<int,ii>> ls;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            bit[i][j] = 0;
            if (a[i] == b[j]){
                ls.push_back({a[i], {i,j}});
            }
        }
    }
    sort(all(ls));
    queue <pair<ii,ii>> q;
    int res = 0;
    for (auto i: ls){
        int w = i.fi;
        int x = i.se.fi;
        int y = i.se.se;
        while(q.size() and 2 * q.front().fi.fi <= w){
            pair<ii,ii> t = q.front();
            q.pop();
            update(t.se.fi, t.se.se, t.fi.se);
        }
        int cur = get(x - 1,y - 1) + 1;
        // cout << x << " " << y << " " << cur << endl;
        res = max(res, cur);
        q.push({{w,cur}, {x,y}});
    }
    cout << res << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
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