#include<bits/stdc++.h>
// #define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 1e5 + 10;

int n, m, x;
vector <int> adj[maxN];
int X[maxN];
queue <int> myQueue;
ii visited[maxN];

void bfs(){
    for (int i = 0; i <= n; i++){
        visited[i] = {-1, i};
    }
    for (int i = 1; i <= x; i++){
        visited[X[i]] = {0, X[i]};
    }


    // for (int i = 1; i <= n; i++){
    //     cout << i << ": " << visited[i].f << " " << visited[i].s << endl;
    // }

    while (!myQueue.empty()){
        int tempV = myQueue.front();
        myQueue.pop();
        // cout << "# " << tempV << endl;
        for (auto i: adj[tempV]){
            // cout << i << endl;
            if (visited[i].f == -1){
                visited[i] = {visited[tempV].f + 1, visited[tempV].s};
                myQueue.push(i);
                // for (int i = 1; i <= n; i++){
                    // cout << i << ": " << visited[i].f << " " << visited[i].s << endl;
                // }
            }
            else if (visited[i].s != visited[tempV].s){
                // cout << i << " " << tempV << endl;
                cout << visited[i].f + visited[tempV].f + 1;
                exit(1);
            }
        }
        // cout << endl;
        // for (int i = 1; i <= n; i++){
        //     cout << i << ": " << visited[i] << endl;
        // }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    for (int i = 1; i <= x; i++){
        cin >> X[i];
    }

    for (int i = 1; i <= x; i++){
        myQueue.push(X[i]);
    }

    bfs();

    // cout << minDir;



    return 0;
}