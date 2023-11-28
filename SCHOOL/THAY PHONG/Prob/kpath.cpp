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
#define iii pair <int,ii>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
const int inf = 1e18;

vector <ii> adj[maxN];
int root[maxN];
int visited[maxN];
vector <int> valid;

int findRoot(int n){
    if (n == root[n]){
        return n;
    }
    return root[n] = findRoot(root[n]);
}

void reset(){
    for (auto i: valid){
        visited[i] = inf;
    }
}

void dickcha(int Start){
    reset();
    priority_queue <ii, vector <ii>, greater <ii>> myHeap;
    myHeap.push({0, Start});
    visited[Start] = 0;
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

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector <iii> lists;
    for (int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        lists.push_back({c,{a,b}});
    }
    sort(lists.begin(), lists.end());
    set <int> validSet;
    for (int i = 0; i < k; i++){
        int a = lists[i].se.fi;
        int b = lists[i].se.se;
        int c = lists[i].fi;
        // cout << a << " " << b << " " << c << endl;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
        // int u = findRoot(a);
        // int v = findRoot(b);
        validSet.insert(a);
        validSet.insert(b);
        // if (u != v){
        //     root[u] = v;
        // }
    }

    for (auto i: validSet){
        valid.push_back(i);
    }

    vector <int> ans;

    for (auto i: valid){
        dickcha(i);
        for (auto j: valid){
            if (j != i){
                ans.push_back(visited[j]);
            }
        }
    }

    sort(ans.begin(), ans.end());

    // for (auto i: ans){
    //     cout << i << " ";
    // }
    // cout << endl;

    cout << ans[k * 2 - 1];


    return 0;
}