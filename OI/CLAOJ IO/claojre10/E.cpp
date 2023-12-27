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


const int maxN = 1e6 + 10;

int b[maxN];
int a[maxN];

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
    string t;
    cin >> s >> t;
    int na = s.length();
    int nb = t.length();
    for (int i = 1; i <= na; i++){
        a[i] = s[i - 1] - 32 + 126;
    }
    vector <ii> ls;
    for (int i = 1; i <= nb; i++){
        b[i] = t[i - 1] - 32 + 126;
        ls.push_back({b[i], i - 1});
    }
    sort(all(ls));
    for (int i = (int)ls.size() - 1; i >= 1; i--){
        if (ls[i - 1].fi < ls[i].fi){
            ls[i].fi = 1;
        }
        else{
            ls[i].fi = 0;
        }
    }
    ls[0].fi = 0;
    // for (auto i: ls){
    //     cout << i.fi << " " << i.se << endl;
    // }
    vector <int> res;
    for (int i = 1; i + nb - 1 <= na; i++){
        for (int j = 1; j < (int)ls.size(); j++){
            if (a[i + ls[j].se] + ls[j].fi < a[i + ls[j - 1].se]){
                goto bru;
            }
        }
        res.push_back(i);
        bru:;
    }

    cout << (int)res.size() << endl;

    for (auto x: res){
        cout << x << " ";
    }
    cout << endl;


    return 0;
}