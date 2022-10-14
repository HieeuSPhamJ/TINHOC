#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
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

bool check(int n){
    return countBits(n) == 2;
}

signed main(){
    // freopen("input.inp", "r", stdin);
    // freopen("A.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        if (check(n)){
            cout << 0 << endl;
            continue;
        }
        if (check(n + 1)){
            cout << 1 << endl;
            continue;
        }
        if (n == 1){
            cout << 2 << endl;
            continue;
        }
        vector <int> listBits;
        for (int i = log2(n); i >= 0; i--){
            if (getBit(n,i)){
                listBits.push_back(i);
                // cout << i << " ";
            }                
        }
        // cout << endl;
        
        int m = (1 << listBits[0]) | (1 << listBits[1]);
        int t1 = abs(m - n);
        int t2 = 1e18;
        // cout << m << "-";
        if (listBits[0] - 1 != listBits[1]){
            m = (1 << listBits[0]) | (1 << listBits[1] + 1);
            t2 = abs(m - n);
            // cout << t2;
        }
        m = (1 << listBits[0] + 1) | (1 << 0);
        t2 = min(t2,abs(m - n));
        // cout << endl;

        cout << min(t1,t2) << endl;

    }
    return 0;
}