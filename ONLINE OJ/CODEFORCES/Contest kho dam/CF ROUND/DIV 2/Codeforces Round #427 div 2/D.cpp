#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5010;
const ii mod = {1e9 + 7, 1e9 + 9};
const ii base = {50,24};

ii ha[2][maxN];
int dp[maxN][maxN];
ii POW[maxN];
int cnt[maxN];

ii mul(ii a, ii b){
    (a.fi *= b.fi) %= mod.fi;
    (a.se *= b.se) %= mod.se;
    return a;
}

ii add(ii a, ii b){
    (a.fi += b.fi) %= mod.fi;
    (a.se += b.se) %= mod.se;
    return a;
}


ii subtr(ii a, ii b){
    (a.fi = a.fi - b.fi + mod.fi) %= mod.fi;
    (a.se = a.se - b.se + mod.se) %= mod.se;
    return a;
}

void print(ii a){
    cout << a.fi << " " << a.se << endl;
}

bool check(int l, int r){
    ii ha1 = subtr(ha[0][r], mul(ha[0][l - 1], POW[r - l + 1]));
    ii ha2 = subtr(ha[1][l], mul(ha[1][r + 1], POW[r - l + 1]));
    // print(ha1);
    // print(ha2);
    return ha1 == ha2;
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();
    s = "!" + s;
    ha[0][0] = {0,0};
    ha[1][0] = {0,0};
    ha[1][n + 1] = {0,0};
    POW[0] = {1,1};
    for (int i = 1; i <= n; i++){
        POW[i] =  mul(POW[i - 1], base);
    }
    for (int i = 1; i <= n; i++){
        ha[0][i] = add(mul(ha[0][i - 1], base), {s[i], s[i]});
    }
    for (int i = n; i >= 1; i--){
        ha[1][i] = add(mul(ha[1][i + 1], base), {s[i], s[i]});
    }
    // for (int i = 0; i <= n; i++){
    //     cout << ha[0][i].fi << " ";
    // }
    // cout << endl;
    // for (int i = 0; i <= n; i++){
    //     cout << ha[1][i].fi << " ";
    // }
    // cout << endl;
    // cout << check(2,3) << endl;
    for (int r = 1; r <= n; r++){
        for (int l = r; l >= 1; l--){
            if (check(l,r)){
                // cout << "With: " << l << " " << r << endl;
                int len = (r - l + 1) / 2;
                dp[l][r] = (min(dp[l][l + len - 1], dp[r - len + 1][r]) + 1);
                cnt[dp[l][r]]++;
                // cout << dp[l][r] << " "<< (min(dp[l][l + len], dp[r - len][r]) + 1) * check(l,r) << endl;
                // cout << dp[l][l + len] << " " << dp[r - len][r] << " " << check(l,r) << endl;
            }
        }
    }
    for (int i = n; i >= 1; i--){
        cnt[i] += cnt[i + 1];
    }
    for (int i = 1; i <= n; i++){
        cout << cnt[i] << " ";
    }
    cout << endl;

    return 0;
}