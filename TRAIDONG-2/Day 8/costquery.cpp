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

const int maxN = 1e5 + 10;

int rt[maxN];
int va[maxN];
int pre[maxN];
vector <ii> lists;

int find(int nu){
    if (nu == rt[nu]){
        return nu;
    }
    return rt[nu] = find(rt[nu]);
}

int cal(int k){
    int l = 0;
    int r = (int)lists.size() - 1;
    int res = -1;
    while(l <= r){
        int mid = (l + r) / 2;
        if (lists[mid].fi > k){
            r = mid - 1;
        }
        else{
            l = mid + 1;
            res = mid;
        }
    }
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("costquery.inp", "r")) {
        freopen("costquery.inp", "r", stdin);
        freopen("costquery.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, test;
    cin >> n >> test;
    vector <pair<int,ii>> ls;
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        ls.push_back({w,{a,b}});
    }
    sort(rall(ls));

    for (int i = 1; i <= n; i++){
        rt[i] = i;
        va[i] = 1;
    }
    while(ls.size()){
        int u = find(ls.back().se.fi);
        int v = find(ls.back().se.se);
        if (u == v){
            continue;
        }
        lists.push_back({ls.back().fi, va[u] * va[v]});
        va[u] += va[v];
        rt[v] = u;
        ls.pop_back();
    }
    sort(all(lists));
    for (int i = 1; i <= (int)lists.size(); i++){
        pre[i] = pre[i - 1] + lists[i - 1].se;
    }
    while(test--){
        int x, y;
        cin >> x >> y;
        x = cal(x - 1) + 1;
        y = cal(y) + 1;
        // cout << x << " " << y << endl;
        cout << pre[y] - pre[x] << " ";
    }


    return 0;
}