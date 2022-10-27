#include<bits/stdc++.h>
#define int long long
#define pair <int,int>
#define fi first
#define se second
#define endl '\n'

using namespace std;

const int maxN = 2 * 1e5 + 10;
const int inf = 1e18;

int a[maxN];
int dp[maxN];

int seg[maxN * 4];
int segDP[maxN * 4];

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

int get(int i, int left, int right, int L, int R){
    if (right < L or R < left){
        return inf;
    }
    if (L <= left and right <= R){
        return seg[i];
    }
    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, L, R);
    int t2 = get(2 * i + 1, mid + 1, right, L, R);
    return min(t1, t2);
}

void updateDP(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        segDP[i] = val;
        return;
    }
    int mid = (left + right) / 2;

    updateDP(2 * i, left, mid, index, val);
    updateDP(2 * i + 1, mid + 1, right, index, val);

    segDP[i] = max(segDP[2 * i], segDP[2 * i + 1]);
}

int getDP(int i, int left, int right, int L, int R){
    if (right < L or R < left){
        return -inf;
    }
    if (L <= left and right <= R){
        return segDP[i];
    }
    int mid = (left + right) / 2;

    int t1 = getDP(2 * i, left, mid, L, R);
    int t2 = getDP(2 * i + 1, mid + 1, right, L, R);
    return max(t1, t2);
}

signed main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int sum = 0;
    int MIN = 1e18;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
        update(1,1,n,i,a[i]);
        MIN = min(MIN, a[i]);
    }

    if (k == 1){
        cout << sum;
        return 0;
    }
    if (k == n){
        cout << MIN;
        return 0;
    }
    int last = 0;
    dp[k] = get(1,1,n,1,k);
    int ans = dp[k];
    for (int i = k + 1; i <= n; i++){
        last = max(last, dp[i - k]);
//        cout << i << ": " << i - k << " " << endl;
//        int last = getDP(1,1,n,1,i - k);
//        cout << "dp: " << 1 << " " << i - k << endl;
        int mini = get(1,1,n,i - k + 1, i);
//        cout << "mini: " << i - k + 1 << " " << i << endl;
//        cout << i << ": " << last << " " << mini << endl;
        dp[i] = max(dp[i], last + mini);
//        updateDP(1,1,n,i,dp[i]);
        ans = max(ans,dp[i]);
    }

//    for (int i = 1; i <= n; i++){
//        cout << dp[i] << " ";
//    }
//    cout << endl;

    cout << ans;

    return 0;
}

/*
6 2
1 8 5 1 3 1

6 5
19450 10268 30106 17888 20346 5464
*/
