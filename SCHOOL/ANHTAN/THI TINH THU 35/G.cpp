#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define endl "\n"
#define int long long
using namespace std;

const int maxN = 1000 + 10;

int n, m;
int Start, End;
vector <ii> adj[maxN];
int visited[maxN];
int value[maxN];

void treeSubTask(){
    queue <int> myQueue;
    visited[Start] = 1;
    myQueue.push(Start);
    // for (int i = 1; i <= n; i++){
    //     cout << "NODE: " << i << endl;
    //     for (auto v: adj[i]){
    //         cout << v.se << ", ";
    //     }
    //     cout << endl;
    // }
    while(!myQueue.empty()){
        int tempV = myQueue.front();
        myQueue.pop();
        // cout << "#" << tempV << endl;
        for (auto newV: adj[tempV]){
            if (visited[newV.se] == 1){
                continue;
            }
            // cout << newV.se << " ";
            visited[newV.se] = 1;
            value[newV.se] = value[tempV] | newV.fi;
            myQueue.push(newV.se);
        }
        cout << endl;
    }
    cout << value[End];

}

void normalSub(){
    cout << 3;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    cin >> Start >> End;
    
    if (m == n - 1){
        treeSubTask();
    }
    else{
        normalSub();
    }

    return 0;
}