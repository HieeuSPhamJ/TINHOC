#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define iii pair <int,ii>
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

struct cmp{
    bool operator ()(const iii& a, const iii& b){
        int x = a.se.fi * a.se.se - a.se.se / 2 * a.se.fi;
        int y = b.se.fi * b.se.se - b.se.se / 2 * b.se.fi;
        return x < y;
    }
};

int sum = 0;
vector <ii> adj[maxN];
int dp[maxN];
priority_queue <iii, vector <iii>, cmp> lists;


void DFS(int node,int father, int w){
    dp[node] = 0;
    int check = 0;
    for (auto i: adj[node]){
        if (i.se == father){
            continue;
        }
        check = 1;
        DFS(i.se, node, i.fi);
        dp[node] += dp[i.se];
    }
    if (check == 0){
        dp[node] = 1;
    }
    lists.push({node,{dp[node],w}});
    sum += dp[node] * w;
}

signed main(){
    
    // freopen("input.inp", "r", stdin);
    // freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        while(!lists.empty()){
            lists.pop();
        }
        int n, s;
        cin >> n >> s;
        for (int i = 1 ; i <= n; i++){
            adj[i].clear();
        }
        
        for (int i = 1 ; i < n; i++){
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({w,b});
            adj[b].push_back({w,a});
        }

        sum = 0;

        DFS(1,1,0);

        int cnt = 0;

        // cout << sum << endl;
        
        while(sum > s){
            iii t = lists.top();
            lists.pop();
            sum -= t.se.fi * t.se.se;
            t.se.se /= 2;
            sum += t.se.fi * t.se.se;
            // cout << t.fi << " " << sum << endl;
            // cout << t.se.fi << " " << t. << endl;
            lists.push(t);
            cnt++;
        }

        // while(!lists.empty()){
        //     iii t = lists.top();
        //     lists.pop();
        //     cout << t.fi << " " << t.se.fi << " " << t.se.se << endl;
        // }

        cout << cnt << endl;

    }
    return 0;
}