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
    int count = 0;
    while (mask){
        count += (mask & 1);
        mask >>= 1;
    }
    return count;
}

int a[20];

int lcm(int x, int y){
    int gcd = __gcd(x,y);
    return (x * y / gcd);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int ans = n;
    for (int i = 1; i <= k; i++){
        cin >> a[i];
    }
    for (int mask = 1; mask < (1 << k); mask++){
        int LCM = 1;
        for (int i = 0; i <= log2(mask); i++){
            // cout << getBit(mask,i);
            if (getBit(mask,i)){
                LCM = lcm(LCM, a[i + 1]);
            }
        }
        int temp = n / LCM;
        // cout << " " << temp  << " " << LCM << endl;
        if (countBits(mask) % 2){
            temp = -temp;
        }
        ans += temp;
    }

    cout << ans;
    
    return 0;
}