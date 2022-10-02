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
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    if (s[0] == s[n - 1]){
        cout << "Lose";
        return 0;
    }
    for (int i = 0; i < n - 1; i++){
        if (s[0] == s[i] and s[i + 1] == s[n - 1]){
            ans = 1;
        }
    }
    if (ans == 0){
        cout << "Lose";
    }
    else{
        cout << "Win";
    }

    return 0;
}