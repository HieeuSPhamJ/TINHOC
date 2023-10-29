#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;
const int base = 200;
const int mod =  1e9 + 7;

int n, k;
string s;

int D_odd[maxN];
int D_even[maxN];

void Calc_D_odd() {
    for(int i = 1 ; i <= n ; i++) {
        D_odd[i] = 0;
    }
    for(int i = 1 ; i <= n ; i++) {
        D_odd[i] = 0;
        while(i - D_odd[i] - 1 > 0 && i + D_odd[i] + 1 <= n && s[i - D_odd[i] - 1] == s[i + D_odd[i] + 1]) {
            D_odd[i]++;
        }
    }
}

void Calc_D_even() {
    // int L = 1;
    // int R = 0;
    for(int i = 1 ; i <= n ; i++) {
        D_even[i] = 0;
    }
    for(int i = 1 ; i < n ; i++) {
        int j = i + 1;
        D_even[i] = 0;
        while(i - D_even[i] > 0 && j + D_even[i] <= n && s[i - D_even[i]] == s[j + D_even[i]]) {
            D_even[i]++;
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("PALIVAL.inp", "r")) {
        freopen("PALIVAL.inp", "r", stdin);
        freopen("PALIVAL.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    int ans = 0;
    n = s.length();
    s = " " + s;
    for (int t = 1; t <= n; t++){
    for (int c = 'a'; c <= 'z'; c++){
        char old = s[t];
        s[t] = c;
        Calc_D_odd();
        Calc_D_even();
        int res = 0;
        for(int i = 1 ; i < n ; i++) {
            res += D_odd[i] + 1;
            res += D_even[i];
        }
        res += D_odd[n]+ 1;
        ans = max(ans,res);
        s[t] = old;
    }
    }

    cout << ans << endl;
    return 0;
}