#pragma GCC optimize("O1")
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1010;
const int inf = 1e18;

struct query{
    int id, l, r, k;
};

bool cmp(query a, query b){
    return a.r > b.r;
}

set <int> seg[maxN * 4];
int add[maxN * 4];

void update(int i, int l, int r, int index, int val){
    if (index < l or r < index){
        return;
    }
    if (l == r){
        seg[i].insert(val);
        add[i] = val;
        return;
    }
    int mid = (l + r) / 2;

    update(2 * i, l, mid, index, val);
    update(2 * i + 1, mid + 1, r, index, val);

    if (add[2 * i] != inf){
        seg[i].insert(add[2 * i]);
        add[i] = add[2 * i];
    }
    add[2 * i] = inf;

    if (add[2 * i + 1] != inf){
        seg[i].insert(add[2 * i + 1]);
        add[i] = add[2 * i + 1];
    }
    add[2 * i + 1] = inf;
}

int n, test;
int a[maxN];
vector <query> ls;
int ans[maxN * maxN];

int get(int i, int l, int r, int L, int R, int k){
    if (r < L or R < l){
        // cout << l << " " << r << " " << -inf << endl;
        return -inf;
    }
    if (seg[i].empty()){
        return -inf;
    }
    if (L <= l and r <= R){
        if (*seg[i].begin() > k){
            // cout << l << " " << r << " " << -inf << endl;
            return -inf;
        }
        auto it = seg[i].upper_bound(k);
        it--;
        // cout << l << " " << r << " " << *it << endl;
        return *it; 
    }

    int mid = (l + r) / 2;

    int t1 = get(2 * i, l, mid, L, R, k);
    int t2 = get(2 * i + 1, mid + 1, r, L, R, k);
    // cout << l << " " << r << " " << max(t1,t2) << endl;
    return max(t1,t2);
}

int get(int i, int l, int r, int id){
    if (id < l or r < id){
        return -1;
    }
    if (l == r){
        return i;
    }
    int mid = (l + r) / 2;
    return max(get(2 * i, l, mid, id), get(2 * i + 1, mid + 1, r, id));
}

void print(){
    for (int i = 1; i <= n; i++){
        cout << i << ": ";
        int t = get(1,1,n,i);
        for (auto x: seg[t]){
            cout << x << ", ";
        }
        cout << endl;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> test;
    for (int i = 1; i < 4 * maxN; i++){
        add[i] = inf;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= test; i++){
        int l, r, k;
        cin >> l >> r >> k;
        ls.push_back({i,l,r,k});
    }
    sort(all(ls), cmp);

    for (int i = 1; i <= n; i++){
        if (ls.empty()){
            break;
        }
        for (int j = i, sum = 0; j >= 1; j--){
            sum += a[j];
            update(1,1,n,j,sum);
        }
        while(ls.back().r == i){
            query t = ls.back();
            ls.pop_back();
            // print();
            ans[t.id] = get(1, 1, n, t.l, i, t.k);
        }
    }

    for (int i = 1; i <= test; i++){
        if (ans[i] == -inf){
            cout << "NONE" << endl;
        }
        else{
            cout << ans[i] << endl;
        }
    }

    return 0;
}