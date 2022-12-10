#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector <int> x;
        while(n--){
            char xx; cin >> xx;
            x.push_back(xx - ('a' - 1));
        }
        sort(x.begin(), x.end());
        cout << x.back() << endl;
    }
    return 0;
}