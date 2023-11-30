#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

namespace sub1{
    int n, k;

    int a[maxN];
    int dp[maxN];
    int seg[maxN * 4];
    int pre[maxN];
    
    void update(int i, int left, int right, int index, int val){
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

    void update(int i, int v){
        // cout << i << ": " << v << endl;
        update(1,1,n,i,v);
    }

    int get(int l, int r){
        if (r < l){
            return 0;
        }
        return get(1,1,n,l,r);
    }

    void solve(){
        cin >> n >> k;
        int sum = 0;
        int res = 0;
        for (int i = 1, la = 1; i <= n; i++){
            int c;
            cin >> a[i] >> c;
            sum += c;
            while(a[i] - a[la] > k){
                la++;
            }
            // cout << "With: " << i << " " << la << endl;
            dp[i] = get(la,i - 1);
            if (dp[i] != 0){
                dp[i] += c;
                res = max(res, dp[i]);
                // cout << dp[i] << endl;
            }
            if (i >= 2){
                pre[i - 1] = max(pre[i - 2], dp[i - 1]);
            }
            update(i,pre[i - 1] + c);
        }

        cout << sum - res << endl;
    }
}

namespace sub2{
    
    int k;
    int dp[maxN][2];
    int cal(vector <int> &ls){
    
    }

    void solve(){
        int n;
        cin >> n >> k;
        vector <int> ls;
        int res = 0;
        for (int i = 1; i <= n; i++){
            int x, c;
            cin >> x >> c;
            if (ls.size() and x - ls.back().fi > k){
                res += cal(ls);
                ls.clear();
            }
            ls.push_back({x,c});
        }
        res += cal(ls);

        cout << res << endl;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("paired.inp", "r")) {
        freopen("paired.inp", "r", stdin);
        freopen("paired.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    if (test == 1){
        sub1::solve();
    }
    else{
        sub2::solve();
    }
    return 0;
}

/*
1 2 3 4 5
2 1 4 6 

dp[i][j] 
*/