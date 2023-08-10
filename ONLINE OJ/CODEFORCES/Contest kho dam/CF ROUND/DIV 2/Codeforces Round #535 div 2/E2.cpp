#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;
const int inf = 1e18;

int seg[maxN * 4];
int lazy[maxN * 4];

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

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        update(1,1,n,i,i,x);
    }
    vector <pair<ii,int>> ls;
    for (int i = 1; i <= m; i++){
        int l, r;
        cin >> l >> r;
        ls.push_back({{l,r},i});
    }
    sort(rall(ls));
    int res = 0;
    multiset <pair<ii,int>> s;
    set <int> lists;
    for (int i = 1; i <= n; i++){
        while(ls.size() and ls.back().fi.fi == i){
            update(1,1,n,ls.back().fi.fi, ls.back().fi.se,-1);
            s.insert({{ls.back().fi.se, ls.back().fi.fi},ls.back().se});
            ls.pop_back();
        }
        while(s.size() and (*s.begin()).fi.fi < i){
            update(1,1,n,(*s.begin()).fi.se,(*s.begin()).fi.fi,1);
            s.erase(s.begin());
        }
        int tres = abs(get(1,1,n,1,n) - get(1,1,n,i,i));
        if (tres > res){
            res = tres;
            lists.clear();
            for (auto i: s){
                lists.insert(i.se);
            }
        }
    }

    cout << res << endl;
    cout << lists.size() << endl;
    for (auto i: lists){
        cout << i << " ";
    }
    return 0;
}