#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int maxBits[20];

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

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        for (int j = 0;  j < 22; j++){
            if (getBit(inp,j)){
                maxBits[j] = max(maxBits[j], inp);
            }
        }
    }

    cin >> n;

    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        int ans = 0;
        int temp = 0;
        for (int j = 0;  j < 22; j++){
            if (getBit(inp,j) == 0){
                if ((inp xor maxBits[j]) > temp){
                    ans = maxBits[j];
                    temp = (inp xor maxBits[j]);
                }
            }
        }
        cout << ans << " ";
    }

    return 0;
}