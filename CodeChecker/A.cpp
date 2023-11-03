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



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int maxN = 1e5 + 10;
map <int,vector<int>> ls;
vector <int> a[maxN];

struct dickcha{
    int n;
    vector <int> bit;
    dickcha(int _n){
        n = _n;
        bit.resize(n + 1);
    }
    void update(int i, int v){
        while(i <= n){
            bit[i] += v;
            i += (i & (-i));
        }
    }

    int get(int i){
        int res = 0;
        while(i){
            res += bit[i];
            i -= (i & (-i));
        }
        return res;
    }
};

void nenso(vector <int> &ts){
    set <int> s;
    for (auto i: ts){
        s.insert(i);
    }
    int cnt = 1;
    map <int,int> cv;
    for (auto i: s){
        cv[i] = cnt;
        cnt++;
    }
    for (auto &i: ts){
        i = cv[i];
    }
}

int b[maxN];

map <int,int> HASH;

int random(int left, int right){
    if (left >= right){
        return left;
    }
    return (rng() % (right - left + 1)) + left;
}

signed main(){
    srand(time(0));
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
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
    for (int i = 1; i <= n; i++){
        cin >> b[i];
        if (HASH[b[i]] == 0){
            HASH[b[i]] = random(1,1e18);
        }
    }

    // for (int i = 1; i <= n; i++){
    //     cout << HASH[b[i]] << " ";
    // }

    // cout << endl;

    
    ls[HASH[0]].push_back(0);
    for (int i = 1, p = 0, x = 0; i <= n; i++){
        int inp = b[i];
        p += inp;
        x = x xor HASH[inp];
        ls[x].push_back(p);
        // cout << i << " " << HASH[inp] << " " << x << " " << p << endl;
    }
    n = 0;
    for (auto i: ls){
        n++;
        // cout << i.fi << ": ";
        for (auto x: i.se){
            // cout << x << " ";
            a[n].push_back(x);
        }
        // cout << endl;
    }
    int res = 0;
    for (int t = 1; t <= n; t++){
        dickcha BIT(a[t].size());
        nenso(a[t]);
        // for (auto i: a[t]){
        //     cout << i << " ";
        // }
        // cout << endl;
        for (auto i: a[t]){
            res += BIT.get(i - 1);
            BIT.update(i,1);
        }
    }
    cout << res << endl;
    return 0;
}

/*

2 -1 3 -2 5 -2 5 -4 3 2 

*/