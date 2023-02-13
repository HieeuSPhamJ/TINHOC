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
    int n;
    cin >> n;
    vector <char> s;
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        s.push_back(x);
    }
    
    vector <char> org;
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        org.push_back(x);
    }

    vector <char> s1, s2;
    s1 = s;
    s2 = org;
    sort(all(s1));
    sort(all(s2));
    if (s1 != s2){
        cout << -1 << endl;
        return 0;
    }
    int ans = n;

    while(!s.empty() and !org.empty()){
        if (s.back() == org.back()){
            s.pop_back();
            org.pop_back();
            ans--;
        }
        else{
            org.pop_back();
        }
    }

    cout << ans << endl;
    return 0;
}