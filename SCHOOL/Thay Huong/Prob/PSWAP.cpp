#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;
const int inf = 1e18;

int n;
int a[maxN];
int dp[maxN];
vector <int> st[maxN * 4];

void merg(int a, int b, int c){
    for (auto i: st[b]){
        st[a].push_back(i);
    }
    for (auto i: st[c]){
        st[a].push_back(i);
    }
    sort(st[a].begin(), st[a].end());
    // st[a].resize((int)(st[c].size() + st[c].size()));
    // merge(all(st[b]), all(st[c]), st[a].begin());

    // for (auto i: ans){
    //     cout << i << " ";
    // }
}

void build(int id, int l, int r){
    // cout << id << " " << l << " " << r << endl;
    if (l == r) {
        st[id].push_back(a[l]);
        // cout << l << "-" << r << endl;
        // for (auto i: st[id]){
        //     cout << i << " ";
        // }
        // cout << endl;
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    // cout << "Do" << endl;
    merg(id, 2 * id, 2 * id + 1);
    // cout << l << "-" << r << endl;
    // for (auto i: st[id]){
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << "Done!" << endl;
}

int get(int id, int l, int r, int u, int v, int k){
    if (v < l || r < u) {
        return 0;
    }
    if (u <= l && r <= v) {
        return st[id].size() - (upper_bound(st[id].begin(), st[id].end(), k) - st[id].begin());
    }
    int mid = (l + r) / 2;
    return get(id*2, l, mid, u, v, k) + get(id*2+1, mid+1, r, u, v, k);
}

int getLow(int id, int l, int r, int u, int v, int k){
    // cout << l << " " << r << endl;
    if (v < l || r < u) {
        return 0;
    }
    if (u <= l && r <= v) {
        int i = (lower_bound(st[id].begin(), st[id].end(), k) - st[id].begin());
        // cout << l << " " << r << " " << i << endl;
        return i;
    }
    int mid = (l + r) / 2;
    return getLow(id*2, l, mid, u, v, k) + getLow(id*2+1, mid+1, r, u, v, k);
}

signed main(){
    freopen("PSWAP.INP", "r", stdin);
    freopen("PSWAP.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1,1,n);
    int ans = 0;

    for (int i = 1; i <= n; i++){
        dp[i] = get(1,1,n,1,i,a[i]);
        ans += dp[i];
    }

    int oans = ans;

    for (int i = 1; i <= n; i++){
        int left = 1;
        int right = i - 1;
        // cout << "Index: " << i << endl;
        for (int mid = 1; mid < i; mid++){
            // int mid = (left + right) / 2;
            if (a[mid] < a[i]){
                continue;
            }
            int dpi = get(1,1,n, 1, i - 1, a[mid]);
            int dpj = get(1,1,n, 1, mid - 1, a[i]);
            int lmao = getLow(1,1,n, mid + 1, i - 1, a[mid]);
            int notLmao = getLow(1,1,n, mid + 1, i - 1, a[i]);
            int newAns = oans - dp[i] - dp[mid] + dpi + dpj - lmao + notLmao;

            // cout << mid << ": " << newAns << endl; 
            // // cout << mid + 1 << " " << i - 1 << endl;
            // cout << dpi << " " << dpj << " " << lmao << endl;

            ans = min(ans, newAns + 1);

        }
    }
    // cout << "ENDL" << endl;
    // cout << getLow(1,1,n, 4, 5, 3) << endl;
    cout << ans << endl;


    return 0;
}

/*
1 4 6 2 5 3
0 0 0 2 1 3
6
1 4 3 2 5 6
0 0 1 2 0 0

*/