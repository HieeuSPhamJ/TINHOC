#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1010;
const int inf = 1e18;

int n, m, s, t;
vector <int> adj[maxN];
int f[maxN][maxN];
int cap[maxN][maxN];
int check[maxN];
int level[maxN];
int turn = 0;

void addEdge(int a, int b, int w){
    adj[a].push_back(b);
    adj[b].push_back(a);
    cap[a][b] += w;
}

bool BFS(){
    memset(level, 0, sizeof(level));
    queue <int> myQueue;
    myQueue.push(s);
    level[s] = 0;
    while(!myQueue.empty()){
        int tempV = myQueue.front();
        myQueue.pop();
        if (tempV == t){
            return 1;
        }
        for (auto newV: adj[tempV]){
            if (f[tempV][newV] < cap[tempV][newV] and level[newV] == 0 and newV != s){
                level[newV] = level[tempV] + 1;
                myQueue.push(newV);
            }
        }
    }
    return 0;
}

int DFS(int node, int Min){
    if (node == t){
        return Min;
    }
    if (check[node] != turn){
        check[node] = turn;
    }
    else{
        return 0;
    }
    for (auto newNode: adj[node]){
        if (check[newNode] != turn){
            if (level[node] + 1 == level[newNode] and f[node][newNode] < cap[node][newNode]){
                int tempMin = min(Min, cap[node][newNode] - f[node][newNode]);
                tempMin = DFS(newNode, tempMin);
                if (tempMin != 0){
                    f[node][newNode] += tempMin;
                    f[newNode][node] -= tempMin;
                    return tempMin;
                }
            }
        }
    }
    return 0;
}

int dinic(){
    int ans = 0;
    while(BFS()){
        turn++;
        int temp = DFS(s,inf);
        ans += temp;
    }
    return ans;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++){
        int a, b , w;
        cin >> a >> b >> w;
        addEdge(a,b,w);
    }
    
    int ans = dinic();

    cout << ans;
    return 0;
}