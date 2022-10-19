#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define val first
#define id second
#define len first
#define num second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int inf = 1e18;
const int maxN = 1e5 + 10;

vector <ii> adj[3][maxN];
int visited[3][maxN];
priority_queue <ii, vector <ii>, greater <ii>> myHeap;

void Dickcha(int type, int Start){
    myHeap.push({0, Start});
    visited[type][Start] = 0;
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop(); 
        // cout << "#" << tempV.id << endl;
        if (tempV.len != visited[type][tempV.id]){
            continue;
        }
        for (auto newV: adj[type][tempV.id]){
            if (visited[type][tempV.id] + newV.val < visited[type][newV.id]){
                // cout << newV.id << ' ';
                visited[type][newV.id] = visited[type][tempV.id] + newV.val;
                myHeap.push({visited[type][newV.id], newV.id});
            }
        }
        // cout << endl;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k, s, t;
    cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= n; i++){
        visited[0][i] = inf;
        visited[1][i] = inf;
        
    }
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[0][a].push_back({w,b});
        adj[1][b].push_back({w,a});
    }
    Dickcha(0,s);
    Dickcha(1,t);
    int ans = visited[0][t];

    // cout << ans << endl;

    for (int i = 1; i <= k; i++){
        int a, b, w;
        cin >> a >> b >> w;
        ans = min(ans, visited[0][a] + visited[1][b] + w);
        ans = min(ans, visited[0][b] + visited[1][a] + w);
    }
    if (ans == inf){
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}