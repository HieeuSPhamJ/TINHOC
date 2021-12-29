#include <bits/stdc++.h>
using namespace std;

const int infinite = 1e9;
const int maxV = 100;
int Start, End;
int E, V;
vector<pair<int, int>> adj[maxV];
int visited[maxV];
int traced[maxV];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myHeap;

void inputReader()
{
    cin >> V >> E;
    for (int i = 1; i <= E; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    cin >> Start >> End;
}

void Dijkstra(int start)
{
    for (int i = 1; i <= maxV; i++)
    {
        visited[i] = infinite;
    }
    myHeap.push(make_pair(0, start));
    visited[start] = 0;
    while (!myHeap.empty())
    {
        pair<int, int> tempV = myHeap.top();
        myHeap.pop();
        if (tempV.first <= visited[tempV.second])
        {
            for (int i = 0; i < adj[tempV.second].size(); i++)
            {
                pair<int, int> neighbor = adj[tempV.second][i];
                int newV = neighbor.first;
                int newWeight = neighbor.second + visited[tempV.second];
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

void check(int end)
{
    cout << visited[end] << endl;
    for (int i = 0; i <= V; i++)
    {
        cout << i << ' ' << traced[i] << endl;
    }
}

int main()
{
    inputReader();
    Dijkstra(Start);
    check(End);
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