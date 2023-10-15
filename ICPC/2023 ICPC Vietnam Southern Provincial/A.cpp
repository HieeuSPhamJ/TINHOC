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
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            ls.push_back(x);
        }
        ls.push_back(0);
        sort(all(ls));
        int res = 0;
        for (int i = 1; i < ls.size(); i++){
            res = res xor (ls[i] - ls[i - 1] + 1);
        }
        cout << res << " ";
        if (res == 0){
            cout << "RR" << endl;
        }
        else{
            cout <<"Hieu" << endl;
        }
    }
    return 0;
}