#include<bits/stdc++.h>

#define int long long
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'

using namespace std;

const int maxN = 5 * 1e5 + 10;
const int inf = 1e18;

ii seg[maxN * 4];

ii min(ii x, ii y){
    return {min(x.fi,y.fi), min(x.se, y.se)};
}

void update(int i, int left, int right, int index, ii val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i] = val;
        return;
    }
    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);
    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}

ii get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return {1e18,1e18};
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    ii t1 = get(2 * i, left, mid, _left, _right);
    ii t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return min(t1, t2);
}

unordered_map <int,int> lmao;
int a[(int)1e6];
ii adu[(int)1e6];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, test;
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++){
        if (lmao[a[i]] == 0){
            adu[i].fi = 1e18;
        }
        else{
            adu[i].fi = i - lmao[a[i]];
        }
        lmao[a[i]] = i;
    }
    lmao.clear();
    for (int i = n; i >= 1; i--){
        if (lmao[a[i]] == 0){
            adu[i].se = 1e18;
        }
        else{
            adu[i].se = lmao[a[i]] - i;
        }
        lmao[a[i]] = i;
    }
    for (int i = 1; i <= n; i++){
        // cout << adu[i].fi << " " << adu[i].se << endl;
        update(1,1,n,i,adu[i]);
    }
    while(test--){
        int l, r;
        cin >> l >> r;
        int res = 1e18;
        for (int i = l; i <= r; i++){
            if (i - adu[i].fi >= l){
                res = min(res,adu[i].fi);
            }
            if (i + adu[i].se <= r){
                res = min(res,adu[i].se);
            }
        }
        if (res == 1e18){
            cout << -1 << endl;
        }
        else{
            cout << res << endl;
        }
    }

    return 0;
}
