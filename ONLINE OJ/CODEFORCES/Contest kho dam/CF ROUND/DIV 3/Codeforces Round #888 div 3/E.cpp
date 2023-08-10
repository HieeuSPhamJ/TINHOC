#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int a[maxN];
vector <int> adj[maxN];
int dp[maxN];

int cal(int nu){
    int &res = dp[nu];
    if (res != -1){
        // cout << nu << " " << res << endl; 
        return res;
    }    
    res = 0;
    for (auto i: adj[nu]){
        res += cal(i);
    }

    if (adj[nu].size()){
        res = min(res,a[nu]);
    }
    else{
        res = a[nu];
    }

    // cout << nu << " " << res << endl; 
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            dp[i] = -1;
            adj[i].clear();
        }
        for (int i = 1; i <= m; i++){
            int x;
            cin >> x;
            a[x] = 0;
        }
        for (int t = 1; t <= n; t++){
            int x;
            cin >> x;
            if (x == 0){
                continue;
            }
            int co = 0;
            vector <int> ls;
            for (int i = 1; i <= x; i++){
                int p;
                cin >> p;
                ls.push_back(p);
                
            }
            if (a[t] == 0){
                continue;
            }
            for (auto i: ls){
                adj[t].push_back(i);
            }
        }

        // for (int i = 1; i <= n; i++){
        //     for (auto j: adj[i]){
        //         cout << i << " " << j << endl;
        //     }
        // }

        // for (int i = 1; i <= n; i++){
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        // cout << cal(1) << endl;
        for (int i = 1; i <= n; i++){
            cout << cal(i) << " ";
        }
        cout << endl;
    }
    return 0;
}