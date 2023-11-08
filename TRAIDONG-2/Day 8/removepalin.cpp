#include<bits/stdc++.h>
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e6 + 10;
const int inf = 1e9 + 7;
const int delta = 2;

int dp[8][8];
int newdp[8][8];
int a[maxN];

int add(int c, int x){
    return (c + x + 26) % 26;
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("removepalin.inp", "r")) {
        freopen("removepalin.inp", "r", stdin);
        freopen("removepalin.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();
    if (n == 1){
        cout << 0 << endl;
        return 0;
    }
    if (n == 2){
        if (s[0] == s[1]){
            cout << 1 << endl;
            return 0;
        }
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++){
        a[i] = s[i - 1] - 'a';
        // cout << a[i] << " ";
    }
    // cout << endl;
    for (int i = 0; i <= delta * 2; i++){
        for (int j = 0; j <= delta * 2; j++){
            newdp[i][j] = dp[i][j] = inf;
        }
    }
    for (int i = -delta; i <= delta; i++){
        for (int j = -delta; j <= delta; j++){
            if (add(a[1],i) != add(a[2],j)){
                int &cur = dp[i + delta][j + delta];
                // cout << add(a[1],i) << " " << add(a[2],j) <<
                cur = min(cur, abs(i) + abs(j));
            }
        }
    }

    int res = inf;
    for (int t = 2; t < n; t++){
        // cout << "With: " << t << endl;
        for (int i = 0; i <= delta * 2; i++){
            for (int j = 0; j <= delta * 2; j++){
                int &cur = dp[i][j];
                // cout << "With: " << t << " " << i - delta << " " << j - delta << ": " << cur << endl;
                // cout << add(a[t - 1], i - delta) << " " << add(a[t], j - delta) << endl;
                if (cur == inf){
                    continue;
                }
                for (int k = -delta; k <= delta; k++){
                    int c1 = add(a[t - 1], i - delta);
                    int c2 = add(a[t], j - delta);
                    int c3 = add(a[t + 1], k);
                    // cout << " =>" << j - delta << " " << k << ": " << cur + abs(k) << endl;
                    // cout << " " << c1 << " " << c2 << " " << c3 << endl;
                    if (c1 != c3 and c2 != c3){
                        // cout << "#" << endl;
                        newdp[j][k + delta] = min(newdp[j][k + delta], cur + abs(k));
                    }
                }
            }
        }
        for (int i = 0; i <= delta * 2; i++){
            for (int j = 0; j <= delta * 2; j++){
                dp[i][j] = newdp[i][j];
                newdp[i][j] = inf;
                if (t == n -1){
                    res = min(res, dp[i][j]);
                }
            }
        }
    }

    cout << res << endl;
    
    return 0;
}

/*
0 1 2 delta 4 
*/