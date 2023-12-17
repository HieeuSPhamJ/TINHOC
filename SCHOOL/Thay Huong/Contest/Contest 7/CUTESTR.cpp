#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;
const ii base = {40,100 + rand() % 30};
const ii mod = {1e9 + 7,1e9 + 9};

ii mul(ii a, ii b){
    return {(a.fi * b.fi) % mod.fi, (a.se * b.se) % mod.se};
}
ii add(ii a, ii b){
    return {(a.fi + b.fi) % mod.fi, (a.se + b.se) % mod.se};
}
ii sub(ii a, ii b){
    return {(a.fi - b.fi + mod.fi) % mod.fi, (a.se - b.se + mod.se) % mod.se};
}

ii operator + (const ii &a, const ii &b){
    return add(a,b);
}
ii operator * (const ii &a, const ii &b){
    return mul(a,b);
}
ii operator - (const ii &a, const ii &b){
    return sub(a,b);
}

int n;
int a[maxN];
ii ha[maxN];
ii po[maxN];

void init(){
    ha[0] = {0,0};
    po[0] = {1,1};
    for (int i = 1; i <= n; i++){
        ha[i] = (ha[i - 1] * base) + ii(a[i], a[i]);
        po[i] = po[i - 1] * base;
    }
}

int fl[maxN];

ii get(int l, int r){
    return ha[r] - (ha[l - 1] * po[r - l + 1]);
}

bool cmp(int l1, int r1, int l2, int r2){
    int l = 0;
    int r = min(r1 - l1, r2 -l2);
    int k = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if (get(l1, l1 + mid) == get(l2, l2 + mid)){
            l = mid + 1;
            k = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    // cout << "cmp: " << l1 << " " << r1 << " " << l2 << " " << r2 << ": " << k << endl;
    // cout << a[l1 + 1] << " " << a[l2 + 1] << endl; 
    if (k == min(r1 - l1 + 1, r2 - l2 + 1)){
        return r1 - l1 <= r2 - l2;
    }
    if (a[l1 + k] < a[l2 + k]){
        return 1;
    }
    return 0;
}

void solve(string _s){
    n = _s.length();
    memset(a, -1, sizeof(a));
    for (int i = 1; i <= n; i++){
        a[i] = _s[i - 1] - 'a';
    }
    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    init();
    deque <int> ls;
    multiset <ii> s;
    for (int i = 1; i <= n; i++){
        fl[i] = i;
        if (i > 1 and a[i - 1] <= a[i]){
            fl[i] = fl[i - 1];
        }
        if (a[i] > a[i + 1]){
            cout << i << " ";
            if (fl[i] == 1){
                s.insert({a[1],1});
                continue;
            }
            ls.push_back(i);
        }
    }
    cout << endl;

    // cout << cmp(1,7,8,8) << endl;
    while(ls.size() > 1){
        deque <int> ts;
        for (auto i: ls){
            int ok = 0;
            // cout << "With: " << i << ": ";
            for (auto x: s){
                // cout << x.se << " " << fl[i] - 1 << endl;
                if (cmp(x.se, fl[i] - 1, fl[i], i)){
                    // cout << x.se << " " << fl[i] - 1 << " < " << fl[i] << " " << i << endl;
                    s.insert({a[fl[i]], fl[i]});
                    ok = 1;
                    break;
                }
                if (x.fi > a[fl[i]]){
                    cout << "NO" << endl;
                    return;
                }
            }
            if (ok == 0){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

/*
1 2 3 4 5 6 7 8 9 10
0 5 3 1 3 3 0 5 4 3
0 5
3
1 3 3
0 5 4 3
*/

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("CUTESTR.inp", "r")){
        freopen("CUTESTR.inp", "r", stdin);
        freopen("CUTESTR.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}