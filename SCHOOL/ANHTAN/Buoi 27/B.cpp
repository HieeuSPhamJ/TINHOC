#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define x first
#define y second
#define val first
#define id second
#define len first
#define num second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2010;
const int inf = 1e18;

vector <ii> adj[maxN];
int visited[4][maxN];
priority_queue <ii, vector <ii>, greater <ii>> myHeap;
int minLen[maxN][maxN];

void init(){
    for (int i = 0; i <= maxN; i++){
        visited[0][i] = inf;
        visited[1][i] = inf;
    }
}



void Dickcha(int type, int Start){
    myHeap.push({0, Start});
    visited[type][Start] = 0;
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop(); 
        // cout << "#" << tempV.id << endl;
        if (tempV.len != visited[type][tempV.id]){
            continue;
        }
        for (auto newV: adj[tempV.id]){
            if (visited[type][tempV.id] + newV.val < visited[type][newV.id]){
                // cout << newV.id << ' ';
                visited[type][newV.id] = visited[type][tempV.id] + newV.val;
                myHeap.push({visited[type][newV.id], newV.id});
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
    int n, m, k;
    cin >> n >> m >> k;
    vector <ii> listE;
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
        listE.push_back({a,b});
        // listE.push_back({b,a});
    }
    int res = 0;
    for (int i = 1; i <= k; i++){
        int a, b;
        cin >> a >> b;
        if (a == b){
            for (int j = 0; j < listE.size(); j++)
                minLen[i][j] = 0;
            continue;
        }
        init();
        Dickcha(0,a);
        Dickcha(1,b);
        // for (int i = 1; i <= n; i++){
        //     cout << visited[0][i] << " " << visited[1][i] << endl;
        // }
        // cout << "------" << endl;
        int ans = 1e18;
        
        for (int j = 0; j < listE.size(); j++){
            ii e = listE[j];
            minLen[i][j] = visited[0][e.first] + visited[1][e.second];
            minLen[i][j] = min(minLen[i][j],visited[0][e.second] + visited[1][e.first]);
            // ans = min(ans, visited[0][e.first] + visited[1][e.second]);

            // cout << e.first << " " << e.second << " " << visited[0][e.first] << " " << visited[1][e.second] << endl;
    
        }
        // res += ans;
        // cout << ans << endl;
    }
    // cout << res;

    int ans = 1e18;

    for (int i = 0; i < listE.size(); i++){
        int tempAns = 0;
        // cout << listE[i].first << "," << listE[i].second << ": " << endl;
        for (int j = 1; j <= k; j++){
            // cout << minLen[j][i] << " ";
            tempAns += minLen[j][i];
        }
        // cout << endl;
        ans = min(ans, tempAns);
    }

    cout << ans;
    return 0;
}