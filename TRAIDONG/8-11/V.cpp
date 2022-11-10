#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;


int n, m, k;
int X = 0;
vector <int> adj[maxN];
int visited[maxN];
int path[maxN];
int color[maxN];

void bfs(int start){
    queue <int> myQueue;
    for (int i = 0; i < maxN; i++){
        visited[i] = -1;
    }
    visited[start] = 0;
    myQueue.push(start);
    while(!myQueue.empty()){
        int tempV = myQueue.front();
        myQueue.pop();
        for (auto i: adj[tempV]){
            if (visited[i] == -1){
                visited[i] = visited[tempV] + 1;
                path[i] = tempV;
                myQueue.push(i);
            }
        }
    } 
}
int getMax(){
    int ans = 0;
    int tempVal = 0;
    for (int i = 1; i <= n; i++){
        if (tempVal <= visited[i]){
            ans = i;
            tempVal = visited[i];
        }
    }
    return ans;
}
int getLen(){
    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(ans, visited[i]);
    }
    return ans;
}

vector <int> ANS;

void init(){
    bfs(1);
    int a = getMax();
    bfs(a);
    int b = getMax();
    int len = getLen() + 1;
    X = min(k, len);
    // cout << "AB: " << a << " " << b << endl;
    int c = 1;
    while(1){
        // cout << b << " ";
        color[b] = c;
        ANS.push_back(b);
        c++;
        b = path[b];
        if (c > X){
            break;
        }
    }
    // cout << endl;
}


int father[maxN];
 
int findFather(int child){
    if (child == father[child]){
        return child;
    }
    return father[child] = findFather(father[child]);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        father[i] = i;
    }

    vector <ii> E;

    for (int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        int a = findFather(x);
        int b = findFather(y);
        if (a == b){
            continue;
            E.push_back({x,y});
        }
        father[a] = b;

        adj[x].push_back(y);
        adj[y].push_back(x);

        // cout << x << " " << y << endl;
    }

    init();

    for (auto i: E){
        adj[i.fi].push_back(i.se);
        adj[i.se].push_back(i.fi);
    }    

    queue <int> Q;

    for (int i = 1; i <= n; i++){
        // cout << color[i] << endl;
        if (color[i]){
            for (auto x: adj[i]){
                if (!color[x]){
                    Q.push(x);
                }
            }
        }
    }

    while(!Q.empty()){
        int t = Q.front();
        Q.pop();
        vector <int> lists;
        for (auto i: adj[t]){
            if (color[i]){
                lists.push_back(color[i]);
            }
            else{
                Q.push(i);
            }
        }
        sort(lists.begin(), lists.end());
        int c = 1;
        for (auto i: lists){
            if (c != i){
                break;
            }
            c++;
        }
        color[t] = c;
    }
    cout << X << " ";
    for (int i = 1; i <= n; i++){
        cout << color[i] << " ";
    }
    cout << endl;

    for (auto i: ANS){
        cout << i << " ";
    }


    return 0;
}