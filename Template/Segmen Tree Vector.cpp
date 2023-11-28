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
        if (u <= l and r <= v){
            int t = upper_bound(all(seg[id]), k) - seg[id].begin();
            return t;
        }
        int mid = (l + r) / 2;
        return get(id * 2, l, mid, u, v, k) + get(id * 2 + 1, mid + 1, r, u, v, k);
    }
} Tree;

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

    return 0;
}