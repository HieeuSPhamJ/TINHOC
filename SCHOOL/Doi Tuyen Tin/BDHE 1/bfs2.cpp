#include<bits/stdc++.h>
// #define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 1e5 + 10;

int n;
vector <int> adj[maxN];
int visited[maxN];
int path[maxN];
queue <int> myQueue;


void bfs(int start){
    for (int i = 0; i < maxN; i++){
        visited[i] = -1;
    }

    visited[start] = 0;

    myQueue.push(start);

    while(!myQueue.empty()){
        int tempV = myQueue.front();
        myQueue.pop();
        for (auto i: adj[tempV]){
            if (visited[i] == -1){
                visited[i] = visited[tempV] + 1;
                path[i] = tempV;
                myQueue.push(i);
            }
        }
    }
    
}

int getMax(){
    int ans = 0;
    int tempVal = 0;
    for (int i = 1; i <= n; i++){
        if (tempVal <= visited[i]){
            ans = i;
            tempVal = visited[i];
        }
    }

    return ans;
}

int getLen(){
    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(ans, visited[i]);

    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    bfs(1);
    int a = getMax();

    // cout << a;
    
    bfs(a);

    int b = getMax();

    int len = getLen();

    // cout << b;


    cout << len << endl;

    // if (len % 2 == 1){
    //     cout << 2;
    //     int tempV = b;
    //     len /= 2;
    //     while(len--){
    //         tempV = path[tempV];
    //     }
    //     cout << endl;
    //     cout << min(tempV,path[tempV]) << ' ' << max(tempV,path[tempV]);
    // }
    // else{
    //     cout << 1;
    //     int tempV = b;
    //     len /= 2;
    //     while(len--){
    //         tempV = path[tempV];
    //     }
    //     cout << endl;
    //     cout << tempV;
    // }
    // cout << endl;
    
    

    // cout << a << ' ' << b << endl;

    

    return 0;
}