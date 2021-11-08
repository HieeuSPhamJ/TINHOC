#include<bits/stdc++.h>
using namespace std;

const int maxN=5003;
const int infinite=INT_MAX-100;
int n,m;
vector <pair<int,long long>> adj[maxN];
priority_queue <pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> myHeap;
long long visited[maxN];
long long countWay=0;

void inputReader(){
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int k,a,b,w;
        cin>>k>>a>>b>>w;
        adj[a].push_back(make_pair(b,w));
        if (k==2){
            adj[b].push_back(make_pair(a,w));
        }
    }
    for (int i=1;i<=maxN;i++){
        visited[i]=infinite;
    }
}

void Dijkstra(){
    myHeap.push(make_pair(0,1));
    visited[1]=0;
    while(!myHeap.empty()){
        pair<long long,int> tempV=myHeap.top();
        myHeap.pop();
        if (tempV.first<=visited[tempV.second]){
            for (int i=0;i<adj[tempV.second].size();i++){
                pair<long long,int> newV=adj[tempV.second][i];
                if (newV.second+tempV.first<=visited[newV.first]){
                    if (newV.first==n){
                        if (newV.second+tempV.first<visited[newV.first]){
                            countWay=0;
                        }
                        countWay++;
                    }
                    visited[newV.first]=newV.second+tempV.first;
                    myHeap.push(make_pair(visited[newV.first],newV.first));
                }
            }
        }
    }

}

void Check(){
    cout<<visited[n]<<' '<<countWay;
}


int main(){
    inputReader();
    Dijkstra();
    Check();
    return 0;
}
