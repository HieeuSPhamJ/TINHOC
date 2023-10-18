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


struct node{
    int bandau, loinhuan, ngay;
    node(int _bandau = 0, int _loinhuan = 0, int _ngay = 0){
        bandau = _bandau;
        loinhuan = _loinhuan;
        ngay = _ngay;
    }  
    int get(){
        return bandau + loinhuan * ngay;
    }
};

node merg(node &a, node &b){
    if (a.get() < b.get()){
        return b;
    }
    return a;
}

int n, test;
node seg[maxN * 4];
int lazy[maxN * 4];

void pushLazy(int i){
    int day = lazy[i];
    lazy[i] = 0;
    lazy[2 * i] += day;
    lazy[2 * i + 1] += day;
    seg[2 * i].ngay += day;
    seg[2 * i + 1].ngay += day;
}

void change(int i, int l, int r, int k, int bandau, int loinhuan){
    if (k < l or  r < k){
        return;
    }
    if (l == r){
        seg[i] = node(bandau, loinhuan, 0);
        lazy[i] = 0;
        return;
    }

    pushLazy(i);
    int mid = (l + r) / 2;
    
    change(2 * i, l, mid, k, bandau, loinhuan);
    change(2 * i + 1, mid + 1, r, k, bandau, loinhuan);
    
    seg[i] = merg(seg[2 * i], seg[2 * i + 1]);
}   

void change(int k, int bandau, int loinhuan){
    change(1,1,n,k,bandau,loinhuan);
}

void update(int i, int l, int r, int L, int R, int v){
    if (r < L or R < l){
        return;
    }
    if (L <= l and r <= R){
        seg[i].ngay += v;
        lazy[i] += v;
        return;
    }
    pushLazy(i);

    int mid = (l + r) / 2;

    update(2 * i, l, mid, L, R, v);
    update(2 * i + 1, mid + 1, r, L, R, v);
    
    seg[i] = merg(seg[2 * i], seg[2 * i + 1]);
}

void update(int k){
    update(1,1,n,1,n,k);
}

node get(int i, int l, int r, int L, int R){
    if (r < L or R < l){
        return node(-1e18);
    }
    if (L <= l and r <= R){
        cout << l << " " << r << " " <<seg[i].loinhuan << endl;
        return seg[i];
    }
    pushLazy(i);

    int mid = (l + r) / 2;

    node t1 = get(2 * i,l,mid,L,R);
    node t2 = get(2 * i + 1, mid + 1, r, L, R);

    if (t1.get() > t2.get()){
        cout << l << " " << r << " " <<t1.loinhuan << endl;
        return t1;
    }
    cout << l << " " << r << " " <<t2.loinhuan << endl;
    return t2;
}

node get(int l, int r){
    return get(1,1,n,l,r);
}
signed main(){
    // freopen("rent.INP", "r", stdin);
    // freopen("rent.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> test;
    for (int i = 1; i <= 4 * n; i++){
        seg[i] = node(-1e18,0,0);
    }
    int la = 0;
    // while(test--){
    //     int t;
    //     cin >> t;
    //     int time;
    //     cin >> time;
    //     update(time - la);
    //     la = time;
    //     if (t == 1){
    //         int k, bandau, loinhuan;
    //         cin >> k >> loinhuan >> bandau;
    //         change(k,bandau,loinhuan);
    //     }
    //     else{
    //         int a, b;
    //         cin >> a >> b;
    //         if (a > b){
    //             swap(a,b);
    //         }
    //         node t = get(a,b);
    //         if (t.get() == -1e18){
    //             cout << "no" << endl;
    //         }
    //         else{
    //             cout << t.get() << endl;
    //         }
    //     }
    // }
    // update(1);
    // change(5,-5,4);
    // update(1);
    // cout << get(3,5).get() << endl;
    // update(1);
    // change(4,9,6);
    // update(1);
    // cout << get(1,2).get() << endl;
    // update(2);
    // change(2,3,2);
    // update(2);
    // cout << get(1,2).get() << endl;

    change(2,3,-3);
    change(1,-100,1);
    update(100);
    node t = get(1,2);
    cout << t.bandau << " " << t.loinhuan << " " << t.ngay << endl;
    
    return 0;
}