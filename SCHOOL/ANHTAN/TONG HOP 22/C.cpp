#include<bits/stdc++.h>
#define ii pair <double,int>
#define fi first
#define se second
#define x first
#define y second
#define val first
#define id second
#define len first
#define num second
#define int long long
using namespace std;

struct iii{
    double val;
    int id,k;
    
};

struct cmp{
    bool operator()(iii& a, iii& b){
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return a.val > b.val;
    }
};

const int maxN = 1e5 + 10;
const int inf = 1e18;

int n, m, K;

vector <ii> adj[maxN];
double visited[maxN][12];
// int dp[maxN][12];

void init(){
    for (int i = 1; i <= n; i++){
        for (int k = 0; k <= K; k++){
            visited[i][k] = inf;
            // cout << i << " " << k << endl;
        }
    }
}

void Dickcha(){
    init();
    // cout << "TEST CAN" << endl;
    priority_queue <iii, vector <iii>, cmp> myHeap;
    myHeap.push({0, 1, 0});
    visited[1][0] = 0;
    

    cout << myHeap.top().val;

    while(!myHeap.empty()){
        iii tempV = myHeap.top();
        myHeap.pop(); 
        // cout << "#" << tempV.id << " " << tempV.k << endl;
        if (tempV.len != visited[tempV.id][tempV.k]){
            continue;
        }
        for (auto newV: adj[tempV.id]){
            for (int k = 0; k <= K - tempV.k; k++){
            // if (visited[tempV.id][tempV.k] + newV.val < visited[newV.id][tempV.k]){
            //     visited[newV.id][tempV.k] = visited[tempV.id][tempV.k] + newV.val;
            //     cout << newV.id << "," << tempV.k << "," << visited[newV.id][tempV.k] << " | ";
            //     myHeap.push({visited[newV.id][tempV.k], newV.id, tempV.k});
            // }
                if (tempV.k + k <= K and visited[tempV.id][tempV.k] + newV.val < visited[newV.id][tempV.k + k]){
                    visited[newV.id][tempV.k + k] = visited[tempV.id][tempV.k] + newV.val;
                    // cout << newV.id << "," << tempV.k + k << "," << visited[newV.id][tempV.k + k] << " | ";
                    myHeap.push({visited[newV.id][tempV.k + k], newV.id, tempV.k + k});
                }
                else{
                    break;
                }
                newV.val /= 2;
            }
        }
        // cout << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> K;

    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }

    Dickcha();

    double ans = 1e8;
    for (int i = 0; i <= K; i++){
        ans = min(ans, visited[n][i]);
    }

    // for (int i = 1; i <= n; i++){
    //     for (int k = 0; k <= K; k++){
    //         cout << visited[i][k] << ' ';
    //     }
    //     cout << endl;
    // }



    cout << fixed << setprecision(2) << ans;

    return 0;
}