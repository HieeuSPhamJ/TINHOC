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

const int maxN = 3e5 + 10;

vector <int> res[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("discounts.inp", "r")) {
        freopen("discounts.inp", "r", stdin);
        freopen("discounts.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> n >> k;
    vector <int> ls;
    vector <pair<ii,int>> lists;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        int t, x;
        cin >> x >> t;
        lists.push_back({{x,t},i});
        
    }
    sort(rall(lists));
    int cnt = 1;
    for (auto i: lists){
        int x = i.fi.fi;
        int t = i.fi.se;
        if (t == 1 and cnt <= k){
            sum += x;
            res[cnt].push_back(i.se);
            cnt++;
        }
        else{
            sum += 2 * x;
            ls.push_back(i.se);
        }
    }
    cout << sum / 2 << ".";
    if (sum % 2){
        cout << 5 << endl;
    }
    else{
        cout << 0 << endl;
    }
    for (int i = k; ls.size(); i--){
        if (i == 0){
            i = k;
        }
        res[i].push_back(ls.back());
        ls.pop_back();
    }
    for (int i = 1; i <= k; i++){
        cout << res[i].size() << " ";
        for (auto i: res[i]){
            cout << i << " "; 
        }
        cout << endl;
    }
    return 0;
}