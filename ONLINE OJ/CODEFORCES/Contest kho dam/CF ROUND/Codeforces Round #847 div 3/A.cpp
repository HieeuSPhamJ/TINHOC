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
    string s = "3141592653589793238462643383279502884197169399375105820974944";
    int test;
    cin >> test;
    while(test--){
        string t;
        cin >> t;
        int res = 0;
        for (int i = 0; i < t.length(); i++){
            if (t[i] == s[i]){
                res++;
            }
            else{
                break;
            }
        }

        cout << res << endl;
    }
    return 0;
}