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

int n;
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
    cin >> n >> s;
    init();
    
    // cout << getHash(0,1,2) << " " << getHash(1,2,3) << endl;

    int ans = 0;
    for (int i = 1; i <= n; i++){
        int left = 0;
        int right = min(i - 1, n - i);
        int tempAns = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            int l = i - mid;
            int r = i + mid;
            if (getHash(0,l,i) == getHash(1,i,r)){
                left = mid + 1;
                tempAns = max(tempAns, mid * 2 + 1);
            }
            else{
                right = mid - 1;
            }
        }
        left = 0;
        right = min(i - 1, n - i + 1);
        while(left <= right){
            int mid = (left + right) / 2;
            int l = i - mid;
            int r = i + mid - 1;
            if (getHash(0,l,i - 1) == getHash(1,i,r)){
                left = mid + 1;
                tempAns = max(tempAns, mid * 2);
            }
            else{
                right = mid - 1;
            }
        }
        ans = max(ans, tempAns);

    }

    cout << ans;

    return 0;
}