#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5 * 2e5 + 10;
const int inf = 1e18;

int n;
int lazy[4 * maxN];
int seg[4 * maxN];

void setLazy(int id){
    for (int i = id * 2; i <= id * 2 + 1; i++){
        seg[i] = max(seg[i], lazy[id]);
        lazy[i] = max(lazy[i], lazy[id]);
    }
    lazy[id] = -inf;
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


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    n = 10;
    cout << get(1,6) << endl;
    update(4,6,3);
    cout << get(1,6) << endl;
    update(4,8,2);
    cout << get(7,8) << endl;
    return 0;
}