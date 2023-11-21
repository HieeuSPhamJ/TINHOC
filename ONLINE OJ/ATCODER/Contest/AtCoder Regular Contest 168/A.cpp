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

const int maxN = 3e5 + 10;

int n;
int bit[maxN];

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
    string s;
    cin >> n;
    cin >> s;
    s = " " + s;
    vector <int> ls;
    ls.push_back(0);
    for (int i = 1, ma = 0; i < n; i++){
        int t;
        if (s[i] == '>'){
            t = ls.back() - 1;
        }
        else{
            t = ls.back() + 1;
            t = max(t,ma + n);
            ma = t;
        }   
        
        ls.push_back(t);
    }

    vector <int> tmp;
    for (auto i: ls){
        tmp.push_back(i);
    }
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), tmp.end());
    for (auto &i: ls){
        i = lower_bound(all(tmp), i) - tmp.begin() + 1;
        // cout << i << " ";
    }

    int res = 0;
    for (auto i: ls){
        // cout << i << " ";
        update(i,1);
        res += get(n) - get(i);
    }
    // cout << endl;
    cout << res << endl;
    return 0;
}