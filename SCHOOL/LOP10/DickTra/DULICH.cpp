#include<bits/stdc++.h>
using namespace std;

const int maxN = 110;
const int inf = 110000;

int n, a, b;
vector <pair<int,int>> adj[maxN];
priority_queue <pair<int,int>> myHeap;
int quantity[maxN];
int prevCity[maxN] = {0};

void Path(int v){
    // cout << prevCity[v] << v;
    if (prevCity[v] != 0){
        Path(prevCity[v]);
        cout << ' ' << v;
    }
}

int main(){
    freopen("DULICH.INP", "r", stdin);
    freopen("DULICH.OUT", "w", stdout);
    cin >> n >> a >> b;
    int s, e, w;
    while(cin >> s >> e >> w){
        adj[s].push_back({e,w});
        // cout << s << ' ' << e << ' ' << w << endl;
    }
    for (int i = 1; i <= n; i++){
        quantity[i] = -1;
    }
    myHeap.push({inf,a});
    quantity[a] = inf;
    while(!myHeap.empty()){
        pair <int,int> tempCity = myHeap.top();
        myHeap.pop();
        for (auto nextCity: adj[tempCity.second]){
            int nextWeight = min(nextCity.second, tempCity.first);
            if (nextWeight > quantity[nextCity.first]){
                quantity[nextCity.first] = nextWeight;
                myHeap.push({nextWeight, nextCity.first});
                prevCity[nextCity.first] = tempCity.second;
            }
        } 
    }
    cout << quantity[b] << endl;
    // for (int i = 1;i <= n; i++){
    //     cout << i << ' ' << prevCity[i] << endl;
    // }
    cout << a;
    Path(b);
    return 0;
}