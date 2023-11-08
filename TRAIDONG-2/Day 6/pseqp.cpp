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

const int maxN = 3 * 1e5 + 10;
const int inf = 1e18;

int seg[maxN * 4];


void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i] += val;
        return;
    }
    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);
    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
}

int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return 0;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return max(t1, t2);
}

int a[maxN];
int n, test;

void update(int i, int v){
    i++;
    update(1,1,n,i,v);
}

int get (){
    return get(1,1,n,1,n);
}

int b[maxN];


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a[x] = i;
    }

    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        update((i - a[x] + n) % n, 1);
        b[i] = x;
    }

    while(test--){
        int i, j;
        cin >> i >> j;
        update((i - a[b[i]] + n) % n, -1);
        update((j - a[b[j]] + n) % n, -1);
        swap(b[i], b[j]);
        update((i - a[b[i]] + n) % n, 1);
        update((j - a[b[j]] + n) % n, 1);
        cout << get() << endl;
    }


    return 0;
}