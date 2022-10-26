#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int inf = 1e18;
const int maxN = 1e5 + 10;

int n;
int a[maxN];
ii b[maxN];
int seg[maxN * 4];
int dp[maxN];
 


bool cmp(ii x, ii y){
    return x.s < y.s;
}


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
    if (_right < left or right < _left){
        return -inf;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;
    return max(get(2 * i, left, mid, _left, _right), get(2 * i + 1, mid + 1, right, _left, _right));

}

signed main(){
	freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    b[0] = {0, 0};
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = {a[i], i};
        dp[i] = 1;
        // update(1, 1, n, i, 1);
    }

    sort(b + 1, b + 1 + n);
    for (int i = 1, j = 0; i <= n; i++){
        if (b[i].f != b[i - 1].f){
            j++;
        }
        b[i].f = j;
        
    }

    sort(b + 1, b + 1 + n, cmp);

    for (int i = 1; i <= n; i++){
        a[i] = b[i].f;
        // cout << a[i] << ' ';
    }
    // cout << endl;

    int ans = 0;

    for (int i = 1; i <= n; i++){
        int temp = get(1, 1, n, 1, a[i] - 1);
        if (temp == -inf){
            temp = 0;
        }
        if (dp[a[i]] == 0){
            dp[a[i]] = 1;
        }
        // cout << a[i] << ' ' << dp[a[i]] << ' ' << temp << endl;
        dp[a[i]] = max(dp[a[i]], 1 + temp);
        update(1, 1, n, a[i], dp[a[i]]);
        ans = max(ans, dp[a[i]]);
    }

    // for (int i = 1; i <= n; i++){
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;
    cout << ans;

    

    return 0;
}

/*
    0 1 2 3 4 5 6 7 8 9 10
    0 1 2 3 4 0 0 0 0 0 0
    
    1 2 3 4 5 4 3 2 1 10



*/

