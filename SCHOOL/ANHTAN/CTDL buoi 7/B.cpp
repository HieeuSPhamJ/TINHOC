#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
// #define maxN int(1e5 + 10)
using namespace std;

const int inf = 1e18;
const int maxN = 1e5 + 10;

int n;
int a[maxN];
ii b[maxN];
int seg[maxN * 4];
int dpL[maxN];
int dpR[maxN];
int dp[2][maxN];


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

main(){
    cin >> n;
    b[0] = {0, 0};
    
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = {a[i], i};
    }

    sort(b + 1, b + 1 + n);
    for (int i = 1, j = 0; i <= n; i++){
        if (b[i].f != b[i - 1].f){
            j++;
        }
        b[i].f = j;
    }

    sort(b + 1, b + 1 + n, cmp);

    int maxA = 0;
    for (int i = 1; i <= n; i++){
        a[i] = b[i].f;
        dpL[i] = dpR[i] = 1;
        maxA = max(maxA, a[i]);
        // cout << a[i] << ' ';
    }
    // cout << endl;

    for (int i = 1; i <= n; i++){
        int temp = get(1, 1, n, 1, a[i] - 1);
        if (temp == -inf){
            temp = 0;
        }
        // dpL[a[i]] += temp;
        dpL[a[i]] = max(dpL[a[i]], 1 + temp);
        update(1, 1, n, a[i], dpL[a[i]]);
        dp[0][i] = dpL[a[i]];
    }

    for (int i = 1; i < 4 * maxN; i++){
        seg[i] = 0;
    }

    for (int i = n; i >= 1; i--){
        int temp = get(1, 1, n, 1, a[i] - 1);
        if (temp == -inf){
            temp = 0;
        }
        dpR[a[i]] = max(dpR[a[i]], 1 + temp);
        update(1, 1, n, a[i], dpR[a[i]]);
        dp[1][i] = dpR[a[i]];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++){
        ans = max(ans, 2 * min(dp[0][i] - 1, dp[1][i] - 1) + 1);
    }
    // cout << endl;

    // for (int i = 1; i <= n; i++){
    //     cout << dp[0][i] << ' ';
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++){
    //     cout << dp[1][i] << ' ';
    // }
    // cout << endl;
    
    // cout << "---" << endl;

    // for (int i = 1; i <= n; i++){        
    //     cout << dpL[i] << ' ';
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++){
    //     cout << dpR[i] << ' ';
    // }
    // cout << endl;

    cout << ans;

    

    return 0;
}

/*
1 2 3 2 1 2 3 4 3 2 1 5 4 1 2 3 2 2 1 


*/