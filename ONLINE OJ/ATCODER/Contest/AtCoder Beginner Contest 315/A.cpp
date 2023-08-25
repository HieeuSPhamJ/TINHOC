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
    string s;
    cin >> s;
    for (int i = 0;  i < s.length(); i++){
        if (s[i] != 'a' and s[i] != 'e' and s[i] != 'u' and s[i] != 'i' and s[i] != 'o'){
            cout << s[i];
        }
    }
    return 0;
}