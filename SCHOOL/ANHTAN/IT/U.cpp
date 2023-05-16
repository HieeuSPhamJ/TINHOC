#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;
const int inf = 1e18;
const int SUS = 1e9;

int n, test;
int seg[maxN * 4];
int lazy[maxN * 4];

void setLazy(int i){
    int val = lazy[i];
    lazy[i] = 0;
    if (val){
        lazy[2 * i] = val;
        lazy[2 * i + 1] = val;
        seg[2 * i] = val;
        seg[2 * i + 1] = val;
    }
}


void update(int i, int left, int right, int _left, int _right, int val){
    if (right < _left or _right < left){
        return;
    }
    if (_left <= left and right <= _right){
        seg[i] = val;
        lazy[i] = val;
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

int a[maxN];
int b[maxN];

void print(){
    cout << "===X===" << endl;
    for (int i = 1; i <= n; i++){
        int t = get(1,1,n,i,i);
        if (t > SUS){
            cout << "|" << t - SUS << "|" << ' ';
        }
        else if (t == -inf){
            cout << "x" << " ";
        }
        else{
            cout << t << ' ';
        }
    }
    cout << endl;
}

ii query[maxN];

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
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }

    for (int T = 0; test; test--){
        int t;
        cin >> t;
        if (t == 1){
            int k;
            T++;
            cin >> query[T].fi >> query[T].se >> k;         
            update(1, 1, n, query[T].se, query[T].se + k - 1, T);
            // print();
        }
        else{
            int x;
            cin >> x;
            int i = get(1, 1, n, x, x);
            // int i = 1;
            // cout << "Get: " << i << endl;
            if (i){
                cout << a[query[i].fi - query[i].se + x] << endl;
            }
            else{
                cout << b[x] << endl;
            }
        }
    }

    return 0;
}