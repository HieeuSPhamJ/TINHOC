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

const int maxN = 310;
const int inf = 1e18;

int n, m, k;
vector <ii> adj[maxN];
int dp[maxN][maxN];
int pre[maxN][maxN];
// int precheo[maxN][maxN];

struct seg{
    int seg[maxN * 4];

    void update(int i, int left, int right, int index, int val){
        if (index < left or right < index){
            return;
        }
        if (left == right){
            seg[i] = val;
            return;
        }
        int mid = (left + right) / 2;

        update(2 * i, left, mid, index, val);
        update(2 * i + 1, mid + 1, right, index, val);
        seg[i] = min(seg[2 * i], seg[2 * i + 1]);
    }

    int get(int i, int left, int right, int _left, int _right){
        if (right < _left or _right < left){
            return inf;
        }
        if (_left <= left and right <= _right){
            return seg[i];
        }

        int mid = (left + right) / 2;

        int t1 = get(2 * i, left, mid, _left, _right);
        int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
        return min(t1, t2);
    }
    void update(int i, int v){
        update(1,1,n,i,v);
    }
    int get(int l, int r){
        return get(1,1,n,l,r);
    }
} precheo[maxN];

void print(int n){
    cout << "dp" << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= n; j++){
            if (dp[i][j] >= 1e18){
                cout << "i ";
                continue;
            }
            cout << dp[i][j] << " ";

        }
        cout << endl;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("vaduong.inp", "r")) {
        freopen("vaduong.inp", "r", stdin);
        freopen("vaduong.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int l, r, c;
        cin >> l >> r >> c;
        adj[r].push_back({l,c});
    }

    memset(dp, 0x3f, sizeof(dp));
    memset(pre, 0x3f, sizeof(pre));
    // memset(precheo, 0x3f, sizeof(precheo));
    dp[0][0] = 0;
    int res = 1e18;

    for (int i = 0; i <= n; i++){
        for (int j = 1; j <= 4 * n; j++){
            precheo[i].update(j,inf);
        }
    }
    for (int i = 1; i <= n; i++){
        if (i >= 2){
            for (int g = 0; g <= n; g++){
                pre[i - 1][g] = min(pre[i - 2][g], dp[i - 1][g]);
                if (i - 1 - g >= 0){
                    precheo[i - 1 - g].update(i - 1, dp[i - 1][g]);
                }
            }
        }
        // cout << "With: " << i - 1 << endl;
        // print(n);

        for (auto e: adj[i]){
            int j = e.fi;
            int w = e.se;
            dp[i][i - j + 1] = min(dp[i][i - j + 1], w);
        }
        for (int g = 1; g <= i; g++){
            for (auto e: adj[i]){
                int j = e.fi;
                int w = e.se;
                int len = i - j + 1;
                dp[i][g] = min(dp[i][g], pre[j - 1][g - len] + w);
                dp[i][g] = min(dp[i][g], precheo[i - g].get(j,i) + w);
                // cout << "====" << endl;
                // for (;j <= i; j++){
                //     if (g - (i - j + 1) < 0){
                //         continue;
                //     }
                //     cout << j - 1 << " " << g - (i - j + 1) << endl;
                //     dp[i][g] = min(dp[i][g], dp[j - 1][g - (i - j + 1)] + w);
                // }
            }
            // cout << i << " " << g << ": " << dp[i][g] << endl;
            if (g >= k){
                res = min(res, dp[i][g]);
            }
        }
    }
    if (res == 1e18){
        cout << -1 << endl;
        return 0;
    }
    cout << res << endl;
    return 0;
}

/*
dp[i][k]: thang cuoi bi phu la i, min cost de xay k thang
    = dp[j][k - cost[i][j]]
*/