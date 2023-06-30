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

const int maxN = 1e6 + 10;

int a[maxN];
int t[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int test;
    cin >> test;
    vector <ii> ls;
    while(test--){
        int x, y, v;
        cin >> x >> y >> v;
        t[x] += v;
        t[y + 1] -= v;
        ls.push_back({x,y});
    }

    for (int i = 1, te = 0; i <= n; i++){
        te += t[i];
        a[i] += te;
    }

    sort(rall(ls));

    multiset <ii> s;

    for (int i = 1, sum = 0; i <= n; i++){
        sum += s.size();
        while(ls.back().fi == i){
            s.insert({ls.back().se, ls.back().se - ls.back().fi});
            ls.pop_back();
        }
        a[i] += sum;
        while(s.size() and (*s.begin()).fi == i){
            sum -= (*s.begin()).se;
            s.erase(s.begin());
        }
    }

    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}