#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int inf = 1e18;

string s;
string a, b;

int dp[1010][52][52];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    cin >> a >> b;
    int n = s.length();
    int na = a.length();
    int nb = b.length();
    s = '!' + s;
    a = '!' + a;
    b = '!' + b;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= na; j++){
            for (int k = 0; k <= nb; k++){
                dp[i][j][k] = -inf;
            }
        }
    }

    dp[0][0][0] = 0;

    for (int i = 1; i < n; i++){
        for (int j = 0; j <= na; j)
    }



    return 0;
}