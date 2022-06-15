#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int inf = 1e18;
const int maxK = 11;
const int maxN = 1e5 + 10;
const int mod = 1e9;

int n, k;
int a[maxN];
ii b[maxN];
int seg[maxK][maxN * 4];
int dp[maxK][maxN];
int maxA = 0;
 


bool cmp(ii x, ii y){
    return x.s < y.s;
}


void update(int i, int left, int right, int index, int k, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[k][i] = val;
        seg[k][i] %= mod;
        return;
    }

    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, k, val);
    update(2 * i + 1, mid + 1, right, index, k, val);

    seg[k][i] = seg[k][2 * i] + seg[k][2 * i + 1];

    seg[k][i] %= mod;
    
}

int get(int i, int left, int right, int _left, int _right, int k){
    if (_right < left or right < _left){
        return 0;
    }
    if (_left <= left and right <= _right){
        return seg[k][i];
    }

    int mid = (left + right) / 2;
    return (get(2 * i, left, mid, _left, _right, k) + get(2 * i + 1, mid + 1, right, _left, _right, k)) % mod;

}

void printDP(){
    cout << "---++++---" << endl;
    for (int i = 1; i <= k; i++){
        for (int j = 1; j <= n; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    b[0] = {0, 0};
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = {a[i], i};
        // dp[1][i] = 1;
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
        maxA = max(maxA, a[i]);
    }

    // for (int i = 1; i <= n; i++){
    //     update(1, 1, n, a[i], 1, 1);
    // }

    for (int j = 1; j <= n; j++){
        for (int i = 1; i <= k; i++){
            if (i == 1){
                dp[i][a[j]] += 1;
                // update(1, 1, n, a[j], i, 1);
                // continue;
            }
            int temp = get(1, 1, n, a[j] + 1, n, i - 1);
            dp[i][a[j]] += temp;
            dp[i][a[j]] %= mod;
            update(1, 1, n, a[j], i, dp[i][a[j]]);

            // cout << j << ' ' << a[j] << ' ' << temp << endl;
            // printDP();

            // cout << i << ' ' << a[j] << ' ' << dp[i][a[j]] << endl;
        }
    }

    // cout << '#';

    // cout << maxA;

    // printDP();
    
    int ans = get(1, 1, n, 1, n, k);

    ans %= mod;

    cout << ans;

    return 0;
}


