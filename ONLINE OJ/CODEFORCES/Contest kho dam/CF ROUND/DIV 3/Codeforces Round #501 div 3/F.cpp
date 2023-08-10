#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 210;
const int mod = 1000000007;

int dp[102][3][maxN];    
int dpn[102][3][maxN];    
int p[maxN];
int aut[maxN][3];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    n = 2 * n;
    int m = s.length();
    s = ' ' + s + ' ';
    for (int i = 2; i <= m; i++){
        int k = p[i - 1];
        while(k > 0 and s[k + 1] != s[i]){
            k = p[k];
        }
        if (s[k + 1] == s[i]){
            p[i] = k + 1;
        }
    }

    // for (int i = 1; i <= m; i++){
    //     cout << p[i] << ' ';
    // }
    // cout << endl;

    for (int i = 0; i <= m; i++){
        for (int c = 0; c <= 1; c++){
            if (s[i + 1] - '(' == c){
                aut[i][c] = i + 1;
            }
            else{
                aut[i][c] = aut[p[i]][c];
            }
            // cout << i << " " << char(c + '(') << " " << aut[i][c] << endl;
        }
    }

    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int o = 0; 2 * o <= n; o++){
            for (int k = 0; k <= 1; k++){
                for (int kmp = 0; kmp <= m; kmp++){
                    int curr = dp[o][k][kmp];
                    if (curr == 0){
                        continue;
                    }
                    cout << i << ' ' << o << ' ' << k << " " << kmp << ": " << curr << endl;
                    int nkmp = aut[kmp][0];
                    cout << " -> " << i + 1 << ' ' << o + 1 << ' ' << k + (nkmp == m) << " " << nkmp << endl;
                    (dpn[o + 1][(k + (nkmp == m) > 0)][nkmp] += curr) %= mod;
                    if (o > 0){
                        nkmp = aut[kmp][1];
                        cout << " -> " << i + 1 << ' ' << o - 1 << ' ' << k + (nkmp == m) << " " << nkmp << endl;
                        (dpn[o - 1][(k + (nkmp == m) > 0)][nkmp] += curr) %= mod;
                    }
                }
            }
        }
        for (int o = 0; 2 * o <= n; o++){
            for (int k = 0; k <= 1; k++){
                for (int kmp = 0; kmp <= m; kmp++){
                    dp[o][k][kmp] = dpn[o][k][kmp];
                    dpn[o][k][kmp] = 0;
                }
            }
        }
    }
    
    int res = 0;

    for (int kmp = 0; kmp <= m; kmp++){
        (res += dp[0][1][kmp]) %= mod;
    }


    cout << res << endl;

    return 0;
}

/*
dp[i][o][k][kmp] = số lượng dãy có:
                    độ dài là i
                    số lượng dấu mở thừa là o
                    số lượng đoạn con mà giống với dãy s là k

ans = dp[2 * n][0][0][k][kmp] (k = 1 -> 2 * n)

opt:
    bỏ đi chiều i

(()(

*/