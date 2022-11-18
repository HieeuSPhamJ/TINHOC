#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int N = (1 << 19) + 1;
const int maxN = N + 10;
const int inf = 1e18;


ii seg[maxN * 4];
int a[maxN];

ii com(ii x, ii y){
    ii z;
    z.fi = x.fi + y.fi;
    z.se = x.se + y.se;
    return z;
}

void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i].se += val;
        seg[i].fi = (seg[i].se > 0);
        return;
    }
    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);
    seg[i] = com(seg[2 * i], seg[2 * i + 1]);
}

ii get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return {0,0};
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    ii t1 = get(2 * i, left, mid, _left, _right);
    ii t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return com(t1, t2);
}

void up(int id, int val){
    update(1,1,N,id + 1,val);
}

int MEX(){
    int left = 1;
    int right = N;
    int ans = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        int leq = get(1,1,N,1,mid).fi;
        if (leq >= mid){
            left = mid + 1;
            ans = mid;
        }
        else{
            right = mid - 1;
        }
    }
    return ans;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        up(a[i],1);
    }

    while(test--){
        int k;
        cin >> k;
        for (int i = 1; i <= n; i++){
            up(a[i], -1);
            a[i] = (a[i] xor k);
            up(a[i], 1);
        }
        cout << MEX() << endl;
    }


    return 0;
}