#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 1e9 + 7;

 int n, m;
int dp[1010][10010];
int seg[1010][40010];

void update(int t, int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        (seg[t][i] += val) %= mod;
        return;
    }
    int mid = (left + right) / 2;

    update(t, 2 * i, left, mid, index, val);
    update(t, 2 * i + 1, mid + 1, right, index, val);
    seg[t][i] = (seg[t][2 * i] + seg[t][2 * i + 1]) % mod;
}

int get(int t, int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return 0;
    }
    if (_left <= left and right <= _right){
        return seg[t][i] % mod;
    }

    int mid = (left + right) / 2;

    int t1 = get(t, 2 * i, left, mid, _left, _right);
    int t2 = get(t, 2 * i + 1, mid + 1, right, _left, _right);
    return (t1 + t2) % mod;
}

int get(int t, int l, int r){
    l++;
    r++;
    return get(t,1,1,m + 1,l,r);
}

void update(int t, int i, int v){
    i++;
    update(t, 1, 1, n + 1, i, v);
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> n >> m;
    dp[1][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            for (int k = 0; k <= i; k++){
                (dp[i + 1][j + k] += dp[i][j]) %= mod;
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}
/*
12
*/