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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k >> s;
    init();
    int left = 0;
    int right = n - 1;
    int ans = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        map <int,int> count;
        for (int i = 1; i <= n; i++){
            if (i - mid >= 1){
                count[getHash(0,i - mid, i)]++;
            }
        }
        int check = 0;
        for (auto substr: count){
            if (substr.se >= k){
                check = 1;
                break;
            }
        }
        if (check){
            left = mid + 1;
            ans = max(ans, mid + 1);
        }
        else{
            right = mid - 1;
        }
    }
    cout << ans;
    
    return 0;
}