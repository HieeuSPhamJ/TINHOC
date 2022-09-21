#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 5 * 1e5 + 10;
const int inf = 1e18;

vector <int> adj[maxN];
int visited[maxN];

queue <int> myQueue;

void BFS(){
    while(!myQueue.empty()){
        int tempV = myQueue.front();
        // cout << "#: " << tempV << endl;
        myQueue.pop();
        for (auto newV: adj[tempV]){
            if (visited[newV] > visited[tempV] + 1){
                visited[newV] = visited[tempV] + 1;
                myQueue.push(newV);
                // cout << newV << " ";
            }
        }
        // cout << endl;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= n; i++){
        visited[i] = inf;
    }
    while(m--){
        int test;
        cin >> test;
        if (test == 1){
            int inp;
            cin >> inp;
            if (visited[inp] == inf){
                cout << -1 << endl;
            }
            else{
                cout << visited[inp] << endl;
            }
        }
        else{
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            if (min(visited[a], visited[b]) == inf){
                continue;
            }
            else if (visited[a] < visited[b]){
                myQueue.push(a);
                BFS();
            }
            else{
                myQueue.push(b);
                BFS();
            }
        }
    }
    return 0;
}