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
    int n;
    string s = "";
    cin >> n;
    for (char i = '1'; i <= '0' + n; i++){
        s = s + i;
    }
    cout << s << endl;
    while(next_permutation(s.begin(), s.end())){
        cout << s << endl;

    }
    return 0;
}