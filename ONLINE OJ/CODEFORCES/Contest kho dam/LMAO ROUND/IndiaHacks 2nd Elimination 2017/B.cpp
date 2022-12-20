#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;
 
const int maxN = 2 * 1e5 + 10;
const int N = maxN;

int n, test;
vector <ii> adj[maxN];
int father[maxN][20];
int level[maxN];
int height[maxN];
int st[maxN];
int en[maxN];
int bit[2 * maxN];
int lazy[maxN * 4];
int seg[maxN * 4];
int cnt = 0;
 
void DFS(int node, int daddy){
    st[node] = ++cnt;
    for (auto newNode: adj[node]){
        if (newNode.se == daddy){
            continue;
        }
        father[newNode.se][0] = node;
        height[newNode.se] = height[node] + newNode.fi;
        level[newNode.se] = level[node] + 1;
        DFS(newNode.se, node);
    }
    en[node] = cnt;
}
 
void upbit(int i, int v){
    while(i <= 2 * n){
        bit[i] += v;
        i += (i & (-i));
    }
}
 
void updateDown(int l, int r, int v){
    upbit(l,v);
    upbit(r + 1,-v);
}
 
int getDown(int i){
    int res = 0;
    while(i){
        res += bit[i];
        i -= (i & (-i));
    }
    return res;
}

void setLazy(int i){
    int val = lazy[i];
    lazy[2 * i] += val;
    lazy[2 * i + 1] += val;
    seg[2 * i] += val;
    seg[2 * i + 1] += val;
    lazy[i] = 0;
}

void update(int i, int left, int right, int _left, int _right, int val){
    if (right < _left or _right < left){
        return;
    }
    if (_left <= left and right <= _right){
        seg[i] += val;
        lazy[i] += val;
        return;
    }
    setLazy(i);
    int mid = (left + right) / 2;

    update(2 * i, left, mid, _left, _right, val);
    update(2 * i + 1, mid + 1, right, _left, _right, val);
    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}

int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return 1e18;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }
    setLazy(i);
    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return min(t1,t2);
}

int getUp(int i, int j){
    return get(1, 1, N, i + 1,j + 1);
}

void updateUp(int i, int j, int v){
    update(1, 1, N, i + 1, j + 1, v);
}

void init(){
    level[0] = -1;
    for (int j = 1; j <= log2(n); j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }
 
    for (int i = 1; i <= n; i++){
        updateDown(st[i],st[i],height[i]);
        updateUp(st[i], st[i], height[i]);
    }
}
 
int LCA(int a, int b){
    if (level[a] < level[b]){
        swap(a,b);
    }
    for (int i = log2(level[a]); i >= 0; i--){
        if (level[father[a][i]] >= level[b]){
            a = father[a][i];
        }
    }
 
    if (a == b){
        return a;
    }
 
    for (int i = log2(level[a]); father[a][0] != father[b][0]; i--){
        if (father[a][i] != father[b][i]){
            a = father[a][i];
            b = father[b][i];
        }
    }
 
    return father[a][0];
}
 
int callen(int a, int b){
    int lca = LCA(a, b);
    int res = 0;
    if (lca == a){
        res = getDown(st[b]) - getDown(st[a]);
    }
    else{
        res = getUp(st[a],en[a]) - getDown(st[a]) + getDown(st[b]);
    }
    return res;    
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> test;
    vector <pair<ii,int>> lists;
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
        lists.push_back({{a,b}, w});
    }

    
    DFS(1,1);
    init();

    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        lists.push_back({{a,b}, w});
        updateUp(st[a], st[a], w);
    }

    while(test--){
        int t;
        cin >> t;
        if (t == 1){
            int i, x;
            cin >> i >> x;
            auto &e = lists[i - 1];
            int ne = x - e.se;
            if (i >= n){   
                updateUp(st[e.fi.fi], st[e.fi.fi], ne);     
            }
            else{    
                updateDown(st[e.fi.se], en[e.fi.se], ne);
                updateUp(st[e.fi.se], en[e.fi.se], ne);
            }

            e.se = x;
        }
        else{
            int a, b;
            cin >> a >> b;
            cout << callen(a,b) << endl;
        }
    }


    return 0;
}

/*
2 1 1
2 1 3
2 3 5
2 5 2
1 1 100
2 1 3
1 8 30
2 4 2
2 2 4
*/