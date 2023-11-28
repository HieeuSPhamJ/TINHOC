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

const int maxN = 4e5 + 10;
const int inf = 1e18;

int n;
int a[maxN];
int pre[maxN];

int bit[maxN];

void update(int i, int v){
    i += n + 1;
    while(i <= 2 * n){
        bit[i] = min(bit[i],v);
        i += (i & (-i));
    }
}

int get(int i){
    i += n + 1;
    int res = inf;
    while(i){
        res = min(res,bit[i]);
        i -= (i & (-i));
    }
    return res;
}

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
    string s;
    cin >> s;
    n = s.length();
    int res = 0;
    for (char c = 'a'; c <= 'z'; c++){
        for (int i = 0; i <= 2 * n; i++){
            bit[i] = inf;
        }
        // cout << "With: " << c << endl;
        update(pre[0],1);
        for (int i = 1; i <= n; i++){
            pre[i] = pre[i - 1] + (c == s[i - 1]) + -1 * (c != s[i - 1]);
            // cout << pre[i] << " ";
            int t = get(pre[i] - 1);
            // cout << t << ' ' << i << endl;
            if (t != inf){
                res = max(res, i - t + 1);
            }
            update(pre[i], i + 1);
        }
        // cout << endl;
    }

    cout << res << endl;
    return 0;
}

/*
 a b b b a b c e  d
-1 0 1 2 1 2 1 0 -1 

0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
1000000000000000000 9

*/