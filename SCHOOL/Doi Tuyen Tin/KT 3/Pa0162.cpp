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

int cal(){
    int ans = 0;
    init();
    for (int i = 1; i <= n; i++){
        // cout << "With: " << i << endl;
        int left = 0;
        int right = min(i - 1, n - i);
        int tempAns = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            int l = i - mid;
            int r = i + mid;
            if (getHash(0,l,i) == getHash(1,i,r)){
                left = mid + 1;
                tempAns = max(tempAns, mid + 1);
            }
            else{
                right = mid - 1;
            }
        }
        // cout << tempAns << " ";
        ans += tempAns;
        left = 0;
        right = min(i - 1, n - i + 1);
        tempAns = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            int l = i - mid;
            int r = i + mid - 1;
            if (getHash(0,l,i - 1) == getHash(1,i,r)){
                left = mid + 1;
                tempAns = max(tempAns, mid);
            }
            else{
                right = mid - 1;
            }
        }
        // cout << tempAns << endl;
        ans += tempAns;
    }
    return ans;
}

string a;

signed main(){
    freopen("Pa0162.inp", "r", stdin);
    freopen("Pa0162.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    a = s;
    n = s.length();

    cal();

    return 0;
}