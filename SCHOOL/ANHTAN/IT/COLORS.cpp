#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 4 * 1e5 + 10;
const int inf = 1e18;

int n, test;
int seg[maxN * 4];

void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i] = val;
        return;
    }
    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);
    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}

void update(int i, int v){
    update(1,1,n,i,v);
}

int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return 0;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return (t1 + t2);
}

struct query{
    int id,c,d,l,r;
};

bool cmp(query a, query b){
    return a.r > b.r;
}

vector <query> ls;

int a[maxN];
int ans[maxN];

int get(int i, int l, int r, int c, int d, int gap){
    if (r < c or d < l){
        // cout << l << " " << r << " " << inf << endl;
        return inf;
    }
    if (c <= l and r <= d){
        // cout << l << " " << r << " in" << " " << seg[i] << endl;
        if (seg[i] >= gap){
            // cout << l << " " << r << " " << inf << endl;
            return inf;
        }
    }

    if (l == r){
        // cout << l << " " << r << " " << l << endl;
        return l;
    }

    int mid = (l + r) / 2;

    int t = get(2 * i, l, mid, c, d, gap);

    if (t == inf){
        // cout << l << " " << r << " right" << endl;
        return get(2 * i + 1, mid + 1, r, c, d, gap);
    }
    // cout << l << " " << r << " " << t << endl;
    return t;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= test; i++){
        int c,d,l,r;
        cin >> c >> d >> l >> r;
        ls.push_back({i,c,d,l,r});
    }
    sort(all(ls), cmp);

    for (int i = 1; i <= n; i++){
        update(a[i],i);
        while(ls.back().r == i){
            query t = ls.back();
            ls.pop_back();
            // cout << "index: " << t.id << endl;
            // for (int j = 1; j <= n; j++){
            //     cout << get(1,1,n,j,j) << " ";
            // }
            // cout << endl;
            // cout << get(1,1,n,t.c,t.d,t.l) << endl;
            ans[t.id] = get(1,1,n,t.c,t.d,t.l);
        }
    }

    for (int i = 1; i <= test; i++){
        if (ans[i] == inf){
            cout << "OK";
        }
        else{
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}