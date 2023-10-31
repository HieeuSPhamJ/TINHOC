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

const int maxN = 100010;

int a[maxN];
int lazy[4 * maxN];
int seg[4 * maxN];

void setLazy(int id){
    for (int i = id * 2; i <= id * 2 + 1; i++){
        seg[i] = max(seg[i], lazy[id]);
        lazy[i] = max(lazy[i], lazy[id]);
    }
    lazy[id] = 0;
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
        return 0;
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
 
int n, k;

void update(int l, int r, int v){
    update(1,1,n,l,r,v);
}
 
int get(int l, int r){
    return get(1,1,n,l,r);
}

int L[maxN];
int R[maxN];
vector <int> sto[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("VERIFY.inp", "r")) {
        freopen("VERIFY.inp", "r", stdin);
        freopen("VERIFY.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 0; i <= n; i++){
        L[i] = 1;
        R[i] = n;
    }
    for (int i = 1; i <= k; i++){
        int l, r, x;
        cin >> l >> r >> x;
        l++;
        r++;
        update(l,r,x);
        L[x] = max(L[x], l);
        R[x] = min(R[x], r);
    }

    vector <pair<ii,int>> ls;

    for (int i = 0; i < n; i++){
        // cout <<  L[i] << " " << R[i] << endl;
        ls.push_back({{L[i],R[i]},i});
    }

    sort(rall(ls));

    int ok = 1;
    set <int> s;
    for (int i = 1; i <= n; i++){
        while(ls.size() and ls.back().fi.fi == i){
            ii t = {ls.back().se, ls.back().fi.se};
            ls.pop_back();
            s.insert(t.fi);
            sto[t.se].push_back(t.fi);
        }
        int up = get(i,i);
        auto it = s.lower_bound(up);
        if (s.empty() or it == s.end()){
            ok = 0;
            break;
        }
        a[i] = *it;
        s.erase(it);
        for (auto i: sto[i]){
            it = s.find(i);
            if (it != s.end()){
                s.erase(it);
            }
        }
        sto[i].clear();
    }


    if (!ok){
        for (int i = 1; i <= n; i++){
            cout << -1 << " ";
        }
        cout << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}