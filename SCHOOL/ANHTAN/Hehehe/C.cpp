#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
using namespace std;

bool getBit(int mask, int i){
    return (mask & (1 << i));
}

int onBit(int mask, int i){
    return mask | (1 << i);
}

int offBit(int mask, int i){
    return (mask xor (1 << i));
}

int countBits(int mask){
    return __builtin_popcount(mask);
}

const int maxN = 1e6 + 10;

int a[maxN];

int dp[(1 << 10)];

int thismask(int x){
    int mask = 0;
    while(x){
        mask = onBit(mask, x % 10);
        x /= 10;
    }
    return mask;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++){
        int mask = thismask(a[i]);
        // cout << "Index: " << bitset<10>(mask) << endl;     
        // cout << mask << endl;
        for(int submask = mask; submask; submask = (submask - 1) & mask){
            int temp = dp[submask];
            // cout << "SUB " << bitset<10>(submask) << endl; 
            if (countBits(submask) % 2 == 0){
                temp =- temp;
            }
            // cout << temp << endl;
            ans += temp; 
            dp[submask]++;
        }
    }
    cout << ans;
    
    return 0;
}