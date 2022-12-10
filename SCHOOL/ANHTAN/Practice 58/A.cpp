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

vector <ii> adj[maxN];
vector <ii> invAdj[maxN];
int visited[3][maxN];
priority_queue <ii, vector <ii>, greater <ii>> myHeap;

void Dickcha(int Start, int type){
    for (int i = 1; i < maxN; i++){
        visited[type][i] = inf;
    }
    myHeap.push({0, Start});
    visited[type][Start] = 0;
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop(); 
        // cout << "#" << tempV.id << endl;
        if (tempV.len != visited[type][tempV.id]){
            continue;
        }
        if (type == 0){
            for (auto newV: adj[tempV.id]){
                if (visited[type][tempV.id] + newV.val < visited[type][newV.id]){
                    // cout << newV.id << ' ';
                    visited[type][newV.id] = visited[type][tempV.id] + newV.val;
                    myHeap.push({visited[type][newV.id], newV.id});
                }
            }
        }
        else{
            for (auto newV: invAdj[tempV.id]){
                if (visited[type][tempV.id] + newV.val < visited[type][newV.id]){
                    // cout << newV.id << ' ';
                    visited[type][newV.id] = visited[type][tempV.id] + newV.val;
                    myHeap.push({visited[type][newV.id], newV.id});
                }
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
    int test;
    cin >> test;
    while(test--){
        int n, m, k;
        cin >> n >> m >> k;
        int s, t;
        cin >> s >> t;
        for (int i = 1; i <= n; i++){
            adj[i].clear();
            invAdj[i].clear();
            
        }
        for (int i = 1; i <= m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({c,b});
            invAdj[b].push_back({c,a});
            
        }

        // cout << n << " " << m << endl;

        Dickcha(s,0);
        Dickcha(t,1);

        int ans = visited[0][t];
        // cout << ans << endl;

        for (int i = 1; i <= k; i++){
            int a, b, w;
            cin >> a >> b >> w;
            // cout << "#" << a << " " << b << endl;
            // cout << visited[0][a] << " " << visited[1][b] << endl;
            // cout << visited[1][a] << " " << visited[0][b] << endl;
            
            ans = min(ans, visited[0][a] + w + visited[1][b]);
            ans = min(ans, visited[1][a] + w + visited[0][b]);
        }
        if (ans >= inf){
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}