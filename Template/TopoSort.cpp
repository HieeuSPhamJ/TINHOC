#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

vector <int> adj[maxN];
int vao[maxN];
int ra[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i =1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ra[a]++;
        vao[b]++;
    }

    queue <int> myQueue;
    for (int i = 1; i <= n; i++){
        if(vao[i] == 0){
            myQueue.push(i);
        }
    }

    vector <int> ans;

    while(!myQueue.empty()){
        int tempV = myQueue.front();
        myQueue.pop();
        ans.push_back(tempV);
        for (auto newV: adj[tempV]){
            vao[newV]--;
            if (vao[newV] == 0){
                myQueue.push(newV);
            }
        }
    }

    for (auto i: ans){
        cout << i << " ";
    }

    return 0;
}