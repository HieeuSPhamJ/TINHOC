#include<bits/stdc++.h>
using namespace std;

const int maxN=1002;
const int infinite=INT_MAX-1;

int N,E,T,M;
vector <pair<int,int>> adj[maxN];
int visited[maxN];
priority_queue <pair<int,int>> myHeap;


void inputReader(){
    cin>>N>>E>>T>>M;
    for (int i=1;i<=M;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[b].push_back(make_pair(a,w));
    }

    for (int i=0;i<=maxN;i++){
        visited[i]=infinite;
    }

}

void Dijkstra(){
    myHeap.push(make_pair(0,E));
    visited[E]=0;
    while(!myHeap.empty()){
        pair <int,int> tempV=myHeap.top();
        myHeap.pop();
        if (tempV.first<=visited[tempV.second]){
            for (int i=0;i<adj[tempV.second].size();i++){
                pair <int,int> newV=adj[tempV.second][i];
                if (newV.second+visited[tempV.second]<=visited[newV.first]){
                    visited[newV.first]=newV.second+visited[tempV.second];
                    myHeap.push(make_pair(visited[newV.first],newV.first));
                }
            }
        }
    }
}

void outputWriter(){
    int count=0;
    for (int i=0;i<=N;i++){
        if (visited[i]<=T){
            count++;
        }
        // cout<<visited[i]<<endl;
    }
    cout<<count;
}

int main(){
    inputReader();
    Dijkstra();
    outputWriter();
    return 0;
}