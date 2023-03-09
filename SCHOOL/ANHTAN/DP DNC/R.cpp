#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e3 * 5 + 10;

int n, m;
int a[maxN];
int cost[maxN][maxN];

int dp_curr[maxN];
int dp_before[maxN];

int cnt[32];

void cal(int l, int r, int optl, int optr){
    if(l > r){
        return;
    }
    int mid = (l + r) / 2;
    ii best = ii(1e18 , -1); 
    for(int k = optl; k <= min(mid,optr); k++){
        if(best.fi > dp_before[k - 1] + cost[k][mid]){
            best = {dp_before[k - 1] + cost[k][mid], k};
        }
    }
    dp_curr[mid] = best.fi;
    cal(l, mid - 1, optl, best.se); 
    cal(mid + 1, r, best.se, optr); 
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++){
        cost[i][i] = 0;
        for (int j = 0; j <= 31; j++){
            cnt[j] = 0;
            if ((a[i] & (1ll << j)) > 0){
                cnt[j]++;
            }
        }
        for (int j = i + 1; j <= n; j++){
            cost[i][j] = cost[i][j - 1];
            for (int k = 0; k <= 31; k++){
                int t = cnt[k];
                if ((a[j] & (1ll << k))){
                    t = (j - i - t);
                    cnt[k]++;
                }
                cost[i][j] += (1ll << k) * t;
            }
        }
    }
    
    m++;
    
    for (int i = 1; i <= n; i++){
        dp_before[i] = 1e18;
    }

    dp_before[0] = 0;
    for (int i = 1; i <= m; i++){
        cal(1,n,1,n);
        for (int i = 1; i <= n; i++){
            dp_before[i] = dp_curr[i];
        }
    }
    cout << dp_before[n];

    return 0;
}