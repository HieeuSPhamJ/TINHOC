#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2 * 1e5 + 10;
const int inf = 1e18;

int a[maxN];
int res[maxN];
ii seg[maxN * 4];


void build(int i, int l, int r){
    if (l == r){
        seg[i] = {a[l], l};
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    seg[i] = seg[2 * i];
    if (seg[i].fi >= seg[2 * i + 1].fi){
        seg[i] = seg[2 * i + 1];
    }
}


ii get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return {inf, -1};
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    ii t1 = get(2 * i, left, mid, _left, _right);
    ii t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    if (t1.fi >= t2.fi){
        return t2;
    }
    return t1;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            res[i] = 0;
        }
        int k;
        cin >> k;
        build(1,1,n);
        int st = 1;
        int la = 0;
        int cnt = 0;
        int ma = 1e18;
        while(k and st <= n){
            cnt++;
            ii t = get(1,1,n,st,n);
            st = t.se + 1;
            int pri = t.fi - la;
            int tk = min(k / pri, ma);
            if (tk == 0){
                break;
            }
            // cout << st - 1 << " " << tk << " " << pri << " " << k << endl;
            la = t.fi;
            k -= pri * tk;
            res[st - 1] += tk;
            ma = tk;
        }
        for (int i = n, t = 0; i >= 1; i--){
            res[i] = max(res[i], t);
            t = max(res[i], t);
            
        }
        for (int i = 1; i <= n; i++){
            cout << res[i] << " ";
        }
        cout << endl;

    }
    return 0;
}