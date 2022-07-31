#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 2 * 1e5 + 10;

int n, k;
vector <int> adj[maxN];
int f[maxN];
int visited[maxN];
int val[maxN];
vector <ii> lists;


void init(int resetVal){
    for (int i = 1; i <= n; i++){
        f[i] = resetVal;
        visited[i] = 0;
    }
}

int DFS(int v){
    // cout << v << endl;
    visited[v] = 1;
    for (auto i: adj[v]){
        if (visited[i] == 0){
            // cout << i << ' ';
            f[v] += DFS(i);
        }
    }
    cout << endl;
    return f[v];
}

void BFS(){
    queue <int> myQueue;
    myQueue.push(1);
    visited[1] = 1;
    f[1] += val[1];
   
    while(!myQueue.empty()){
        int tempV = myQueue.front();
        //  cout << tempV << endl;
        myQueue.pop();
        for (auto newV: adj[tempV]){
            // cout << newV << '|' << visited[newV] << " ";
            if (visited[newV] == 0){
                
                myQueue.push(newV);
                f[newV] = f[tempV] + val[newV];
                visited[newV] = 1;
            }
        }
        cout << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    k = n - k;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); 
    }

    init(1);
    visited[1] = 1;
    for (auto i: adj[1]){
        // cout << "#" << i << endl;
        f[1] += DFS(i);
    }
    cout << endl;

    for (int i = 1; i <= n; i++){
        // cout << i << ": " << f[i] << endl;
        lists.push_back({f[i], i});
    }

    for (int i = 0;k--;i++){
        val[lists[i].se] = 1;
        // cout << myHeap.top().se << endl;
    }

    init(0);
    BFS();
    
    // for (int i = 1; i <= n; i++){
    //     cout << i << ": " << visited[i] << endl;
    // }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (val[i] == 0){
            ans += f[i];
        }
        cout << i << ": " << val[i] << endl;
        
    }

    cout << ans;

    return 0;
}