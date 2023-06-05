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
        string s;
        cin >> s;
        set <ii> ss;
        for (int i = 1; i < s.size(); i++){
            ss.insert({(int)(s[i - 1] - 'a'), (int)(s[i] - 'a')});
        }
        cout << ss.size() << endl;
    }
    return 0;
}