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
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector <int> ls;
        while(n--){
            int x;
            cin >> x;
            if (ls.size() and ls.back() > x){
                ls.push_back(x);
            }
            ls.push_back(x);
        }
        cout << ls.size() << endl;
        for (auto i: ls){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}