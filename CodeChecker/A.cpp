#include <bits/stdc++.h>

#define int long long
#define ii pair <int, int>
#define iii pair<ii, int>
#define vii vector<ii>
#define fi first
#define se second
using namespace std;

const int inf = 1e18;
const double eps = 0.00001;
const int mod = 1e9 + 7;

const int maxN = 1e6 + 10;

int bit[maxN];

int tr[maxN];

void update (int id, int l, int r, int u, int val) {
    //cout << id << " " << l << " " << r << " " << pos << " " << val << "\n";
    if (l > u or r < u) return;
    else if (l == r) {
        tr[id] = val;
        return;
    }
    int mid = (l+r)/2;
    update(id*2, l, mid, u, val);
    update(id*2+1, mid+1, r, u, val);
    tr[id] = min(tr[id*2], tr[id*2+1]);
}

int get (int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 1e18;
    else if (l >= u && r <= v) return tr[id];
    int mid = (l+r)/2;
    return min(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    for (int i = 1; i < maxN; i++){
        tr[i] = 1e18;
    }
    int n;
    cin >> n;
    vector <int> lists;
    set <int> Set;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        lists.push_back(x);
        Set.insert(x);
    }

    map <int,int> conv;
    
    int cnt = 1;

    for (auto i: Set){
        conv[i] = cnt;
        cnt++;
    }

    for (auto &i: lists){
        i = conv[i];
        // cout << i << " ";
    }

    int res = -1;
    update(1,1,n,lists[0],0);
    for (int i = 1; i < lists.size(); i++){
        int x = lists[i];
        if (x == 1){
            update(1,1,n,x,i);
            continue;
        }
        int last = get(1,1,n,1,x - 1);
        // cout << i << " " << last << " " << x << endl;
        if (last != 1e18){
            // cout << i << " " << last << endl;
            res = max(res,i - last);
        }
        update(1,1,n,x,i);
    }

    if (res == -1){
        cout << -1;
    }
    else{
        cout << res;
    }
    return 0;
}