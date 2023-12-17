#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

vector <vector <int>> a;
vector <vector <int>> dp;
vector <priority_queue <ii,vector <ii>, greater <ii>>> sto;
vector <multiset<ii>> pre;

bool maximize(int &a, int b){
    if (a < b){
        a = b;
        return 1;
    }
    return 0;
}

bool minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
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
    int n, m;
    cin >> n >> m;
    sto.resize(m + 1);
    pre.resize(m + 1);
    a.resize(n + 1);
    dp.resize(n + 1);
    
    for (int i = 1; i <= n; i++){
        a[i].resize(m + 1);
        dp[i].resize(m + 1);
    }    

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    dp[1][1] = 1;
    sto[1].push({1 + a[1][1],1});
    pre[1].insert({1,1 + a[1][1]});
    for (int i = 1; i <= n; i++){
        
        priority_queue <ii, vector <ii>, greater <ii>> q;
        multiset <ii> s;
        
        for (int j = 1; j <= m; j++){
            // cout << "With: " << i << " " << j << endl;
            if (i == 1 and j == 1){
                q.push({1 + a[1][1],1});
                s.insert({1, 1 + a[1][1]});
                continue;
            }

            dp[i][j] = 1e18;
            while (sto[j].size() and sto[j].top().fi < i){
                ii t = sto[j].top();
                sto[j].pop();
                swap(t.fi, t.se);
                if (pre[j].find(t) != pre[j].end()){
                    pre[j].erase(pre[j].find(t));
                }
            }
            if (pre[j].size()){
                minimize(dp[i][j], (*pre[j].begin()).fi + 1);
            }

            while(q.size() and q.top().fi < j){
                ii t = q.top();
                q.pop();
                swap(t.fi, t.se);
                if (s.find(t) != s.end()){
                    s.erase(s.find(t));
                }
            }
            if (s.size()){
                minimize(dp[i][j], (*s.begin()).fi + 1);
            }

            if (dp[i][j] != 1e18){
                // cout << "x: ";
                // for (auto x: s){
                //     cout << x.fi << "," << x.se << " ";
                // }
                // cout << endl;
                // cout << "y: ";
                // for (auto x: pre[j]){
                //     cout << x.fi << "," << x.se << " ";
                // }
                // cout << endl;
                // cout << dp[i][j] << endl;

                q.push({j + a[i][j], dp[i][j]});
                s.insert({dp[i][j], j + a[i][j]});
                sto[j].push({i + a[i][j], dp[i][j]});
                pre[j].insert({dp[i][j], i + a[i][j]});
            }
        }
    }

    if (dp[n][m] == 1e18){
        cout << -1 << endl;
        return 0;
    }
    cout << dp[n][m] << endl;
    return 0;
}