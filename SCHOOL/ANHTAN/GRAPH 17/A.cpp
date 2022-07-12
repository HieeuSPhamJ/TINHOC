#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define x first
#define y second
#define val first
#define id second
#define len first
#define num second
#define int long long
using namespace std;

const int inf = 1e18;
const int maxN = 2 * 1e5 + 10;

vector <ii> adj[maxN];
int visited[maxN];
int cityVisited[maxN];
int checkLower = 0;
priority_queue <ii, vector <ii>, greater <ii>> myHeap;

void init(){
    for (int i = 1; i < maxN; i++){
        visited[i] = inf;
    }
}

void Dickcha(){
    init();
    myHeap.push({0, 1});
    visited[1] = 0;
    cityVisited[1] = 1;
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop(); 
        // cout << "#" << tempV.id << endl;
        if (tempV.len != visited[tempV.id]){
            continue;
        }
        for (auto newV: adj[tempV.id]){
            if (visited[tempV.id] + newV.val < visited[newV.id]){
                // cout << newV.id << ' ';
                visited[newV.id] = visited[tempV.id] + newV.val;
                myHeap.push({visited[newV.id], newV.id});
                cityVisited[newV.id] = cityVisited[tempV.id] + 1;
            }
            if (visited[tempV.id] + newV.val == visited[newV.id]){
                cityVisited[newV.id] = min(cityVisited[newV.id], cityVisited[tempV.id] + 1);
            }
            
        }
        // cout << endl;
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int a, b, v;
        cin >> a >> b >> v;
        adj[a].push_back({v, b});
        adj[b].push_back({v, a});
    }
    Dickcha();

    cout << visited[n] << ' ';
    if (cityVisited[n] <= k){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}