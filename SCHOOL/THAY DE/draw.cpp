#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define iii pair <ii,int>
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2010;
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
    cout << a << " " << b << " " << w << endl;
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

ii a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    int s = n + n + n + n + 1;
    int t = n + n + n + n + 2;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j){
                continue;
            }
            if (a[i].fi == a[j].se){ 
                addEdge(i + n, j + n + n, 1);
            }
            else if (a[i].se == a[j].se){  
                addEdge(i + n, j + n + n, 1);
            }
        }
    }

    for (int i = 1; i <= n; i++){
        addEdge(s, i, 1);
        addEdge(i, i + n, 1);
        addEdge(i + n + n, t, 1);
        addEdge(i + n + n, i + n, 1);
    }
    int ans = 0;
    // ans = dinic();
    cout << ans;
    return 0;
}