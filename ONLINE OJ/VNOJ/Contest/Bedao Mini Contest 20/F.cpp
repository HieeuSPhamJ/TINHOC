#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5e5 + 10;
const int inf = 1e18;
const int SUS = 1e9;

int n, test;

struct conactaoto{
    int T = 0;
    ii query[maxN];
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

    void update(int l, int r, int v){
        // cout << "up: " << l << " " << r << " " << v << endl;
        update(1,1,n,l,r,v);
    }
    int get(int l, int r){
        return get(1,1,n,l,r);
    }
} cac[3];

int a[maxN];
int b[maxN];
int c[maxN];

void print(int t){
    for (int i = 1; i <= n; i++){
        cout << cac[t].get(i,i) << " ";
    }
    cout << endl;
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
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }

    while(test--){
        int t;
        cin >> t;
        if (t <= 2){
            int x, y, k;
            cac[t].T++;
            cin >> x >> y >> k;
            cac[t].update(y, y + k - 1, cac[t].T);
            cac[t].query[cac[t].T].fi = x;
            cac[t].query[cac[t].T].se = y;
        }
        else {
            int x;
            cin >> x;
            int i = cac[2].get(x,x);
            if (i){
                i = cac[1].get(x,x);
                if (i){
                    cout << a[cac[1].query[i].fi - cac[1].query[i].se + x] << endl;
                }
                else{
                    cout << b[x] << endl;
                }
            }
            else{
                cout << c[x] << endl;
            }
        }
        // cout << "--RES--" << endl;
        // print(1);
        // print(2);
        
    }

    return 0;
}

/*
1 2 3 5 4
4 2 3 1 5
2 4 3 5 1


*/