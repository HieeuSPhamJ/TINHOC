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

const int maxN = 510;

int n, k;
int dp[maxN][maxN];
int a[maxN];
int pre[maxN];

bool minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
}

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

int cost[maxN][maxN];

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
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            cost[i][j] = cal(i,j);
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int g = 1; g <= k; g++){
            for (int j = 1; j <= i; j++){
                minimize(dp[i][g], dp[j - 1][g - 1] + cost[j][i]);
            }
        }
    }
    
    // cout << cost(3,4) << endl;

    cout << dp[n][k] << endl;
    return 0;
}

/*
1 1 2 2 3 3

*/