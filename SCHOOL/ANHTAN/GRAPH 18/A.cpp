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
const int maxN = 1e5 + 10;

int n, m;
int a[maxN];
vector <ii> adj[maxN];
int visited[3][maxN];
priority_queue <ii, vector <ii>, greater <ii>> myHeap;

void init(int type){
    for (int i = 1; i < maxN; i++){
        visited[type][i] = inf;
    }
}

void Dickcha(int type){
    init(type);
    for (int i = 1; i <= n; i++){
        if (a[i] == type){
            myHeap.push({0, i});
            visited[type][i] = 0;
        }
    }
    
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop(); 
        // cout << "#" << tempV.id << endl;
        if (tempV.len != visited[type][tempV.id]){
            continue;
        }
        for (auto newV: adj[tempV.id]){
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[b].push_back({c, a});
    }

    Dickcha(0);
    Dickcha(1);

    for (int i = 1; i <= n; i++){
        if (visited[!a[i]][i] == inf){
            cout << -1;
        }
        else{
            cout << visited[!a[i]][i];
        }

        cout << endl;
    }

    return 0;
}