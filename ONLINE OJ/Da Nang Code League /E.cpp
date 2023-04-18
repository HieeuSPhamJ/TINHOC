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
        string s;
        cin >> s;

        int n = s.length();
        s = " " + s;
        int ok = 1;
        if (s[1] == 'D'){
            ok = 0;
        }
        for (int i = 1, last = 0; i <= n; i++){
            if (s[i] == 'D'){
                last++;
            }
            else{
                last = 0;
            }
            if (last > 2){
                ok = 0;
                break;
            }
            if (s[i] != 'D' and s[i] != 'F'){
                ok = 0;
                break;
            }
        }
        if (ok){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}