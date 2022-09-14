#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 4 * 1e5 + 10;
const int inf = 1e18;
int n, m;

vector <ii> adj[maxN];
int visited[maxN];

void init(){
    for (int i = 1; i < maxN; i++){
        visited[i] = inf;
    }
}

void dickcha(){
    init();
    priority_queue <ii, vector <ii>, greater <ii>> myHeap;
    visited[1] = 0;
    myHeap.push({0,1});
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop();
        if (tempV.fi > visited[tempV.se]){
            continue;
        }
        for (auto newV: adj[tempV.se]){
            if (newV.fi + tempV.fi >= visited[newV.se]){
                continue;
            }
            visited[newV.se] = newV.fi + tempV.fi;
            myHeap.push({visited[newV.se], newV.se});
        }
    }

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b + n].push_back({w,a + n});
    }

    for (int i = 1; i <= n; i++){
        adj[i].push_back({0,i + n});
    }

    dickcha();

    for (int i = 2; i <= n; i++){
        if (visited[i + n] == inf){
            cout << -1 << " ";
            continue;
        }
        cout << visited[i + n] << " ";
    }
    return 0;
}