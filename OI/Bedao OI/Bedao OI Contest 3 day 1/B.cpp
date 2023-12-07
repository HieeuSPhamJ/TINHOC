#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 3e5 + 10;

int n;
int a[maxN];

struct segmenttree{
    int seg[maxN * 4];
    int lazy[maxN * 4];
    segmenttree(){
        memset(lazy, -1, sizeof(lazy));
        memset(seg, 0, sizeof(seg));
        
    }
    void setLazy(int i, int l, int r){
        int val = lazy[i];
        lazy[i] = -1;
        if (val == -1){
            return;
        }
        int mid = (l + r) / 2;
        seg[2 * i] = val * (mid - l + 1);
        seg[2 * i + 1] = val * (r - mid);
        lazy[2 * i] = val;
        lazy[2 * i + 1] = val;
    }

    void update(int i, int left, int right, int _left, int _right, int val){
        if (right < _left or _right < left){
            return;
        }
        if (_left <= left and right <= _right){
            seg[i] = (right - left + 1) * val;
            lazy[i] = val;
            return;
        }

        setLazy(i, left, right);

        int mid = (left + right) / 2;

        update(2 * i, left, mid, _left, _right, val);
        update(2 * i + 1, mid + 1, right, _left, _right, val);
        seg[i] = (seg[2 * i] + seg[2 * i + 1]);
    }

    int get(int i, int left, int right, int _left, int _right){
        if (right < _left or _right < left){
            return 0;
        }
        if (_left <= left and right <= _right){
            return seg[i];
        }

        setLazy(i, left, right);

        int mid = (left + right) / 2;

        int t1 = get(2 * i, left, mid, _left, _right);
        int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
        return t1 + t2;
    }

    void update(int l, int r, int v){
        update(1,1,n,l,r,v);
    }

    int get(int l, int r){
        return get(1,1,n,l,r);
    }

} Tree[31];


void print(){
    cout << "===!===" << endl;
    for (int t = 0; t <= 4; t++){
        cout << t << ":";
        for (int i = 1; i <= n; i++){
            cout << Tree[t].get(i,i);
        }
        cout << endl;
    }
}

int tmp[32];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("mexquery.inp", "r")) {
        freopen("mexquery.inp", "r", stdin);
        freopen("mexquery.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        Tree[a[i]].update(i,i,1);
    }

    int test;
    cin >> test;
    while(test--){
        int te;
        cin >> te;
        int l, r;
        cin >> l >> r;
        for (int i = 0; i <= 30; i++){
            tmp[i] = Tree[i].get(l,r);
        }
        if (te == 2){
            for (int i = 0; i <= 31; i++){
                // cout << i << " " << tmp[i] << endl;
                if (tmp[i] == 0){
                    cout << i << endl;
                    goto bru;
                }
            }
        }
        else{
            int t;
            cin >> t;
            // cout << l << ' ' << r << " " << t << endl;
            // print();
            if (t == 1){
                for (int i = 0, la = l; i <= 30; i++){
                    Tree[i].update(l,r,0);
                    if (tmp[i]){
                        // cout << " add "<< i << " " << la << " " << la + tmp[i] - 1 << endl;
                        Tree[i].update(la, la + tmp[i] - 1, 1);
                    }
                    la += tmp[i];
                }
            }
            else{
                for (int i = 30, la = l; i >= 0; i--){
                    Tree[i].update(l,r,0);
                    if (tmp[i]){
                        // cout << " add "<< i << " " << la << " " << la + tmp[i] - 1 << endl;
                        Tree[i].update(la, la + tmp[i] - 1, 1);
                    }
                    la += tmp[i];
                }
            }
            // print();
        }
        bru:;
    }
    return 0;
}

/*
1 3 2 0 4
0 1 2 3 4
*/