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
    return cost[j][j] - cost[i][j]; 
}

void cal(int l, int r, int optl, int optr){
    if(l > r){
        return;
    }
    int mid = (l + r) / 2;
    ii best = ii(1e9 , -1); 
    for(int k = optl; k <= min(mid,optr); k++){
        if(best.fi > dp_before[k] + C(k,mid)){
            best = {dp_before[k] + C(k,mid), k};
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
        dp_before[i] = 1e9;
    }

    dp_before[0] = 0;
    for (int i = 1; i <= m; i++){
        cal(1,n,0,n - 1);
        for (int j = 1; j <= n; j++){
            dp_before[j] = dp_curr[j];
        }
    }
    cout << dp_before[n];

    return 0;
}