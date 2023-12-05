#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e6 + 10;

int a[maxN];
int b[maxN];
int p[maxN];
int auto[maxN][20];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    for (int i = 1; i <= n; i++){
        a[i] = s[i - 1] - 'a';
    }
    for (int i = 1; i <= m; i++){
        b[i] = t[i - 1] - 'a';
    }
    for (int i = 2; i <= m; i++){
        int t = p[i - 1];
        while(t and b[t + 1] != b[i]){
            t = p[t];
        }
        if (b[t + 1] == b[i]){
            p[i] = t + 1;
        }
    }


    return 0;
}