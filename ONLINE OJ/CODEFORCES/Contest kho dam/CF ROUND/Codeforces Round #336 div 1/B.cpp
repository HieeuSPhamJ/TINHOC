#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 510;

int a[maxN];
int dp[maxN][maxN];

int cal(int l, int r){
    int &res = dp[l][r];

    if (l == r){
        res = 1;
        return res;
    }
    if (l > r){
        return -1;
    }

    for (int i = 1; i <= n; i++){
        
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    cout << cal(1,n);
    return 0;
}