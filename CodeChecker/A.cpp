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
const int mod = 1e9 + 7;
int n;

struct node{
    int lz, va3, va2, va1;
};

int add(int a, int b){
    return (a + b) % mod;
}
int mul(int a, int b){
    return (a * b) % mod;
}


void merge(node &a, node &b){
    a.va1 = add(a.va1, b.va1);
    a.va2 = add(a.va2, b.va2);
    a.va3 = add(a.va3, b.va3);
}


void merge(node &a, node &b, node &c){
    a.va1 = add(b.va1, c.va1);
    a.va2 = add(b.va2, c.va2);
    a.va3 = add(b.va3, c.va3);
}

void nxt(node &a, int x, int l, int r){
    int le = r - l + 1;
    // cout << l << " " << r << " " << x << " " << a.va1 << " " << a.va2 << " " << a.va3 << endl;
    // a.va3 += 3*a.va2*x + 3*a.va1*x*x + x*x*x*le;
    // a.va2 += 2*a.va1*x + x*x*le;
    a.va3 = add(a.va3, mul(3 * x, a.va2) + mul(3*a.va1, mul(x,x)) + mul(x,mul(x,mul(x,le))));
    a.va2 = add(a.va2, mul(2*a.va1, x) + mul(x,mul(x,le)));
    a.va1 = add(a.va1, x * le);
    // cout << a.va1 << " " << a.va2 << " " << a.va3 << endl;
}

/*
a^3 + 3*a^2x +  3*a*x^2 + x^3


a^3 + 3*a^2x +  3*a*x^2 + x^3
b^3 + 3*b^2x +  3*b*x^2 + x^3

*/

struct segmenttree{
    node seg[maxN * 4];

    void setLazy(int i, int l, int r){
        int lz = seg[i].lz;

        seg[i].lz = 0;
        if (lz == 0){
            return;
        }
        int mid = (l + r) / 2;
        // cout << "lz " << l << " " << r << endl;
        nxt(seg[2 * i], lz, l, mid);
        nxt(seg[2 * i + 1], lz, mid + 1, r);
        // cout << seg[2 * i].va3 << " " << seg[2 * i + 1].va3 << endl;
        seg[2 * i].lz += lz;
        seg[2 * i + 1].lz += lz;
    }

    void update(int id, int left, int right, int _left, int _right){
        if (right < _left or _right < left){
            return;
        }
        if (_left <= left and right <= _right){
            // cout << "!" << left << " " << right << endl;
            nxt(seg[id], 1, left, right);
            seg[id].lz++;
            return;
        }

        setLazy(id, left, right);

        int mid = (left + right) / 2;

        update(2 * id, left, mid, _left, _right);
        update(2 * id + 1, mid + 1, right, _left, _right);
        merge(seg[id], seg[2 * id], seg[2 * id + 1]);
    }

    int get(int i, int left, int right, int _left, int _right){
        if (right < _left or _right < left){
            return 0;
        }
        if (_left <= left and right <= _right){
            return seg[i].va3;
        }

        setLazy(i, left, right);

        int mid = (left + right) / 2;

        int t1 = get(2 * i, left, mid, _left, _right);
        int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
        return add(t1, t2);
    }

    void update(int l, int r){
        // cout << l << " " << r << endl;
        update(1,1,n,l,r);
    }

    int get(int l, int r){
        return get(1,1,n,l,r);
    }

    void print(char en = endl){
        for (int i = 1; i <= n; i++){
            cout << get(i,i) << " ";
        }
        cout << en;
    }

} Tree;


/*
x^2
(x + 1)^2
x^2 + 2*x + 1
*/

int la[maxN];

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> n >> test;
    while(test--){
        int t;
        cin >> t;
        int l, r;
        cin >> l >> r;
        if (t == 0){
            Tree.update(l,r);
        }
        else{
            cout << Tree.get(l,r) << endl;
        }
    }
    return 0;
}

/*
0 0 1 
1 1 1
2 2 1
*/