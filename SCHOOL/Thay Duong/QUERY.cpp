#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

struct node{
    int ma,sum,chan;
};

const node inf = {0,0,0};

int n, test;
node seg[4 * maxN];

node merg(node a, node b){
    a.ma = max(a.ma, b.ma);
    a.chan = (a.chan + b.chan);
    a.sum = (a.sum + b.sum);
    return a;
}

void updateMa(int i, int left, int right, int id, int val){
    if (id < left or right < id){
        return;
    }
    if (left == right){
        seg[i].ma = val;
        return;
    }
    int mid = (left + right) / 2;
    updateMa(2 * i, left, mid, id, val);
    updateMa(2 * i + 1, mid + 1, right, id, val);
    seg[i].ma = max(seg[2 * i].ma, seg[2 + i + 1].ma);
}

void updateSum(int i, int left, int right, int id, int val){
    if (id < left or right < id){
        return;
    }
    if (left == right){
        seg[i].sum = val;
        return;
    }
    int mid = (left + right) / 2;
    updateSum(2 * i, left, mid, id, val);
    updateSum(2 * i + 1, mid + 1, right, id, val);
    seg[i].sum = (seg[2 * i].sum + seg[2 + i + 1].sum);
}

void updateChan(int i, int left, int right, int id, int val){
    if (id < left or right < id){
        return;
    }
    if (left == right){
        seg[i].chan = val;
        return;
    }
    int mid = (left + right) / 2;

    updateChan(2 * i, left, mid, id, val);
    updateChan(2 * i + 1, mid + 1, right, id, val);
    seg[i].chan = (seg[2 * i].chan + seg[2 * i + 1].chan);
}

node get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return inf;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    node t1 = get(2 * i, left, mid, _left, _right);
    node t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return merg(t1, t2);
}

void upMa(int i, int x){
    updateMa(1,1,n,i,x);
}
void upSum(int i, int x){
    updateSum(1,1,n,i,x);
}
void upChan(int i, int x){
    if (i % 2){
        return;
    }
    updateChan(1,1,n,i,x);
}
node getAll(int l, int r){
    return get(1,1,n,l,r);
}
signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> test;
    
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        upMa(i,x);
        upSum(i,x);
        upChan(i,x);
    }

    while(test--){
        int t;
        cin >> t;
        if (t == 1){
            int i, x;
            cin >> i >> x;
            upMa(i,x);
            upSum(i,x);
            upChan(i,x);
        }
        else{
            int l, r;
            cin >> l >> r;
            node now = getAll(l, r);
            int len = (r - l + 1);
            int chan = (len / 2) + (!(l % 2) and len % 2);
            int le = (len - chan);
            // cout << chan << " " << le << endl;
            if (now.ma % 2){
                int same = now.ma * le - (now.sum - now.chan);
                same /= 2;
                int diff = now.ma * chan - now.chan;
                diff /= 2;
                diff += 
            }
            else{
            }
        }
    }

    // cout << getAll(1,2).chan;

    return 0;
}

/*
2 3 4 5 8
*/