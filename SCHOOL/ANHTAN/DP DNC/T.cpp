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
    ii best = ii(0 , -1); 
    unordered_set <int> s;
    
    for(int k = min(mid,optr); k >= optl; k--){
        s.insert(a[k]);
        // if (s.size() != cost[k][mid]){
        //     cout << k << " " << mid << ": " << s.size() << " " << cost[k][mid] << endl;
        // }
        if(best.fi < dp_before[k - 1] + s.size()){
            best = {dp_before[k - 1] + s.size(), k};
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
        unordered_set <int> s;
        for (int j = i; j <= n; j++){
            s.insert(a[j]);
            cost[i][j] = s.size();
        }
    }
    
    for (int i = 1; i <= m; i++){
        cal(1,n,1,n);
        for (int j = 1; j <= n; j++){
            // cout << dp_curr[j] << " ";
            dp_before[j] = dp_curr[j];
        }
        // cout << endl;
    }
    cout << dp_before[n];

    return 0;
}

