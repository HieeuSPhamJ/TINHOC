#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;


const int maxN = 4 * 1e3 + 10;
const int base = 256;
const int mod =  1e9 + 7;

int n;
string s;
int dp[3][maxN];
int po[maxN];
int tans[maxN];
int kans[maxN];
int temp[maxN][maxN];

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
    memset(dp, -1, sizeof(dp));
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

bool checkPalin(int left, int right){
    int hash1 = getHash(0, left, right);
    int hash2 = getHash(1, left, right);
    // cout << hash1 << " " << hash2 << endl;
    if (hash1 == hash2){
        return 1;
    }
    return 0;
}

int check(int left, int right){
    // cout << left << " " << right << endl;
    // if (dp[left][right] != -1){
    //     return dp[left][right];
    // }
    int len = (right - left + 1);
    if (len == 1){
        // cout << "len 1" << endl;
        // dp[left][right] = 1;
        return 1;
    }
    if (!checkPalin(left, right)){
        // cout << "not Palin" << endl;
        // dp[left][right] = 0;
        return 0;
    }
    if (len % 2 == 0){
        int mid = (left + right) / 2;
        int t = check(left, mid);
        // dp[left][right] = t + 1;
        return t + 1;
    }
    int mid = (left + right) / 2 - 1;
    int t = check(left, mid);
    // dp[left][right] = t + 1;
    return t + 1;
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    n = s.length();
    init();

    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            int t = check(i,j);
            if (t == 0){
                continue;
            }
            tans[t]++;
            // cout << i << " " << j << " " << t << endl;
            // kans[t]++;
        }
    }

    // cout << check(1,n) << endl;

    for (int i = n, t = 0; i >= 1; i--){
        t += tans[i];
        kans[i] += t;
    }

    for (int i = 1; i <= n; i++){
        cout << kans[i] << " ";
    }
    return 0;
}