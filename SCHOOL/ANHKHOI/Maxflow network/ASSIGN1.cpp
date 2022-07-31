#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxN = 1000;
const int inf = 1e18;
int n, m;
int End, Start;
int d[maxN], c[maxN][maxN], f[maxN][maxN];
int dfs[maxN], t = 0;
vector<int> adj[maxN];

bool bfs(int End, int Start) {
    memset(d, 0, sizeof d);
    queue<int> myQueue;
    myQueue.push(End);
    d[End] = 1;
    while (myQueue.size()) {
        int u = myQueue.front();
        myQueue.pop();
        if (u == Start)
            return true;
        for (int v : adj[u])
            if (!d[v] && f[u][v] < c[u][v]) {
                myQueue.push(v);
                d[v] = d[u] + 1;
            }
    }
    return false;
}

int visit(int u, int Min) {
    if (u == Start)
        return Min;
    if (dfs[u] != t)
        dfs[u] = t;
    else
        return 0;

    for (int v : adj[u])
        if (f[u][v] < c[u][v])
            if (dfs[v] != t && d[v] == d[u] + 1)
                if (int x = visit(v, min(Min, c[u][v] - f[u][v]))) {
                    f[u][v] += x;
                    f[v][u] -= x;
                    return x;
                }
    return 0;
}

void addOne(int x, int y, int z){
    adj[x].push_back(y);
    adj[y].push_back(x);
    c[x][y] += z;
}

void addTwo(int x, int y, int z){
    adj[x].push_back(y);
    adj[y].push_back(x);
    c[x][y] += z;
    c[y][x] += z;
}

void resetAll(){
    for (int i = 0; i < maxN; i++){
        d[i] = 0;
        adj[i].clear();
    }
    for (int i = 0; i < maxN; i++){
        for (int j = 0; j < maxN; j++){
            f[i][j] = 0;
            c[i][j] = 0;
        }
    }
}

struct iii{
    int a, b, val;
};

vector <iii> lists;

bool check(int time){
    resetAll();
    cout << "#" << time << "#" << endl;
    for (int i = 1; i <= n; i++){
        addOne(Start, i, 1);
        addOne(i + n, End, 1);
        cout << Start << " " << i << " " << 1 << endl;
        cout << i + n << " " << End << " " << 1 << endl;
    }
    for (auto i: lists){
        if (i.val <= time){
            addOne(i.a, i.b, 1);
            cout << i.a << " " << i.b << " " << 1 << endl;
        }
    }
    int Sum = 0;
    while (bfs(End, Start)) {
        while (int x = (t++, visit(End, inf))) {
            Sum += x;
        }
    }
    cout << Sum << endl;
    if (Sum == n){
        return 1;
    }
    return 0;
}

signed main() {
    cin >> n;
	Start = 0;
	End = n + n + 1;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int a = i;
            int b = j + n;
            int inp;
            cin >> inp;
            lists.push_back({min(a, b), max(a, b), inp});
        }
    }
    
    int left = 1;
    int right = 1e18;
    int ans = 1e18;
    // while(left <= right){
    //     int time = (left + right) / 2;
    //     if (check(time)){
    //         ans = min(ans, time);
    //         right = time - 1;
    //     }
    //     else{
    //         left = time + 1;
    //     }
    // }
    int temp = check(5);
    cout << ans;
}