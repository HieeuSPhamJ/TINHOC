#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;
const int base = 74;
const int mod =  1e9 + 7;

int n, k;
string s;
int dp[3][maxN];
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

void init(){
    po[0] = 1;
    n = s.length();
    for (int i = 0; i < n; i++){
        dp[0][i + 1] = add(mul(dp[0][i], base), (int)(s[i]));
        po[i + 1] = mul(po[i], base);
    }
    for (int i = n - 1; i >= 0; i--){
        // cout << i + 1 << " " << i << " " << i + 2 << endl;
        dp[1][i + 1] = add(mul(dp[1][i + 2], base), (int)(s[i]));
    }
}

int getHash(int type, int left, int right){
    int len = (right - left + 1);
    if (type == 1){
        swap(left, right);
        left++;
    }
    else{
        left--;
    }
    int hash = subtr(dp[type][right], mul(dp[type][left], po[len]));
    
    return hash;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("PALIVAL.inp", "r")) {
        freopen("PALIVAL.inp", "r", stdin);
        freopen("PALIVAL.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    int ans = 0;
    for (int t = 0; t < (int)s.length(); t++){
    for (int c = 'a'; c <= 'z'; c++){
        char old = s[t];
        s[t] = c;
        init();
        int res = 0;
        for (int i = 1; i <= n; i++){
            int l = 0;
            int r = min(i - 1, n - i);
            int tres = 0;
            while(l <= r){
                int mid = (l + r) / 2;
                if (getHash(0,i - mid, i) == getHash(1,i, i + mid)){
                    tres = mid + 1;
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            res += tres;
            l = 0;
            r = min(i - 1, n - i - 1);
            tres = 0;
            while(l <= r){
                int mid = (l + r) / 2;
                if (getHash(0,i - mid, i) == getHash(1,i + 1, i + 1 + mid)){
                    tres = mid + 1;
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            res += tres;
        }
        s[t] = old;
        ans = max(ans, res);
    }
    }

    cout << ans << endl;
    return 0;
}