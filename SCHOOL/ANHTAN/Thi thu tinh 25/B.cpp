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

const int inf = 1e18;
const int maxN = 2 * 1e5 + 10;

int n, m, k;
vector <ii> adj[maxN];
int visited1[maxN];
int visitedn[maxN];
priority_queue <ii, vector <ii>, greater <ii>> myHeap;

void init(){
    for (int i = 1; i < maxN; i++){
        visited1[i] = inf;
        visitedn[i] = inf;
    }
}

void Dickcha1(){
    myHeap.push({0, 1});
    visited1[1] = 0;
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop(); 
        // cout << "#" << tempV.id << endl;
        if (tempV.len != visited1[tempV.id]){
            continue;
        }
        for (auto newV: adj[tempV.id]){
            if (visited1[tempV.id] + newV.val < visited1[newV.id]){
                // cout << newV.id << ' ';
                visited1[newV.id] = visited1[tempV.id] + newV.val;
                myHeap.push({visited1[newV.id], newV.id});
            }
        }
        // cout << endl;
    }
}
void Dickchan(){
    myHeap.push({0, n});
    visitedn[n] = 0;
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop(); 
        // cout << "#" << tempV.id << endl;
        if (tempV.len != visitedn[tempV.id]){
            continue;
        }
        for (auto newV: adj[tempV.id]){
            if (visitedn[tempV.id] + newV.val < visitedn[newV.id]){
                // cout << newV.id << ' ';
                visitedn[newV.id] = visitedn[tempV.id] + newV.val;
                myHeap.push({visitedn[newV.id], newV.id});
            }
        }
        // cout << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int a, b, v;
        cin >> a >> b >> v;
        adj[a].push_back({v,b});
        // adj[b].push_back({v,a});
    }
    init();
    Dickcha1();
    Dickchan();
    for (int test = 1; test <= k; test++){
        int a, b;
        cin >> a >> b;
        int ans = inf;
        for (int i = 1; i <= n; i++){
			if (visited1[i] == inf  or visitedn[i] == inf){
				continue;
			}
            ans = min(ans, visited1[i] * a + visitedn[i] * b);
            // cout << visited1[i] * a + visitedn[i] * b << ' ';
        }
        cout << ans << endl;
    }
    return 0;
}