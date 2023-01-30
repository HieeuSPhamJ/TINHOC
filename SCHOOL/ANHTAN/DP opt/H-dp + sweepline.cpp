#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int n, k;
int a[maxN];
int pre[maxN];
int seg[maxN * 4];
int dp[maxN];
int lazy[maxN * 4];

void setLazy(int i){
    int val = lazy[i];
    lazy[2 * i] += val;
    lazy[2 * i + 1] += val;
    seg[2 * i] += val;
    seg[2 * i + 1] += val;
    lazy[i] = 0;
}


void update0(int i, int left, int right, int _left, int _right, int val){
    if (right < _left or _right < left){
        return;
    }
    if (_left <= left and right <= _right){
        seg[i] += val;
        lazy[i] += val;
        return;
    }
    setLazy(i);
    int mid = (left + right) / 2;

    update0(2 * i, left, mid, _left, _right, val);
    update0(2 * i + 1, mid + 1, right, _left, _right, val);
    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
}

int gett(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return 0;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }
    setLazy(i);
    int mid = (left + right) / 2;

    int t1 = gett(2 * i, left, mid, _left, _right);
    int t2 = gett(2 * i + 1, mid + 1, right, _left, _right);
    return max(t1,t2);
}
void update(int i, int j, int v){
    i = max(i,1ll);
    if (i > j){
        return;
    }
    update0(1,1,n,i,j,v);
}


int get(int l, int r){
    l = max(l,1ll);
    if (l > r){
        return 0;
    }
    return gett(1,1,n,l,r);
}

int sum(int l, int r){
    if (l <= 1){
        return pre[r];
    }
    return pre[r] - pre[l - 1];
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = 1, maxLast = 0; i <= n; i++){
        if (i - k >= 0){
            maxLast = max(maxLast, dp[i - k]);
        }
        // cout << "With: " << i << endl;
        dp[i] = max(dp[i], maxLast + sum(i - k + 2,i));
        // cout << maxLast << " " << sum(i - k + 1, i) << endl;
        update(i - k, i - 2, a[i]);
        // cout << "UP " << i - k << " " << i - 2 << " " << a[i] << endl;
        // for (int i = 1; i <= n; i++){
        //     cout << get(i,i) << " ";
        // }
        // cout << endl;

        dp[i] = max(dp[i], get(i - k, i - 2));
        // cout << i - k << " " << i - 2 << " " << get(i - k, i - 2) << endl;
        // cout << dp[i] << endl;
        update(i,i,dp[i]);
        ans = max(ans, dp[i]);
    }


    // for (int i = 1; i <= n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;


    cout << ans << endl;



    return 0;
}