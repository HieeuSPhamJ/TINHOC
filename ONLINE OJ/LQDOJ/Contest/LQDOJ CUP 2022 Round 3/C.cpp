#include<bits/stdc++.h>
#define ii pair <int,int>
#define iii pair <ii,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;


int n, test;
int a[maxN];
int ans;
int dp[1020][1020];
vector <iii> query;


void backtrack(int l, int r, int s, int val){
    // cout << l << " " << r << " " << s << " " << val << endl;
    if (l >= r){
        if (val == s){
            ans++;
        }
        // cout << "-----" << endl;
        return;
    }
    backtrack(l + 1, r, s, (val xor a[l + 1]));
    backtrack(l + 1, r, s, (val));

}

void sub1(){
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    while(test--){
        int q;
        cin >> q;
        if (q == 1){
            int i, x;
            cin >> i >> x;
            a[i] = x;
            continue;
        }
        int l, r, s;
        cin >> l >> r >> s;
        ans = 0;
        backtrack(l - 1,r,s,0);
        cout << ans << endl;
    }
    
}

void sub2(){
    int ma = 0;
    for (int i = 0; i < n; i++){
        ma = max(ma, a[i]);
    }
    int m = (1 << (int)(log2(ma) + 1)) - 1;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            dp[i][j] = dp[i - 1][j] + dp[i - 1][(j xor a[i - 1])];
        }
    }

    for (auto i: query){
        cout << dp[i.fi.se][i.se] - dp[i.fi.fi - 1][i.se] << endl;
    }
}

signed main(){
    freopen("XORSEG.inp", "r", stdin);
    freopen("XORSEG.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> test;
    if (n <= 20){
        sub1();
    }

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= test; i++){
        int q;
        cin >> q;
        if (q == 1){
            cout << "DARKBULMAO" << endl;
            return 0;
        }
        else{
            int l, r, s;
            cin >> l >> r >> s;
            query.push_back({{l,r},s});
        }
    }

    sub2();

    return 0;
}