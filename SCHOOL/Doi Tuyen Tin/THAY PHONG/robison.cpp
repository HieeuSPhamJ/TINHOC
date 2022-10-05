#include<bits/stdc++.h>
#define ii pair <int,int>
#define iii pair <ii,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'

using namespace std;

const int maxN = 2010;
const int inf = 1e18;

int k,n,m;
int Start, End;
int visited[210][maxN];
vector <iii> adj[maxN];
priority_queue <iii, vector <iii>, greater <iii>> myHeap;

void init(){
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= 200; j++){
            visited[j][i] = inf;
        }
    }
}

void Dickcha(){
    init();
    myHeap.push({{0,k}, Start});
    visited[k][Start] = 0;
    while(!myHeap.empty()){
        iii tempV = myHeap.top();
        myHeap.pop(); 
        // cout << "#" << tempV.se << endl;
        for (auto newV: adj[tempV.se]){
            int newWeight = visited[tempV.fi.se][tempV.se] + newV.fi.fi;
            int dept = tempV.fi.se - newV.fi.se;
            if (dept > 0 and newWeight < visited[dept][newV.se]){
                // cout << newV.id << ' ';
                visited[dept][newV.se] = newWeight;
                myHeap.push({{newWeight, dept}, newV.se});
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
    cin >> k >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b, w, h;
        cin >> a >> b >> w >> h;
        adj[a].push_back({{w,h}, b});
        adj[b].push_back({{w,h}, a});
    }
    cin >> Start >> End;
    Dickcha();

    int ans = inf;
    for (int i = 1; i <= 200; i++){
        if (visited[i][End] != inf){
            ans = min(visited[i][End],ans);
        }
    }
    if (ans != inf){
        cout << ans;
    }
    else{
        cout << -1;
    }
    
    return 0;
}