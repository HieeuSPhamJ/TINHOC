#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1010;
const int maxMask = (1 << 11);
const int inf = 1e18;

int visited[maxN][maxMask];
vector <ii> adj[maxN];

void init(){
    for (int i = 1; i < maxN; i++){
        for (int j = 0; j < maxMask; j++){
            visited[i][j] =inf;
        }
    }
}

void dickcha(int Start){
    init();
    queue <ii> myHeap;
    myHeap.push({0,Start});
    visited[Start][0] = 0;
    
    while(!myHeap.empty()){
        ii tempV = myHeap.front();
        myHeap.pop();
        // cout << "#" << tempV.se << endl;
        for (auto newV: adj[tempV.se]){
            if (visited[newV.se][tempV.fi | newV.fi] == inf){
                // cout << newV.se << " ";
                visited[newV.se][tempV.fi | newV.fi] = tempV.fi | newV.fi;
                myHeap.push({visited[newV.se][tempV.fi | newV.fi], newV.se});
            }
        }
        // cout << endl;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a}); 
    }
    int Start, End;
    cin >> Start >> End;
    dickcha(Start);
    int ans = inf;
    for (int i = 0; i < maxMask; i++){
        ans = min(ans, visited[End][i]);
    }

    if (ans == inf){
        cout << -1;
    }
    else{
        cout << ans;
    }

    return 0;
}