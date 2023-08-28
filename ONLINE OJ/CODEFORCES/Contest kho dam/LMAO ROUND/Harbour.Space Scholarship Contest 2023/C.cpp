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
        ls.push_back(n);
        int n0 = n;
        int lon = -1;
        for (int i = 0; n0 > 1; i++){
            if (n0 % 2){
                ls.push_back(n - (1 << i));
                n -= (1 << i);
            }
            n0 /= 2;
            lon = (n0 << (i + 1));
        }

        while(lon){
            ls.push_back(lon / 2);
            lon /= 2;
        }
        ls.pop_back();
        cout << ls.size() << endl;
        for (auto i: ls){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}