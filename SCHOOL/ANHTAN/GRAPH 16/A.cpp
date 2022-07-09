#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

const int infinity = 1e9;
const int maxN = 1e5 + 10;

int m, n;
vector <pair <int,int>> adj[maxN];
int visited[maxN];
priority_queue <ii, vector <ii>, greater <ii>> myHeap;

void Dijstra(){
    myHeap.push(make_pair(0, 1));
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop();
        if (visited[tempV.s] != tempV.f){
            continue;
        }
        for (int i = 0; i < adj[tempV.second].size(); i++){
            ii newV = adj[tempV.second][i];
            int newWeight = newV.second + tempV.first;
            if (newWeight < visited[newV.first]){
                visited[newV.first] = newWeight;
                myHeap.push(make_pair(newWeight, newV.first));

            }
        }
    }

}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i<= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }
    for (int i = 0; i <= n; i++){
        visited[i] = infinity;
    }
    visited[1] = 0;

    Dijstra();
    
    cout << visited[n];
}