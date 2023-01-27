#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

bool getBit(int mask, int i){
    return (mask & (1ll << i));
}

int onBit(int mask, int i){
    return mask | (1ll << i);
}

int offBit(int mask, int i){
    return (mask xor (1ll << i));
}

int countBits(int mask){
    int count = 0;
    while (mask){
        count += (mask & 1ll);
        mask >>= 1ll;
    }
    return count;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int x;
        cin >> x;
        int sum = (x * 2) + x % 2;
        int temp = (sum - x) / 2;
        int a = temp | x;
        int b = a xor x;
        if ((a xor b) != x){
            cout << -1 << endl;
            continue;
        }
        if (((a + b) / 2) != x){
            cout << -1 << endl;
            continue;
        }
        cout << a << ' ' << b << endl;
    }
    return 0;
}
/*
100011010
100011010

1000110100
0100011101
0000000001
*/