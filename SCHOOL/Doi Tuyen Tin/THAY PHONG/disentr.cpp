#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define val first
#define id second
#define len first
#define num second
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e3 + 10;
const int inf = 1e18;

int n, m;
int s,t,k,c;

struct iiii{
    int open, close;
};

vector <ii> adj[maxN];
int cost[maxN][maxN];
int visited[maxN];
iiii ban[maxN];

void setBan(int a, int b, int time){
    ban[a] = {min(ban[a].open, time), max(ban[a].close, time + cost[a][b])};
    ban[b] = {min(ban[b].open, time), max(ban[b].close, time + cost[a][b])};
    
}

void init(){
    for (int i = 1; i <= n; i++){
        ban[i] = {inf,0};
        visited[i] = inf;
    }
}


void Dickcha(){
    priority_queue <ii, vector <ii>, greater <ii>> myHeap;
    visited[s] = k;
    myHeap.push({k,s});
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop(); 
        cout << "#" << tempV.id << endl;
        if (tempV.fi != visited[tempV.id]){
            continue;
        }
        for (auto newV: adj[tempV.id]){
            if (visited[tempV.id] + newV.val < visited[newV.id]){
                cout << newV.id << ' ';
                visited[newV.id] = visited[tempV.id] + newV.val;
                myHeap.push({visited[newV.id], newV.id});
            }
        }
        cout << endl;
    }
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    init();
    cin >> s >> t >> k >> c;
    vector <int> lists;
    for (int i = 1; i <= c; i++){
        int inp;
        cin >> inp;
        lists.push_back(inp);
    }
    for (int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = c;
        cost[b][a] = c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    for (int i = 1, time = 0; i < lists.size(); i++){
        int a = lists[i - 1], b = lists[i];
        setBan(a, b, time);
        time += cost[a][b];
    }

    for (int i = 1; i <= n; i++){
        if (ban[i].open == inf){
            ban[i].open = 0;
        }
        else{
            ban[i].open++;
        }
        cout << ban[i].open << " " << ban[i].close << endl;
    }

    Dickcha();
    // cout << visited[t];
    for (int i = 1; i <= n; i++){
        cout << i << " " << visited[i] << endl;
    }
    return 0;
}