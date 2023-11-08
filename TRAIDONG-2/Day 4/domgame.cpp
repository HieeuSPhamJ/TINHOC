#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 10010;

int n, m;
char a[maxN][maxN]; 
vector <int> adj[maxN];
int ml[maxN];
int mr[maxN];
int dist[maxN];
int N;
 
bool canop(){
    queue <int> q;
    for (int i = 1; i <= N; i++){
        if (ml[i] == 0){
            q.push(i);
            dist[i] = 0;
        }
        else{
            dist[i] = -1;
        }
    }
    int can = 0;
 
    while(!q.empty()){
        int t = q.front();
        q.pop();
 
        for (auto i: adj[t]){
            if (mr[i] == 0){
                can = 1;
            }
            else  if(dist[mr[i]] < 0){
                dist[mr[i]] = dist[t] + 1;
                q.push(mr[i]);
            }
        }
    }
 
    return can;
}
 
bool Try(int node){
    for (auto i: adj[node]){
        if (mr[i] == 0){
            ml[node] = i;
            mr[i] = node;
            return 1;
        }
        if ((dist[mr[i]] == dist[node] + 1) and Try(mr[i])){
            ml[node] = i;
            mr[i] = node;
            return 1;
        }
    }
    return 0;
}
 
int cac(){
    while(canop()){
        // cout << "try" << endl;
        for (int i = 1; i <= N; i++){
            if (ml[i] == 0){
                Try(i);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= N; i++){
        res += (ml[i] != 0);
    }
    return res;
}

vector <ii> ls;
vector <int> ln;  

void nenso(){
    set <int> s;
    for (auto i: ln){
        s.insert(i);
    }
    int cnt = 0;
    map <int,int> cv;
    for (auto i: s){
        cnt++;
        cv[i] = cnt;
        // cout << i << ": " << cnt << endl;
    }
    for (auto &i: ln){
        i = cv[i];
    }
    for (auto &i: ls){
        i.fi = cv[i.fi];
        i.se = cv[i.se];
    }
}

void add(int i, int j, int u, int v){
    if ((i + j) % 2){
        swap(i,u);
        swap(j,v);
    }
    // cout << "add " << i << " " << j << " " << u << " " << v << endl;
    ls.push_back({(i - 1) * m + j,(u - 1) * m + v});
    // cout << ls.back().fi << " " << ls.back().se << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    int k = 0;
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= m + 1; j++){
            a[i][j] = '#';
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            if (a[i][j] == '#'){
                k++;
            }
        }
    }

    k = (n * m - k) / 2 - 1;
    if (k == 0){
        cout << 0 << endl;
        return 0;
    }
  
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i][j] != '#'){
                ln.push_back((i - 1) * m + j);
                if (a[i - 1][j] != '#'){
                    add(i,j,i-1,j);
                }
                if (a[i][j - 1] != '#'){
                    add(i,j,i,j - 1);
                }
            }
        }
    }

    nenso();
    N = ln.size();
    if (N / 2 * N / 2 >= 1e6){
        cout << 1e6 << endl;
        return 0;
    }
    int res = 0;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j < i; j++){
            for (int t = 1; t <= N; t++){
                adj[t].clear();
                dist[t] = 0;
                ml[t] = 0;
                mr[t] = 0;
            }
            // cout << i << " " << j << ": " << endl;
            for (auto x: ls){
                if (x.fi != i and x.fi != j and x.se != i and x.se != j){
                    adj[x.fi].push_back(x.se);
                    // cout << x.fi << ' ' << x.se << endl;
                }
            }
            if (cac() < k){
                // cout << cac() << endl;
                res++;
            }
        }
    }

    cout << min((int)(1e6), res) << endl;
    // adj[4].push_back(3);
    // cout << cac();

    return 0;
}