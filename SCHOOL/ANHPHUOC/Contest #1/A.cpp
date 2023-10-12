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

int n, test;
int a[maxN];
int b[maxN];
int seg[maxN * 4];

void build(int i, int l, int r){
    if (l > r){
        return;
    }
    if (l == r){
        seg[i] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}

int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return 1e18;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return min(t1, t2);
}

int get(int l, int r){
    return get(1,1,n,l,r);
}

int getl(int i, int l, int r, int left, int k){
    if (seg[i] > k){
        return -1;
    }
    if (r < left){
        return -1;
    }
    if (l == r){
        return l;
    }
    int mid = (l + r) / 2;
    if (seg[2 * i] <= k){
        int t = getl(2 * i, l, mid, left, k);
        if (t != -1){
            return t;
        }
    }
    return getl(2 * i + 1, mid + 1, r, left, k);
}
 
int getl(int l, int r, int k){
    int t = getl(1,1,n,l, k);
    if (t <= r){
        return t;
    }
    return -1;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> test;
    for (int i = 1; i <= test; i++){
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1,1,n);
    for (int t = 1; t <= test; t++){
        int x = b[t];
        for (int i = 1; i <= n;){
            int l = i;
            int r = n;
            int k = getl(i,n,x);
            if (k == -1){
                break;
            }
            x %= a[k];
            i = k + 1;
        }
        cout << x << " ";
    }


    return 0;
}