#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

vector <int> adj[12];
int check[maxN];
string s;
int visited[maxN];
int n;

void BFS(){
    queue <int> myQueue;
    myQueue.push(0);
    while(!myQueue.empty()){
        int tempV = myQueue.front();
        myQueue.pop();
        if (tempV + 1 <= n and visited[tempV + 1] == -1){
            visited[tempV + 1] = visited[tempV] + 1;
            myQueue.push(tempV + 1);
        }
        if (tempV - 1 >= 0 and visited[tempV - 1] == -1){
            visited[tempV - 1] = visited[tempV] + 1;
            myQueue.push(tempV - 1);
        }
        if (check[s[tempV] - '0']){
            continue;
        }
        for (auto i: adj[s[tempV] - '0']){
            check[s[tempV] - '0'] = 1;
            if (visited[i] == -1){
                visited[i] = visited[tempV] + 1;
                myQueue.push(i);
            }
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s;
    n = (int)s.length() - 1;
    for (int i  = 0; i <= n; i++){
        adj[s[i] - '0'].push_back(i);
    }
    memset(visited, -1, sizeof(visited));
    visited[0] = 0;
    BFS();
    cout << visited[n];
    return 0;
}