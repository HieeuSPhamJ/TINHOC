#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;


int n, test;
int NPRIME = 0;
int daucatmoi[(1 << 20)];
// int cnt[50];
int conv[100];
vector <int> primes;

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

int lcm(int x, int y){
    return x * y;
}

int sol(int x1, int x2){
    int ans = 0;
    for (int mask = 1; mask < (1 << (NPRIME + 1)); mask++){
        
        int temp = x2 / daucatmoi[mask] - x1 / daucatmoi[mask];
        if (!(__builtin_popcount(mask) & 1)){
            temp = -temp;
        }
        ans += temp;
    }
    return ans;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> test;

    int nn = n;
    for (int i = 2; i * i <= nn; i++){
        // cout << i << endl;
        if (nn % i == 0){
            // cout << "take" << endl;
            primes.push_back(i);
            conv[NPRIME] = i;
            NPRIME++;
            while(nn % i == 0){
                // cnt[conv[i]]++;
                nn /= i;
            }
        }
    }
    if (nn != 1) {
        conv[NPRIME] = nn;
        primes.push_back(nn);
        // cnt[conv[nn]]++;
    }

    // for (int i = 0; i <= NPRIME; i++){
    //     cout << i << ": " << conv[i] << endl;
    // }

    // cout << sol(1);

    for (int mask = 1; mask < (1 << (NPRIME + 1)); mask++){
        int y = 1;
        for (int j = 0; j <= NPRIME; j++){
            if (getBit(mask, j)){
                y *= conv[j];
            }
        }
        daucatmoi[mask] = y;
    }

    while(test--){
        int a, b;
        cin >> a >> b;
        int ans = sol(a - 1,b);
        // cout << sol(b) << " " << sol(b) << (__gcd(a,n) == 1);
        cout << (b - a + 1) - ans << endl;
    }

    return 0;
}