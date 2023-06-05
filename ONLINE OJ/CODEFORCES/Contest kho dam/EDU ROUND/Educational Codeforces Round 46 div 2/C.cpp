#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 2e5 + 10;

int res[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <ii> ls;

    set <int> val;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        ls.push_back({a,b});
        val.insert(a);
        val.insert(b);
    }

    sort(rall(ls));
    multiset <int> s;
    int last = *val.begin() - 1;
    for (auto i: val){
        if (last + 1 <= i - 1){
            // cout << last + 1 << ' ' << i - 1 << ' ' << s.size() << endl;
            res[s.size()] += (i - 1 - (last + 1)) + 1;
        }
        while(ls.size() and ls.back().fi == i){
            s.insert(ls.back().se);
            ls.pop_back();
        }
        // cout << i << " " << s.size() << endl;
        res[s.size()]++;
        // cout << s.size() << endl;
        while(s.size() and *s.begin() == i){
            s.erase(s.begin());
        }
        last = i;
    }

    for (int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }

    return 0;
}