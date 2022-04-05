#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e3;
const int oo = 1e8;

vector <pair <int,int>> adj[maxN];
int e, v;
int Start, End;
int visited[maxN];
int trace[maxN];
priority_queue<pair<int,int>> myHeap;

void input(){
    cin >> v >> e;
    for (int i = 1; i <= e; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
        visited[a] = oo;
        visited[b] = oo;
        trace[a] = -1;
        trace[b] = -1;
    }
    cin >> Start >> End;
}

void Ditcha(){
    myHeap.push({0, Start});
    visited[Start] = 0;
    while(!myHeap.empty()){
        pair <int, int> tempV = myHeap.top();
        myHeap.pop();
        for (int i = 0; i < (int)adj[tempV.second].size(); i++){
            pair <int, int> newV = adj[tempV.second][i];
            if (tempV.first + newV.second <= visited[newV.first]){
                visited[newV.first] = tempV.first + newV.second;
                trace[newV.first] = tempV.second;
                myHeap.push({visited[newV.first], newV.first});

            }
        }
    }   

}

void output(){
    for (int i = 1; i <= e; i++){
        cout << trace[i] << ' ';
    }
    cout << endl;
    cout << visited[End];
}


int main(){
    input();
    Ditcha();
    output();

    return 0;
}