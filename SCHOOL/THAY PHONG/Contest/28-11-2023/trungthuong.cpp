#include"bits/stdc++.h"
// #define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 2e5 + 10;

int n;

namespace sub12{
    int a[maxN];

    void solve(){
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int res = 0;
        for (int i = 1; i <= n; i++){
            for (int j = i + 1, mi = a[i], ma = a[i]; j <= n; j++){
                mi = min(mi, a[j]);
                ma = max(ma, a[j]);
                res += (max(a[i], a[j]) == ma and min(a[i], a[j]) == mi);
            }
        }
        cout << res << endl;
    }
}

namespace sub3{
    int a[maxN];
    int fl[maxN];
    int fr[maxN];
    int bit[maxN];

    struct segmenttree{
        vector <int> seg[maxN * 4];

        void build(int id, int l, int r){
            seg[id].clear();
            if (r < l){
                return;
            }
            if (l == r){
                seg[id].push_back(fl[l]);
                return;
            }
            int mid = (l + r) / 2;
            build(id * 2, l, mid);
            build(id * 2 + 1, mid + 1, r);
            int t1 = 0;
            int t2 = 0;
            vector <int> &s1 = seg[2 * id];
            vector <int> &s2 = seg[2 * id + 1];
            int l1 = s1.size();
            int l2 = s2.size();
            while(t1 < l1 or t2 < l2){
                if (t1 < l1 and t2 < l2){
                    if (s1[t1] < s2[t2]){
                        seg[id].push_back(s1[t1]);
                        t1++;
                    }
                    else{
                        seg[id].push_back(s2[t2]);
                        t2++;
                    }
                }
                else{   
                    if (t1 < l1){
                        seg[id].push_back(s1[t1]);
                        t1++;
                    }
                    else{
                        seg[id].push_back(s2[t2]);
                        t2++;
                    }
                }
            }
        }

        int get(int id, int l, int r, int u, int v, int k){
            if (u > v){
                return 0;
            }
            if (v < l or r < u){
                return 0;
            }
            if (seg[id].empty()){
                return 0;
            }
            if (seg[id].front() > k){
                return 0;
            }
            if (u <= l and r <= v){
                if (seg[id].back() <= k){
                    // cout << l << " " << r << " " << seg[id].size() << endl;
                    return seg[id].size();
                }
                int t = upper_bound(all(seg[id]), k) - seg[id].begin();
                return t;
            }
            int mid = (l + r) / 2;
            return get(id * 2, l, mid, u, v, k) + get(id * 2 + 1, mid + 1, r, u, v, k);
        }
    } Tree;

    long long cal(){

        a[n + 1] = -1e9;
        fr[n + 1] = n + 1;
        for (int i = n; i >= 1; i--){
            int t = i;
            while(a[t + 1] >= a[i]){
                t = fr[t + 1];
            }
            fr[i] = t;
        }
        a[0] = 1e9;
        for (int i = 1; i <= n; i++){
            int t = i;
            while(a[t - 1] <= a[i]){
                t = fl[t - 1];
            }
            fl[i] = t;
        }

        Tree.build(1,1,n);

        long long res = 0;

        // for (int i = 1; i <= n; i++){
        //     cout << fl[i] << " ";
        // }
        // cout << endl;

        // cout << Tree.get(1,1,n,2,2,1) << endl;

        for (int i = 1; i <= n; i++){
            int t = Tree.get(1,1,n,i + 1, fr[i], i);
            res += t;
            // cout << i + 1 << " " << fr[i] << " " << i << " " << t << endl;
        }

        return res;
    }

    void solve(){
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        long long res = 0;
        res += cal();
        reverse(a + 1, a + 1 + n);
        res += cal();

        for (int i = 1, la = 1; i <= n; i++){
            if (a[la] != a[i + 1]){
                long long l = i - la + 1;
                res -= l * (l - 1) / 2;
                la = i + 1;
            }
        }
        cout << res << endl;
    }
}

/*
123
23
12
13

*/

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
    cin >> n;
    if (n <= 1000){
        sub3::solve();
    }
    else{
        sub3::solve();
    }
    return 0;
}