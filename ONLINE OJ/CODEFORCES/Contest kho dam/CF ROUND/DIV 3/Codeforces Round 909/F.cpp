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
    int test;
    cin >> test;
    while(test--){
        int n, q;
        cin >> n >> q;
        vector <int> s1, s2;
        s1.push_back(1);
        s2.push_back(2);
        for (int i = 2; i <= n; i++){
            cout << i - 1 << " " << i << endl;
            s1.push_back(i);
        }
        while(q--){
            // cout << "====" << endl;
            int x;
            cin >> x;
            x++;
            if (s1.size() == x){
                cout << -1 << " " << -1 << " " << -1 << endl;
                goto bru;
            }
            if (s1.size() > x){
                cout << s1[x] << " " << s1[x - 1] << " " << s2.back() << endl;
                for (int i = x; i < s1.size(); i++){
                    s2.push_back(s1[i]);
                }
                while(s1.size() > x){
                    s1.pop_back();
                }
            }
            else{
                x--;
                x = n - x;
                // cout << x << endl;
                cout << s2[x] << " " << s2[x - 1] << " " << s1.back() << endl;
                for (int i = x; i < s2.size(); i++){
                    s1.push_back(s2[i]);
                }
                while(s2.size() > x){
                    s2.pop_back();
                }
            }

            bru:;
            // for (auto i: s1){
            //     cout << i << " ";
            // }
            // cout << endl;
            // for (auto i: s2){
            //     cout << i << " ";
            // }
            // cout << endl;
        }
    }
    return 0;
}