#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int a[32];
int dp[32][32][32][32 * 32];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int m;
    cin >> m;
    for (int i = 1; i <= s.length(); i++){
        if (s[i - 1] == 'K'){
            a[i] = 0;
        }
        else if (s[i - 1] == 'E'){
            a[i] = 1;
        }
        else{
            a[i] = 2;
        }
    }
    
    int n = s.length();

    for (int i = 0; i <= n; i++){
        for (int k = i; k >= 0; k--){
            for (int e = i - k; e >= 0; e--){
                for (int t = 0; t <= i * i; t++){
                    int y = i - k - e;
                    int cur = dp[k][e][y][t];
                    
                }
            }
        }
    }

    return 0;
}