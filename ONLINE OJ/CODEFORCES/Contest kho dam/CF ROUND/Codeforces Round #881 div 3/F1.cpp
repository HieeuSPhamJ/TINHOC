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

int n;
int a[maxN];
vector <int> adj[maxN];
vector <pair <int,ii>> query;
int dp[3][maxN];

void dfs(int nu, int p, int s1, int s2){
    s1 = max(s1,0ll);
    s2 = max(s2,0ll);
    dp[0][nu] = max(dp[0][nu], s1);
    dp[1][nu] = max(dp[1][nu], s2);
    for (auto i: adj[nu]){
        if (i == p){
            continue;
        }
        dp[0][i] = max(dp[0][nu], dp[0][i]);
        dp[1][i] = max(dp[1][nu], dp[1][i]);
        dfs(i,nu,s1 + a[i], s2 - a[i]);
    }
}

void init(){
    for (int i = 1; i <= n; i++){
        dp[0][i] = 0;  
    }
    for (int i = 1; i <= n; i++){
        dp[1][i] = 0;   
    }
    dfs(1,1,1,0);
    for (int i = 1; i <= n; i++){
        adj[i].clear();
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
    while(test--){
        cin >> n;
        a[1] = 1;
        for (int i = 1, num = 1; i <= n; i++){
            char t;
            cin >> t;
            if (t == '+'){
                num++;
                int v, x;
                cin >> v >> x;
                adj[v].push_back(num);
                adj[num].push_back(v);
                a[num] = x;
            }
            else{
                int u, v, k;
                cin >> u >> v >> k;
                query.push_back({k,{u,v}});
            }
        }
        init();

        for (auto q: query){
            if (q.fi >= 0){
                if (dp[0][q.se.se] >= q.fi){
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;   
                }
            }
            else{
                if (dp[1][q.se.se] >= abs(q.fi)){
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
            }
        }

        // for(auto v: query){
        //     if(v.fi<0){
        //         if(dp[1][v.se.se]>=abs(v.fi)) cout<<"YES"<<'\n';
        //         else cout<<"NO"<<'\n';
        //     }
        //     else{
        //         if(dp[0][v.se.se]>=v.fi) cout<<"YES"<<'\n';
        //         else cout<<"NO"<<'\n';
        //     }
        // }
    }
    return 0;
}