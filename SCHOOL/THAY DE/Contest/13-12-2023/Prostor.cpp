#include "bits/stdc++.h"
#define int long long
// #define double long double
#define ii pair<int, int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxK = 1010;

const int mxn = 100010;
const int m = 3;
int n;
int a[mxn][m], b[mxn][m];
int bit[maxK][maxK];
vector<pair<int, pair<ii, ii>>> ls[maxK];

void update(int x, int y, int ls){
    while (x < maxK){
        int t = y;
        while (t < maxK){
            bit[x][t] += ls;
            t += t & -t;
        }
        x += x & -x;
    }
}

int get(int x, int y){
    int res = 0;
    while (x){
        int t = y;
        while (t){
            res += bit[x][t];
            t -= t & -t;
        }
        x -= x & -x;
    }
    return res;
}

signed main(){
    // freopen("input.INP", "r", stdin);
    // freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")){
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
        for (int j = 0; j < m; j++){
            cin >> b[i][j];
            if (a[i][j] > b[i][j])
                swap(a[i][j], b[i][j]);
        }
    }

    int res = 0;
    for (int t = 0; t < m; t++){
        for (int i = 1; i < maxK; i++)
            ls[i].clear();
        for (int i = 0; i < n; i++){
            for (int j = 0; j <= t; j++){
                if (a[i][j] == b[i][j]){
                    pair<ii, ii> p = {{a[i][1], a[i][2]}, {b[i][1], b[i][2]}};
                    ls[a[i][0]].push_back({1 + j, p});
                    ls[b[i][0] + 1].push_back({-1 - j, p});
                }
            }
            rotate(a[i], a[i] + m - 1, a[i] + m);
            rotate(b[i], b[i] + m - 1, b[i] + m);
        }
        for (int i = 1, f = 0; i < maxK; i++){
            sort(ls[i].begin(), ls[i].end(), [](pair<int, pair<ii, ii>> x, pair<int, pair<ii, ii>> y)
                 { return (x.fi < 0) != (y.fi < 0) ? x.fi < y.fi : x.fi > y.fi; });
            for (pair<int, pair<ii, ii>> j : ls[i]){
                int x = j.fi;
                res += !~-x * f, f += x / abs(x);
            }
        }
        for (int s = 0; s < 4; s++){
            for (int i = 1; i < maxK; i++){
                for (pair<int, pair<ii, ii>> &j: ls[i]){
                    int x = j.fi;
                    pair<ii, ii> &p = j.se;
                    if (!~-x){
                        res += get(p.fi.fi - 1, p.fi.se - 1) - get(p.fi.fi - 1, maxK - 1);
                    }
                    update(p.se.fi, p.se.se, x / abs(x));
                    swap(p.fi.fi, p.fi.se);
                    swap(p.se.fi, p.se.se);
                    swap(p.fi.fi, p.se.fi);
                    p.fi.fi = maxK - p.fi.fi, p.se.fi = maxK - p.se.fi;
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}