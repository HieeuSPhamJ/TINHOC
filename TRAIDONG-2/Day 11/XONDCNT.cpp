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

int rmq[maxN][20];
int lg[maxN];
int a[maxN];
int pre[maxN];
map <int,vector <int>> sto;

int get(int l, int r){
    int len = r - l + 1;
    int t1 = rmq[l][lg[len]];
    int t2 = rmq[r - (1 << lg[len]) + 1][lg[len]];
    return (t1 & t2);
}

int find(int l, int r, int x){
    // cout << l << ' ' << r << " " << x << endl;
    int res = 0;
    vector <int> &ls = sto[x];
    l = (lower_bound(all(ls),l) - ls.begin());
    r = (upper_bound(all(ls),r) - ls.begin()) - 1;
    // cout << l << " " << r << endl;
    if (l <= r and r < (int)ls.size()){
        res += r - l + 1;
    }
    return res;
}

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
    int n;
    cin >> n;
    sto[0].push_back(0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        rmq[i][0] = a[i];
        pre[i] = pre[i - 1] xor a[i];
        // cout << pre[i] << " ";
        sto[pre[i]].push_back(i);
        lg[i] = log2(i);
    }
    // cout << endl;
    // for (auto i: sto){
    //     cout << i.fi << ":";
    //     for (auto x: i.se){
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "====" << endl;
    
    for (int j = 1; j < 20; j++){
        for (int i = 1; i <= n; i++){
            if (i + (1 << j) - 1 > n){
                break;
            }
            rmq[i][j] = (rmq[i][j - 1] & rmq[i + (1 << (j - 1))][j - 1]);
        }
    }

    int res = 0;

    for (int i = 1; i <= n; i++){
        int mask = a[i];
        int last = i;
        while(mask){
            int l = 1;
            int r = last;
            int tres = -1;
            // cout << "With: " << i << " " << mask << endl;
            while(l <= r){
                int mid = (l + r) / 2;
                // cout << mid << " " << get(mid, last) << endl;
                if (get(mid, i) == mask){
                    r = mid - 1;
                    tres = mid;
                }
                else{
                    l = mid + 1;
                }
            }
            // cout << tres << " " << i << " " << mask << " " << bitset<5>(mask) << endl;
            // sto.push_back({{tres - 1, i - 1}, mask xor pre[i]});
            res += find(tres - 1, i - 1, mask xor pre[i]);
            last = tres - 1;
            if (last < 1){
                break;
            }
            mask = mask & a[last];
        }
        if (mask == 0 and last >= 1){
            // cout << 1 << ' ' << i << " " << 0 << " " << bitset<5>(mask) << endl;
            // sto.push_back({{0,last - 1}, pre[i]});
            res += find(0, last - 1, pre[i]);
        }
    }
    cout << res << endl;
    return 0;
}

/*
3 1 4 2 3 4
1 1 3: 1
1 2 1: 1
3 3 4: 1
1 3 0: 0
4 4 2: 1
1 4 0: 0
5 5 3: 1
4 5 2: 1
1 5 0: 0
6 6 4: 1
1 6 0:
*/