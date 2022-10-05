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

int n, m, Start, End;

vector <pair <int,int>> adj[maxN];
int ban[maxN];
int visited[maxN];
priority_queue <ii, vector <ii>, greater <ii>> myHeap;

void Dickcha(){
    myHeap.push({0, Start});
    visited[Start] = 0;
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop(); 
        // cout << "#" << tempV.id << endl;
        if (tempV.len != visited[tempV.id]){
            continue;
        }
        for (auto newV: adj[tempV.id]){
            if (visited[tempV.id] + newV.val < min(ban[newV.id],visited[newV.id])){
                // cout << newV.id << ' ';
                visited[newV.id] = visited[tempV.id] + newV.val;
                myHeap.push({visited[newV.id], newV.id});
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
    
    cin >> n >> m >> Start >> End;
    for (int i = 1; i <= n; i++){
        cin >> ban[i];
        if (ban[i] == 0){
            ban[i] = inf;
        }
        visited[i] = inf;
    }
    for (int i = 1; i<= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }

    
    Dickcha();
    if (visited[End] == inf){
        cout << -1;
        return 0;
    }
    cout << visited[End];

    return 0;
}