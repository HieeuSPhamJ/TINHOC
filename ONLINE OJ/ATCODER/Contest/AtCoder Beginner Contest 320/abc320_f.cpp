#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 600 + 10;

int a[maxN];
int p[maxN];
int f[maxN];
int dp[maxN][310];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, h;
    cin >> n >> h;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[n + n - i] = a[i];
    }

    for (int i = 1; i <= n; i++){
        
    }

    return 0;
}

/*
1 2 3 4 5 6
1

*/