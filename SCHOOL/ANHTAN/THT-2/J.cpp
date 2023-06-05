#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> ls;
    int res = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        while(ls.size() and ls.back() > x){
            ls.pop_back();
        }
        if (!ls.size() or ls.back() != x){
            ls.push_back(x);
            res++;
        }
    }
    cout << res << endl;
    return 0;
}