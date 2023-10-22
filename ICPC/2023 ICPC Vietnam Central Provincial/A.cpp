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

const int maxN = 1e5 + 10;

int a[maxN];
int dp[maxN];
int far[maxN];

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
    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
}

int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return -1e18;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return max(t1, t2);
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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        update(1,1,n,i,a[i]);
    }


    for (int i = n; i >= 1; i--){
        dp[i] = a[i];
        far[i] = i;
        if (i < n and dp[i + 1] + a[i] > dp[i]){
            dp[i] = dp[i + 1] + a[i];
            far[i] = far[i + 1];
        }
    }
    int res = -1e18;
    for (int i = 1; i <= n; i++){
        // cout << dp[i] << " " << far[i] << endl;
        res = max(res, dp[i] - get(1,1,n,i,far[i]));
    }

    cout << res << endl;


    return 0;
}

/*
6 -5 7 3 -2
1 2
-5 2
7 3
1 5
-2 5
*/