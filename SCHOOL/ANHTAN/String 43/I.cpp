#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;
const int mod = 1e6 + 7;
const int base = 256;

int dp[maxN];

int add(int a, int b){
    return (a + b) % mod;
}
int subtr(int a, int b){
    return ((a + mod) - b) % mod; 
}
int mul(int a, int b){
    return (a * b) % mod;
}

bool getBit(int mask, int i){
    return (mask & (1 << i));
}

int conv(string s){
    int mask = 0;
    for (int i = 0; i < 4; i++){
        mask = add(mul(mask, base), (int)s[i]);
    }
    return mask;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, d;
    cin >> n >> d;
    vector <string> lists;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        lists.push_back(s);
        for (int c1 = 0; c1 <= 1; c1++){
        for (int c2 = 0; c2 <= 1; c2++){
        for (int c3 = 0; c3 <= 1; c3++){
        for (int c4 = 0; c4 <= 1; c4++){
            string ss = s;
            int mask = 0;
            if (c1){
                ss[0] = '~';
                mask = mask | (1 << 0);
            }
            if (c2){
                ss[1] = '~';
                mask = mask | (1 << 1);
            }
            if (c3){
                ss[2] = '~';
                mask = mask | (1 << 2);
            }
            if (c4){
                ss[3] = '~';
                mask = mask | (1 << 3);
            }
            int tans = 0;
            for (int preMask = mask; preMask; preMask = mask & (preMask - 1)){
                string sss = ss;
                for (int j = 0; j < 4; j++){
                    if (getBit(preMask, j)){
                        sss[j] = s[j];
                    }
                }
                tans -= dp[conv(sss)];
            }
            tans += 2 * dp[conv(s)];
            dp[ss] += tans;
        }   
        }   
        }   
        }
    }
    
    return 0;
}