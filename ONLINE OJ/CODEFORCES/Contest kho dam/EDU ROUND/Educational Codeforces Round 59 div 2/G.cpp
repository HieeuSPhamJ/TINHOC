#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
// #define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3 * 1e5 + 10;

int n, k;
int a[maxN];
int d[maxN];
int dp[maxN][2];
int prefix[maxN], suffix[maxN];
int segma[maxN * 4];
int segmi[maxN * 4];
int far[maxN][2];

void updatesu(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        segma[i] = val;
        return;
    }
    int mid = (left + right) / 2;

    updatesu(2 * i, left, mid, index, val);
    updatesu(2 * i + 1, mid + 1, right, index, val);
    segma[i] = min(segma[2 * i], segma[2 * i + 1]);
}

int getsu(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return 1e18;
    }
    if (_left <= left and right <= _right){
        return segma[i];
    }

    int mid = (left + right) / 2;

    int t1 = getsu(2 * i, left, mid, _left, _right);
    int t2 = getsu(2 * i + 1, mid + 1, right, _left, _right);
    return min(t1, t2);
}

void updatepre(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        segmi[i] = val;
        return;
    }
    int mid = (left + right) / 2;

    updatepre(2 * i, left, mid, index, val);
    updatepre(2 * i + 1, mid + 1, right, index, val);
    segmi[i] = min(segmi[2 * i], segmi[2 * i + 1]);
}

int getpre(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return 1e18;
    }
    if (_left <= left and right <= _right){
        return segmi[i];
    }

    int mid = (left + right) / 2;

    int t1 = getpre(2 * i, left, mid, _left, _right);
    int t2 = getpre(2 * i + 1, mid + 1, right, _left, _right);
    return min(t1, t2);
}

void updatePre(int i, int v){
    updatepre(1,1,n,i,v);
}

void updateSu(int i, int v){
    updatesu(1,1,n,i,v);
}

int getPre(int l, int r){
    if (l <= 0){
        return min(0ll,getPre(1,r));
    }
    if (r < 1){
        return 0;
    }
    return getpre(1,1,n,l,r);
}

int getSu(int l, int r){
    l = max(1ll, l);
    if (l > n){
        return 0;
    }
    r = min(r, n + 1);
    return getsu(1,1,n,l,r);
}

signed main(){
    // freopen("input.inp", "r", stdin);
    // freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    
    int ans = 0;

    for (int i = 1; i <= n; i++){
        int x;
        cin >> x >> a[i];
        a[i] = k - a[i];
        d[i] += x;
        d[i + 1] -= x;
        prefix[i] = prefix[i - 1] + a[i];
        updatePre(i,prefix[i]);
        ans = max(ans, a[i]);
        far[i][0] = far[i][1] = i;
    }

    for (int i = n; i >= 1; i--){
        suffix[i] = suffix[i + 1] + a[i];
        updateSu(i,suffix[i]);
    }

    d[1] = 1e18;
    d[n + 1] = 1e18;
    far[n + 1][1] = n + 1;

    // for (int i = 2; i <= n; i++){
    //     cout << d[i] << " ";
    // }
    // cout << endl;

    for (int i = 2; i <= n; i++){
        while(d[far[i][0] - 1] <= d[i]){
            far[i][0] = far[far[i][0] - 1][0];
        }
    }
    for (int i = n; i >= 2; i--){
        while(d[far[i][1] + 1] <= d[i]){
            far[i][1] = far[far[i][1] + 1][1];
        }
    }
    // cout << "===0===" << endl; 
    for (int i = 2; i <= n; i++){
        // cout << i << ": " << endl;
        int res = -(d[i] * d[i]);
        int f = far[i][0] - 1;
        // cout << res << " " << f - 1 << " " << i - 1 << endl; 
        res += prefix[i] - getPre(f - 1,i - 1);
        // cout << res << endl;
        dp[i][0] = res;
    }

    // cout << "===1===" << endl;
    for (int i = n - 1; i >= 1; i--){
        // cout << i << ": " << endl;
        int res = -(d[i + 1] * d[i + 1]);
        int f = far[i][1] + 1;
        // cout << res << " " << i + 2 << " " << f + 1 << endl;
        res += suffix[i] - getSu(i + 2, f + 1);
        // cout << res << endl;
        dp[i][1] = res;
    }

    dp[n][1] = a[n] - d[n] * d[n];

    for (int i = 2; i <= n; i++){
        // cout << i << ": " << dp[i][0] << " " << dp[i][1] << " " << dp[i][0] + dp[i][1] - a[i] + min(d[i] * d[i], d[i + 1] + d[i + 1]) << endl;
        ans = max(ans,dp[i][0]);
        ans = max(ans,dp[i][1]);
        ans = max(ans, dp[i][0] + dp[i][1] - a[i] + min(d[i] * d[i], d[i + 1] + d[i + 1]));
    }

    cout << ans << endl;

    return 0;
}