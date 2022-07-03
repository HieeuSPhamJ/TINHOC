#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

const int maxN = 2 * 1e5 + 10;

int visitedn[maxN];
vector <int> adj[maxN];
int visited1[maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        visitedn[i] = -1;
        visited1[i] = -1;
    }
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue <int> myQueue;
    myQueue.push(n);
    visitedn[n] = 0;

    while(!myQueue.empty()){
        int tempV = myQueue.front();
        // cout << tempV << endl;
        myQueue.pop();
        for (auto i: adj[tempV]){
            if (visitedn[i] == -1){
                visitedn[i] = visitedn[tempV] + 1;
                myQueue.push(i);
                // cout << i << ' ';
            }
        }
        // cout << endl;
    }

    myQueue.push(1);
    visited1[1] = 0;

    while(!myQueue.empty()){
        int tempV = myQueue.front();
        // cout << tempV << endl;
        myQueue.pop();
        for (auto i: adj[tempV]){
            if (visited1[i] == -1){
                visited1[i] = visited1[tempV] + 1;
                myQueue.push(i);
                // cout << i << ' ';
            }
        }
        // cout << endl;
    }

    for (int i = 1; i <= n; i++){
        if (visitedn[i] < 0 or visited1[i] < 0){
            cout << -1 << ' ';
            continue;
        }
        cout << visitedn[i] + visited1[i] << ' ';
    }

    return 0;
}