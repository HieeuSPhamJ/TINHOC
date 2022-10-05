#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define val first
#define id second
#define len first
#define num second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int inf = 1e18;
const int maxN = 1e5 + 10;

struct iii{
    int a, b, w;
};

int n, m, test, MST;

vector <ii> adj[maxN];
int visited[maxN];
priority_queue <ii, vector <ii>, greater <ii>> myHeap;
vector <iii> E;
int father[maxN];
 
bool cmp(iii a, iii b){
    return a.w < b.w;
}
 
int findFather(int child){
    if (child == father[child]){
        return child;
    }
    return father[child] = findFather(father[child]);
}

void Dickcha(){
    myHeap.push({0, 1});
    visited[1] = 0;
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop(); 
        // cout << "#" << tempV.id << endl;
        if (tempV.len != visited[tempV.id]){
            continue;
        }
        for (auto newV: adj[tempV.id]){
            if (visited[tempV.id] + newV.val < visited[newV.id]){
                // cout << newV.id << ' ';
                visited[newV.id] = visited[tempV.id] + newV.val;
                myHeap.push({visited[newV.id], newV.id});
            }
        }
        // cout << endl;
    }
}
 
void Krukal(){
    sort(E.begin(), E.end(), cmp);
    for (auto tempE: E){
        int a = findFather(tempE.a);
        int b = findFather(tempE.b);
        if (a == b){
            continue;
        }
        MST += tempE.w;
        father[a] = b;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> test;
    for (int i = 1; i <= n; i++){
        visited[i] = inf;
        father[i] = i;
    }
    
    for (int i = 1; i<= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
        E.push_back({a,b,w});
    }

    Krukal();
    Dickcha();

    while(test--){
        int q;
        cin >> q;
        if (q == 0){
            int x;
            cin >> x;
            if (visited[x] == inf){
                cout << -1 << endl;
                continue;
            }
            cout << visited[x] << endl;
        }
        else{
            cout << MST << endl;
        }
    }

    return 0;
}