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
    int n,k;
    cin >> n >> k;
    vector <string> s;
    while(n--){
        string x ;
        cin >> x;
        s.push_back(x);
    }
    sort(all(s));
    for (int i = 0; i < k; i++){
        cout << s[i] << endl;
    }
    return 0;
}