#include<bits/stdc++.h>
using namespace std;

const int infinity = 1e9;


int E, V;
vector <pair <int,int>> adj[1000];
int visited[1000];
int dir[1000];
int Start, End;
priority_queue <pair <int, int>> myHeap;


void inputRead(){
    cin >> V >> E;
    for (int i = 1; i<= E; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
        
    }
    for (int i = 0; i <= V; i++){
        visited[i] = infinity;
        dir[i] = -1;
    }
    cin >> Start >> End;
}


void Dijstra(){
    myHeap.push(make_pair(0, Start));
    while(!myHeap.empty()){
        pair <int, int> tempV = myHeap.top();
        myHeap.pop();
        for (int i = 0; i < adj[tempV.second].size(); i++){
            pair <int, int> newV = adj[tempV.second][i];
            int newWeight = newV.second + tempV.first;
            if (newWeight <= visited[newV.first]){
                visited[newV.first] = newWeight;
                myHeap.push(make_pair(newWeight, newV.first));
                dir[newV.first] = tempV.second;

            }
        }
    }

}


void outputWrite(){
    int tempV = dir[End];
    cout << End << endl;
    while(tempV != Start){
        cout << dir[tempV] << endl;
        tempV = dir[tempV];
    }
    // for (int i = 0; i <= V; i++){
    //     cout << i << ": " << dir[i] << endl;
    // }
}


int main(){
    inputRead();
    Dijstra();
    outputWrite();

}