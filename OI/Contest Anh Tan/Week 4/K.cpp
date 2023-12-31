#include"bits/stdc++.h"
#define int long long
// #define double long double
#define ii pair <int,int>
#define fi first
#define se second
// #define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 3e5 + 10;
int n;
int a[maxN];

struct seg1{
    vector <int> seg[4 * maxN];

    void merge(vector <int> &res, vector <int> &a, vector <int> &b, int k = 30){
        res.clear();
        int ta = 0;
        int tb = 0;
        int la = (int)a.size() - 1;
        int lb = (int)b.size() - 1;    
        while ((ta <= la or tb <= lb) and (int)res.size() < k){
            if (ta <= la and tb <= lb){
                if (a[ta] > b[tb]){
                    res.push_back(a[ta]);
                    ta++;
                }
                else{
                    res.push_back(b[tb]);
                    tb++;
                }
            }
            else{
                if (ta <= la){
                    res.push_back(a[ta]);
                    ta++;
                }
                else{
                    res.push_back(b[tb]);
                    tb++;
                }
            }
        }
    }

    void mini(vector <int> &a, int k){
        while((int)a.size() > k){
            a.pop_back();
        }
    }

    void update(int id, int l, int r, int index, int v){
        if (index < l or r < index){
            return;
        }

        if (l == r){
            seg[id].clear();
            seg[id].push_back(v);
            return;
        }

        int mid = (l + r) / 2;

        update(2 * id, l, mid, index, v);
        update(2 * id + 1, mid + 1, r, index, v);

        merge(seg[id], seg[2 * id], seg[2 * id + 1]);
    }

    int countlow(vector <int> &ls, int k){
        int l = 0;
        int r = (int)ls.size() - 1;
        int res = -1;
        // for (auto i: ls){
        //     cout << i << " "; 
        // }
        // cout << endl;
        while(l <= r){
            int mid = (l + r) / 2;
            // cout << mid << endl;
            if (ls[mid] >= k){
                l = mid + 1;
                res = mid;
            }
            else{
                r = mid - 1;
            }
        }
        return res + 1;
    }

    int get(int id, int l, int r, int L, int R, int k){
        if (R < l or r < L){
            return 0;
        }
        vector <int> t;
        if (L <= l and r <= R){
            int t = countlow(seg[id], k);
            // cout << l << " " << r << " " << k << ": " << t << endl; 
            return t;
        }

        int mid = (l + r) / 2;
        
        int t1 = get(2 * id, l, mid, L, R, k);
        int t2 = get(2 * id + 1, mid + 1, r, L, R, k);
        return t1 + t2;
    }

    void update(int i, int v){
        update(1,1,n,i,v);
    }

    int get(int l, int r, int k){
        int lo = 0;
        int hi = 2e9;
        int res = -1;
        // return get(1,1,n,l,r,1408118305);
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            int t = get(1,1,n,l,r,mid);
            // cout << mid << ": " << t << endl;
            if (t >= k){
                lo = mid + 1;
                res = mid;
            }
            else{
                hi = mid - 1;
            }
        }
        return res;
    }

} kthmax;

/*
0 1 2 3 4 5 6 7 8 9 10

9 7 1
*/

struct seg2{
    int seg[4 * maxN];
    
    void update(int id, int l, int r, int index, int v){
        if (index < l or r < index){
            return;
        }

        if (l == r){
            seg[id] = v;
            return;
        }

        int mid = (l + r) / 2;

        update(2 * id, l, mid, index, v);
        update(2 * id + 1, mid + 1, r, index, v);

        seg[id] = max(seg[2 * id], seg[2 * id + 1]);
    }

    int get(int id, int l, int r, int L, int v){
        if (l > r){
            return -1;
        }
        if (r < L){
            return -1;
        }
        // cout << l << " " << r << " " << seg[id] << endl;
        if (l == r){
            if (seg[id] >= v){
                return l;
            }
            return -1;
        }
        int mid = (l + r) / 2;

        if (L <= l){
            if (seg[2 * id] >= v){
                return get(2 * id, l, mid, L, v);
            }
            return get(2 * id + 1, mid + 1, r, L, v);
        }

        int t1 = get(2 * id, l, mid, L, v);
        if (t1 != -1){
            return t1;
        }
        return get(2 * id + 1, mid + 1, r, L, v);   
    }
    
    void update(int i, int v){
        update(1,1,n,i,v);
    }

    int get(int l, int r, int v, int k){
        int res = -1;
        // return get(1,1,n,l,v);
        while(k--){
            int t = get(1,1,n,l,v);
            // cerr << k + 1 << ": " << l << " " << t << endl;
            if (t == -1 or r < t){
                return -1;
            }
            res = t;
            l = t + 1;
        }
        return res;
    }

} kthpos;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("input.inp", "r")) {
        freopen("input.inp", "r", stdin);
        freopen("A.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        kthmax.update(i, a[i]);
        kthpos.update(i, a[i]);
    }
    while(test--){
        string s;
        cin >> s;
        if (s == "SET"){
            int i, v;
            cin >> i >> v;
            kthmax.update(i,v);
            kthpos.update(i,v);
            continue;
        }
        if (s == "MAX"){
            int l, r, k;
            cin >> l >> r >> k;
            cout << kthmax.get(l,r,k) << " ";
            continue;
        }
        if (s == "POS"){
            int l, r, v, k;
            cin >> l >> r >> v >> k;
            cout << kthpos.get(l,r,v,k) << " ";
        }

    }
    return 0;
}