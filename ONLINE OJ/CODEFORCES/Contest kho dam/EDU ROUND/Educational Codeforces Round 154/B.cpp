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
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.length();
        int ok = 0;
        for (int i = 1; i < n; i++){
            if (s1[i] == s2[i] and s1[i - 1] == s2[i - 1] and s1[i] == '1' and s1[i - 1] == '0'){
                ok = 1;
            }
        }
        if (ok){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}