#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;
const int base = 256;
const int mod =  1e9 + 7;
int dp[maxN];
int po[maxN];
int add(int a, int b){
    return (a + b) % mod;
}
int subtr(int a, int b){
    return ((a + mod) - b) % mod; 
}
int mul(int a, int b){
    return (a * b) % mod;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    po[0] = 1;
    for (int i = 0; i < a.size(); i++){
        dp[i + 1] = add(mul(dp[i], base), (int)(a[i]));
        po[i + 1] = mul(po[i], base);
    }
    int val = 0;
    int pbase = 1;
    for (int i = 0; i < b.size(); i++){
        val = add(mul(val, base), (int)(b[i]));
    }


    // for (int i = 1; i <= a.size(); i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    int l = b.size();

    for (int i = 1; i <= a.size(); i++){
        int t = subtr(dp[i], mul(dp[i - l], po[l]));
        // cout << i << " " << dp[i] << " " << dp[i - l] << " " << i - (i - l) << endl;
        // cout << t % mod << " " << val << endl;
        // cout << "---" << endl;
        if (t % mod == val){
            cout << i - l + 1 << " ";
        }
    }
    cout << endl;
    return 0;
}