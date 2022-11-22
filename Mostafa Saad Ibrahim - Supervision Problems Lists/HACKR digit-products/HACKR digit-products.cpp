#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int cal(string s, int k){
    for (int i = 0; i <= 110; i++){
        for (int j = 0; j <= 10010; j++){
            dp[i][j]
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++){
        string a, b;
        int k;
        cin >> a >> b >> k;
        cout << "Case " << t << ":" << cal(b, k) - cal(a - 1, k) << endl;
    }
    return 0;
}