#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

struct segment{
    int l,a,b,r;
    // void print(char en = endl){
    //     cout << l << "," << a << "," << b << "," << r << en;  
    // }
};

const int maxN = 5 * 2e5 + 10;
const int inf = 1e18;

int n;
int goc[maxN];
unordered_map <int,int> cnv;
int lazy[4 * maxN];
int seg[4 * maxN];
int id[maxN];

void setLazy(int id){
    for (int i = id * 2; i <= id * 2 + 1; i++){
        seg[i] = max(seg[i], lazy[id]);
        lazy[i] = max(lazy[i], lazy[id]);
    }
    lazy[id] = -inf;
}

void build(int i, int left, int right){
    if (left > right){
        return;
    }
    if (left == right){
        id[left] = i;
        seg[i] = left;
        return;
    }
    int mid = (left + right) / 2;
    build(2 * i, left, mid);
    build(2 * i + 1, mid + 1, right);
}

void final(int i, int left, int right){
    if (left > right){
        return;
    }
    if (left == right){
        return;
    }
    setLazy(i);
    int mid = (left + right) / 2;
    final(2 * i, left, mid);
    final(2 * i + 1, mid + 1, right);
    
}

void update(int i, int left, int right, int _left, int _right, int val){
    if (right < _left or _right < left){
        return;
    }
    if (_left <= left and right <= _right){
        seg[i] = max(seg[i], val);
        lazy[i] = max(lazy[i], val);
        return;
    }
    setLazy(i);
    int mid = (left + right) / 2;

    update(2 * i, left, mid, _left, _right, val);
    update(2 * i + 1, mid + 1, right, _left, _right, val);
    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
}

int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return -inf;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }
    setLazy(i);
    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return max(t1,t2);
}

void update(int l, int r, int v){
    update(1,1,n,l,r,v);
}

int get(int l, int r){
    return get(1,1,n,l,r);
}

void nenso(vector <segment> &ls, vector <int> &query){
    set <int> s;
    cnv.clear();
    for (segment i: ls){
        s.insert(i.l);
        s.insert(i.r);
        s.insert(i.a);
        s.insert(i.b);
    }
    for (auto i: query){
        s.insert(i);
    }
    int cnt = 0;
    for (auto i: s){
        cnt++;
        cnv[i] = cnt;
        goc[cnt] = i;
        n = cnt;
    }
    for (segment &i: ls){
        i.l = cnv[i.l];
        i.r = cnv[i.r];
        i.a = cnv[i.a];
        i.b = cnv[i.b];   
    }
    for (auto &i: query){
        i = cnv[i];
    }
}

bool cmp(segment a, segment b){
    return a.b > b.b;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        cin >> n;
        vector <segment> ls;
        for (int i = 1; i <= n; i++){
            int l, a, b, r;
            cin >> l >> r >> a >> b;
            ls.push_back({l,a,b,r});
        }
        int q;
        cin >> q;
        vector <int> query;
        while(q--){
            int x;
            cin >> x;
            query.push_back(x);
        }
        nenso(ls, query);
        sort(all(ls), cmp);
        // for (segment i: ls){
        //     i.print();
        // }
        for (int i = 1; i <= 4 * n; i++){
            seg[i] = 0;
            lazy[i] = 0;
        }
        for (int i = 1; i <= n; i++){
            update(i,i,i);
        }
        build(1,1,n);
        for (segment line: ls){
            int dick = get(line.a, line.b);
            update(line.l, line.r, dick);
        }
        final(1,1,n);
        for (auto i: query){
            cout << goc[seg[id[i]]] << " ";
        }
        cout << endl;
    }

    return 0;
}