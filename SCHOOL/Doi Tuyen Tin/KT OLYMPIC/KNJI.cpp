#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

vector <int> s;

signed main(){
    freopen("KNJI.INP", "r", stdin);
    freopen("KNJI.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        s.push_back(x);
    }
    int ans = n;
    while (s.size()){
        if (s.back() == ans){
            ans--;
        }
        s.pop_back();
    }

    cout << ans << endl;
    return 0;
}