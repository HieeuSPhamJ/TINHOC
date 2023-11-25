#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;
const int base = 40;
const int mod =  1e9 + 7;

int n;
int s[maxN];
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
    // freopen("SEQ.inp", "r", stdin);
    // freopen("SEQ.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    
    unordered_map <int,int> cnto;
    int maxCnt = 0;
    for (int i = 0; i < n; i++){
        cin >> s[i];
        cnto[s[i]]++;
        maxCnt = max(maxCnt, cnto[s[i]]);

    }
    init();

    int left = 0;
    int right = n - 1;
    ii ans = {0,0};
    while(left <= right){
        int mid = (left + right) / 2;
        unordered_map <int,ii> cnt;
        ii tempCnt = {0,0};
        for (int i = 1; i <= n; i++){
            if (i + mid <= n){
                int hash = getHash(0,i, i + mid);
                cnt[hash].fi++;
                cnt[hash].se = i;
                tempCnt = max(tempCnt, cnt[hash]);
            }
        } 
        if (tempCnt.fi == maxCnt){
            left = mid + 1;
            ans = {tempCnt.se, tempCnt.se + mid};
        }
        else{
            right = mid - 1;
        }
    }

    cout << ans.fi << " " << ans.se << endl;

    return 0;
}