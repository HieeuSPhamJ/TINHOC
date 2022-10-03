#include<bits/stdc++.h>
#define ii pair <int,int>
#define val first
#define id second
#define len first
#define num second
#define int long long
using namespace std;

const int maxN = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;

int n, m;
vector <ii> adj[maxN];
int visited1[maxN];
int visitedn[maxN];
priority_queue <ii, vector <ii>, greater <ii>> myHeap;
queue <int> myQueue;
int check[maxN] = {0};
int dir1[maxN];
int dirn[maxN];

void init(){
    for (int i = 1; i <= n; i++){
        visited1[i] = inf;
        visitedn[i] = inf;
        dirn[i] = 0;
        dir1[i] = 0;
    }
}

void Dickcha(){
    myHeap.push({0, 1});
    visited1[1] = 0;
    dir1[1] = 1;
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop();
        if (tempV.len != visited1[tempV.id]){
            continue;
        }
        for (auto newV: adj[tempV.id]){
            if (visited1[tempV.id] + newV.val < visited1[newV.id]){
                visited1[newV.id] = visited1[tempV.id] + newV.val;
                myHeap.push({visited1[newV.id], newV.id});
                dir1[newV.id] = dir1[tempV.id];
            }
            else if (visited1[tempV.id] + newV.val == visited1[newV.id]){
                (dir1[newV.id] += dir1[tempV.id]) %= mod;
            }
        }
    }

    myHeap.push({0, n});
    visitedn[n] = 0;
    dirn[n] = 1;
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        // cout << "!" << tempV.id << endl;
        myHeap.pop();
        if (tempV.len != visitedn[tempV.id]){
            continue;
        }
        for (auto newV: adj[tempV.id]){
            if (visitedn[tempV.id] + newV.val < visitedn[newV.id]){
                // cout << newV.id << ' ';
                visitedn[newV.id] = visitedn[tempV.id] + newV.val;
                myHeap.push({visitedn[newV.id], newV.id});
                dirn[newV.id] = dirn[tempV.id];
            }
            else if (visitedn[tempV.id] + newV.val == visitedn[newV.id]){
                (dirn[newV.id] += dirn[tempV.id]) %= mod;
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
    for (int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});

    }

    init();
    Dickcha();

    int minLen = visited1[n];
    int totalDir = dir1[n];
    int ans = n - 2;

    for (int i = 2; i < n; i++){
        if (minLen == visited1[i] + visitedn[i] and (dirn[i] * dir1[i]) % mod == totalDir % mod){
            ans--;
            check[i] = 1;
        }
    }

    // for (int i = 1; i <= n; i++){
    //     cout << dir1[i] << ' ' << dirn[i] << endl;
        
    // }

    cout << ans << endl;

    for (int i = 2; i < n; i++){
        if (check[i] == 0){
            cout << i << endl;
        }
    }

    return 0;
}
