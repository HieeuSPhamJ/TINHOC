#include <bits/stdc++.h>
using namespace std;

const long long infinite = 1e9;
const long long maxV = 1e7;
long long Start, End;
long long E, V;
vector<pair<long long, long long>> adj[maxV];
long long visited[maxV];
long long traced[maxV];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> myHeap;

void inputReader()
{
    cin >> V >> E;
    cin >> Start >> End;
    for (long long i = 1; i <= E; i++)
    {
        long long a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
}

void Dijkstra(long long start)
{
    for (long long i = 1; i < maxV; i++)
    {
        visited[i] = infinite;
    }
    myHeap.push(make_pair(0, start));
    visited[start] = 0;
    while (!myHeap.empty())
    {
        pair<long long, long long> tempV = myHeap.top();
        myHeap.pop();
        if (tempV.first <= visited[tempV.second])
        {
            for (long long i = 0; i < adj[tempV.second].size(); i++)
            {
                pair<long long, long long> neighbor = adj[tempV.second][i];
                long long newV = neighbor.first;
                long long newWeight = neighbor.second + visited[tempV.second];
                if (newWeight <= visited[newV])
                {
                    myHeap.push(make_pair(newWeight, newV));
                    visited[newV] = newWeight;
                    traced[newV] = tempV.second;
                }
            }
        }
    }
}

void check(long long v)
{
    for (long long i = 0; i <= V; i++){
        cout << i << ' ' << visited[i] << endl;
    }
    // cout << v << ' ';
}

void path(long long v){
    if (visited[v] != 0){
        path(traced[v]);
    }
    cout << v << ' ';
}

int main()
{
    freopen("Dijsktra.INP", "r", stdin);
    freopen("Dijsktra.OUT", "w", stdout);
    inputReader();
    Dijkstra(Start);
    cout << visited[End] << endl;
    // check(End);
    path(End);
    return 0;
}

/*

4 4
1 2 5
2 4 7
1 3 1
2 3 2
1 4

*/