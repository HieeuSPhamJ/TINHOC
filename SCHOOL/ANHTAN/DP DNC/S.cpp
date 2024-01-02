#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e3 * 5 + 10;

int n, m;
int a[maxN];
int cost[maxN][maxN];
int upp[maxN][maxN];

int dp_curr[maxN];
int dp_before[maxN];


int C(int i, int j){
    return cost[j][j] - cost[i - 1][j]; 
}

void cal(int l ,int r, int optl, int optr){
    if (l > r){
        return;
    }
    int mid = (l + r) / 2;
    int opt = optl;
    // cout << mid << ": " << endl;
    for (int i = optl; i <= min(mid, optr); i++){
        if (dp_curr[mid] > dp_before[i - 1] + C(i, mid)){
            dp_curr[mid] = dp_before[i - 1] + C(i, mid);
            opt = i;
            // cout << i << endl;
        }
    }
    // cout << opt << " " << dp_before[mid] << endl;

    cal(l, mid - 1, optl, opt);
    cal(mid + 1, r, opt, optr);
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
        // cout << i << ": " << bitset <4> (a[i]) << endl;
    }

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            upp[i][j] = upp[i][j - 1] + bool(a[i] > a[j]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cost[j][i] = cost[j - 1][i] + upp[j][i];
        }
    }

    
    for (int i = 1; i <= n; i++){
        dp_curr[i] = dp_before[i] = 1e9;
    
    }
    

    dp_before[0] = 0;
    for (int i = 1; i <= m; i++){
        // cout << "with: " << i << endl;
        cal(1,n,1,n);
        for (int j = 1; j <= n; j++){
            dp_before[j] = dp_curr[j];
        }
    }
    cout << dp_before[n];

    return 0;
}