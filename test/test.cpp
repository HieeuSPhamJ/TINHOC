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
        vector <int> s;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            s.push_back(x);
        }
        if (!next_permutation(s.begin(), s.end())){
            cout << -1 << endl;
            continue;
        }
        for (auto i: s){
            cout << i;
        }
        cout << endl;
    }
    return 0;
}