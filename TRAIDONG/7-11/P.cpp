#include<bits/stdc++.h>

#pragma GCC optimize("O2")

#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define pb push_back
#define endl '\n'

using namespace std;

const int maxN = 2e5 + 10;
const int inf = 1e9;

int n, m, k;
int a[maxN];
vector <ii> adj[maxN];
int ans[maxN];
int dist[maxN];
int getId[maxN];
ii visited[maxN];
priority_queue <ii, vector <ii>, greater <ii>> myHeap;

bool getBit(int mask, int i){
    return (mask & (1 << i));
}

void reset(){
    for (int i = 1; i <= k + n; i++){
        visited[i] = {inf, -1};
    }
}

void dickcha(){
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop(); 
        // cout << "#" << tempV.se << endl;
        if (tempV.fi != visited[tempV.se].fi){
            continue;
        }
        for (auto newV: adj[tempV.se]){
            if (visited[tempV.se].fi + newV.fi < visited[newV.se].fi){
                // cout << newV.se << ' ';
                visited[newV.se].fi = visited[tempV.se].fi + newV.fi;
                visited[newV.se].se = visited[tempV.se].se;
                
                myHeap.push({visited[newV.se].fi, newV.se});
            }
            // if (visited[tempV.se].fi + newV.fi == visited[newV.se].fi){
            //     // cout << newV.se << ' ';
            //     if (visited[newV.se].se > visited[tempV.se].se){
            //         visited[newV.se].se = visited[tempV.se].se;   
            //         myHeap.push({visited[newV.se].fi, newV.se});
            //     }
            // }
        }
        // cout << endl;
    }
}

void sol(int j, int type){
    reset();
    for (int i = 1; i <= k; i++){
        int node = a[i];
        if (getBit(node,j) == type){
            myHeap.push({0, node});
            visited[node] = {0, node};
        }
    }
    dickcha();

    for (int i = 1; i <= k; i++){
        int node = a[i];
        if (getBit(node,j) == !type){
            if (visited[node].fi < dist[node]){
                dist[node] = visited[node].fi;
                ans[node] = getId[visited[node].se];
            }
            if (visited[node].fi == dist[node]){
                ans[node] = min(ans[node],getId[visited[node].se]);
            }
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++){
        cin >> a[i];
        int newa = n + i;
        adj[newa].pb({0,a[i]});
        adj[a[i]].pb({0,newa});
        // cout << newa << " " << a[i] << endl;
        a[i] = newa;
        dist[a[i]] = inf;
        ans[a[i]] = inf;
        getId[a[i]] = i;
        
    }

    for (int i = 1; i <= m; i++){
        int x,y,w;
        cin >> x >> y >> w;
        adj[x].pb({w,y});
        adj[y].pb({w,x});
    }

    for (int j = log2(k); j >= 0; j--){
        // S.clear();
        // T.clear();
        // int z1 = 0;
        // int z2 = 0;
        // for (int i = 1; i <= k; i++){
        //     if (getBit(i,j)){
        //         z1++;
        //     }
        //     else{
        //         z2++;
        //     }
        // }
        // if (z1 * z2 == 0){
        //     continue;
        // }
        sol(j,0);
        sol(j,1);
    }

    for (int i = 1; i <= k; i++){
        cout << ans[a[i]] << " ";
    }
    // cout << endl;
    // for (int i = 1; i <= k; i++){
    //     cout << dist[a[i]] << " ";
    // }

    return 0;
}