#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 4 * 1e5 + 10;

int a[maxN];
int seg[4 * maxN];
int st[maxN];
int en[maxN];
int lazy[4 * maxN];
int cnt = 1;
vector <int> adj[maxN];

void dfs(int i, int dad){
    st[i] = cnt++;
    for (auto j: adj[i]){
        if (dad == j){
            continue;
        }
        dfs(j,i);
    }
    en[i] = cnt - 1;
}

void setLazy(int i){
    int v = lazy[i];
    if (v == 0){
        return;
    }
    lazy[2 * i] = v;
    lazy[2 * i + 1] = v;
    seg[2 * i] = v;
    seg[2 * i + 1] = v;
    lazy[i] = 0;
}

void update(int i, int left, int right, int LEFT, int RIGHT, int val){
    // cout << left << " " << right << " " << LEFT << " " << RIGHT << " " << val << endl;
    if (right < LEFT or RIGHT < left){
        return;
    }
    if (LEFT <= left and right <= RIGHT){
        seg[i] = val;
        lazy[i] = val;
        // cout << "#" << i << " " << seg[i] << endl;
        return;
    }

    setLazy(i);

    int mid = (left + right) / 2;

    update(2 * i, left, mid, LEFT, RIGHT, val);
    update(2 * i + 1, mid + 1, right, LEFT, RIGHT, val);

    seg[i] = seg[2 * i] | seg[2 * i + 1];
}

int get(int i, int left, int right, int LEFT, int RIGHT){
    if (right < LEFT or RIGHT < left){
        return 0;
    }
    if (LEFT <= left and right <= RIGHT){    
        // cout << "!" << LEFT << " " << RIGHT << "|" << left << " " << right << endl;
        // cout << "#" << seg[i] << endl;
        return seg[i];
    }

    setLazy(i);

    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, LEFT, RIGHT);
    int t2 = get(2 * i + 1, mid + 1, right, LEFT, RIGHT);
    // cout << "!" << LEFT << " " << RIGHT << "|" << left << " " << mid << " " << mid + 1 << " " << right << endl;
    // cout << "%" << t1 << " " << t2 << endl;
    return t1 | t2;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,1);

    for (int i = 1; i <= n; i++){ 
        // cout << i << ": " << st[i] << " " << en[i] << endl;
        update(1,1,n,st[i], st[i], (1ll << a[i]));
        // cout << get(1,1,n,st[i], st[i]) << endl;
    }

    while(m--){
        int t;
        cin >> t;
        if (t == 2){
            int i;
            cin >> i;
            int mask = get(1,1,n,st[i], en[i]);
            // cout << mask << " ";
            cout << __builtin_popcountll(mask) << endl;
        }
        else{
            int i, v;
            cin >> i >> v;
            // int temp = get(1,1,n,st[i], st[i]);
            update(1,1,n,st[i], en[i], (1ll << v));
        }
    }

    
    // cout << "-----" << endl;
    // update(1,1,n,st[3], en[3], (1ll << 2));
    // update(1,1,n,st[6], en[6], (1ll << 4));
    // cout << "-----" << endl;
    // int mask = get(1,1,n,st[3], en[3]);
    // cout << __builtin_popcount(mask) << endl;



    return 0;
}