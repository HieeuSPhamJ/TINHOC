#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int n, k;
int a[maxN];
int pre[maxN];


int cal(int l, int mid, int r){
    int mv = pre[mid] - pre[mid - 1];
    int ler = r - mid + 1;
    int lel = mid - l + 1;
    return (pre[r] - pre[mid - 1]) - mv * ler + mv * lel - (pre[mid] - pre[l - 1]);
}
 
int cal(int L, int R){
    int l = L;
    int r = R;
    int res = 1e18; 
    // return cal(1,1,1);
    while(l <= r){
        int mid = (l + r) / 2;
        int t1 = cal(L, mid, R);
        res = min(res,t1);
        if (mid != R){
            int t2 = cal(L, mid + 1, R);
            res = min(res,t2);
            if(t1 < t2){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        else{
            r = mid - 1;
        }
    }
    return res;
} 

int dp[maxN];
int cur[maxN];

void dnc(int l = 1, int r = n, int bl = 1, int br = n){
    if (l > r){
        return;
    }
    int i = (l + r) / 2;
    int opt = bl;
    // cout << i << ": " << bl << " " << min(i,br) << endl;

    for (int j = bl; j <= min(i,br); j++){
        int t = cur[j - 1] + cal(j,(j + i) / 2, i);
        // cout << j << " " << t << endl;
        if (dp[i] > t){
            dp[i] = t;
            opt = j;
        }
    }
    // cout << dp[i] << endl;

    dnc(l, i - 1, bl, opt);
    dnc(i + 1, r, opt, br);
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
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 0; i <= n; i++){
        cur[i] = dp[i] = 1e18;
    }
    cur[0] = 0;
    for (int j = 1; j <= k; j++){
        // cout << "With: " << j << endl;
        dnc();
        for (int i = 0; i <= n; i++){
            cur[i] = dp[i];
            dp[i] = 1e18;
        }
    }

    cout << cur[n] << endl;
    return 0;
}

/*
dp[i][g] 
= dp[j][g - 1] + cost
(giong dnc vcl)
cost[a][d] >= cost[b][c]
=> adu dnc riel
*/