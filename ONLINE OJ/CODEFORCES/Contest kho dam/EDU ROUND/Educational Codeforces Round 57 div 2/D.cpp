#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int dp[(int)(1e5 + 10)][5];

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
    n = s.length();
    vector <int> a,b;
    a.push_back(-1);
    b.push_back(0);
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        int c = s[i] - 'a';
        if (a.back() == c){
            x += b.back();
            a.pop_back();
            b.pop_back();
        }
        a.push_back(c);
        b.push_back(x);
    }
    n = a.size() - 1;
    for (int i = 1; i <= n; i++){
        if (a[i] == 7){
            a[i] = 0;
        }
        else if (a[i] == 0){
            a[i] = 1;
        }
        else if (a[i] == 17){
            a[i] = 2;
        }
        // cout << a[i] << " ";
    }
    // cout << endl;
    // for (int i = 1; i <= n; i++){
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= 3; j++){
            dp[i][j] = 1e18;
            if (j != 0){
                dp[i][j] = dp[i][j - 1];
            }
            if (a[i] == j){
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + b[i]);
            }
            else{
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
        }
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]});


    return 0;
}

/*
- 5 9 11 7 1
+ h a r  d h
h 5 5 5
a 0 5 5
r 0 0 5
d 0 0 
*/