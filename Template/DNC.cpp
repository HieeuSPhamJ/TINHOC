#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 8010;


int n, k;
int a[maxN];
int dp[maxN];
int old[maxN];

int cost(int j, int i){
    return (i - j + 1) * (a[i] - a[j - 1]);
}

void cal(int l, int r, int optl, int optr){
    if (l > r){
        return;
    }
    int i = (l + r) / 2;

    int opt = 1;
    // cout << i << ": " << optl << " " << min(i,optr) << endl;
    for (int j = optl; j <= min(i,optr); j++){
        if (dp[i] > old[j - 1] + cost(j,i)){
            dp[i] = old[j - 1] + cost(j,i);
            opt = j;
            // cout << " " << j << " " << old[j - 1] << " " << cost(j,i) << " " << dp[i] << endl;
        }
    }

    // cout << l << " " << i - 1 << " " << optl << " "  << opt << endl;
    // cout << i + 1 << " " << r << " " << opt << " "  << optr << endl;

    cal(l, i - 1, optl, opt);
    cal(i + 1, r, opt, optr);
}

void print(){
    for (int i = 1; i <= n; i++){
        if (old[i] == 1e18){
            cout << "inf ";
            continue;
        }
        cout << old[i] << " ";
    }
    cout << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++){
        old[i] = a[i] * i;
        dp[i] = 1e18;
    }
    old[0] = 0;
    // print();
    for (int j = 2; j <= k; j++){
        // cout << "With: " << j << endl;
        cal(1,n,1,n);
        for (int i = 1; i <= n; i++){
            old[i] = dp[i];
            dp[i] = 1e18;
        }
        // print();
    }

    cout << old[n];

    return 0;
}

/*
11 44 99 228 415 1098 
inf 44 55 114 199 480 
inf 66 99 114 155 366 

*/