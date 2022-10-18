#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;
const int inf = 1e18;

int a[maxN];
int b[maxN];

ii seg[maxN * 4];

void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i] = {val, index};
        return;
    }
    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);
    seg[i] = seg[2 * i];
    ii t = seg[2 * i + 1];
    if (seg[i].fi < t.fi){
        seg[i] = t;
    }
    else if (seg[i].fi == t.fi and seg[i].se > t.se){
        seg[i] = t;
    }
    // seg[i] = max(seg[2 * i], seg[2 * i + 1]);
}

ii get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return {-inf, -inf};
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    ii t1 = get(2 * i, left, mid, _left, _right);
    ii t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    // return max(t1,t2);
    if (t1.fi < t2.fi){
        t1 = t2;
    }
    else if (t1.fi == t2.fi and t1.se > t2.se){
        t1 = t2;
    }
    return t1;
}


signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
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
            char x;
            cin >> x;
            if (x == '1'){
                b[i] = 1;
            }
            else{
                b[i] = 0;
            }
        }

        for (int i = 1; i <= n; i++){
            // cout << b[i] << " ";
            cin >> a[i];
            update(1,1,n,i,a[i]);
        }

        int ans = 0;
        // ii temp = get(1,1,n,1,n);
        // cout << temp.fi << " " << temp.se;

        for (int i = 1; i <= n; i++){
            if (b[i]){
                ii t = get(1,1,n,1,i);
                ans += t.fi;
                update(1,1,n,t.se,0);
            }
        }

        cout << ans;
        cout << endl;
    }
    return 0;
}