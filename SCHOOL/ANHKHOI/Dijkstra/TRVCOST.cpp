#include<bits/stdc++.h>
using namespace std;

const int maxCity=502;
const int infinite=50004;

int N;
vector <pair<int,int>> adj[maxCity];
int visited[maxCity];
int Start;
priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> myHeap;


void inputReader(){
    cin>>N;
    for (int i=1;i<=N;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }
    for (int i=0;i<=maxCity;i++){
        visited[i]=infinite;
    }
    cin>>Start;
}

void Dijkstra(){
    myHeap.push(make_pair(0,Start));
    visited[Start]=0;
    while(!myHeap.empty()){
        pair <int,int> tempV=myHeap.top();
        myHeap.pop();
        if (tempV.first<=visited[tempV.second]){
            for (int i=0;i<adj[tempV.second].size();i++){
                pair <int,int> newV=adj[tempV.second][i];
                if (tempV.first+newV.second<=visited[newV.first]){
                    visited[newV.first]=tempV.first+newV.second;
                    myHeap.push(make_pair(visited[newV.first],newV.first));
                }
            }
        }
    }

}

void outputWriter(){
    int test;
    cin>>test;
    // cout<<test<<' '<<'#'<<endl;
    while(test--){
        int Q;
        cin>>Q;
        if (visited[Q]!=infinite){
            cout<<visited[Q];
        }
        else{
            cout<<"NO PATH";
        }
        cout<<endl;
    }
    // cout<<visited[4];
}

int main(){
    inputReader();
    Dijkstra();
    outputWriter();
    return 0;
}