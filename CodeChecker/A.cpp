#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool getBit(int mask, int i){
    return (mask & (1ll << i));
}

int onBit(int mask, int i){
    return mask | (1ll << i);
}

int offBit(int mask, int i){
    if (getBit(mask,i)){
        return (mask xor (1ll << i));
    }
    return mask;
}

int flipBit(int mask, int i){
    return (mask xor (1ll << i));
}

int countBits(int mask){
    int count = 0;
    while (mask){
        count += (mask & 1);
        mask >>= 1;
    }
    return count;
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int len = log2(n);
        int m = n;
        for (int i = len; i >= len / 2; i--){
            if (getBit(m,i)){
                m = onBit(m, len - i);
            }
            else{
                m = offBit(m, len - i);
            }
        }
        int ans = abs(n - m);
        if (len % 2 == 0){
            ans = min(ans, abs(n - flipBit(m,len / 2)));
        }
        cout << ans << endl;
    }
    return 0;
}
/*
100101
100111
100001
*/