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
        map <int,int> a;
        for (int i = 0; i < s.length(); i++){
            a[s[i] - 'a']++;
        }

        int ok = 1;
        for (auto i: a){
            if (i.se == 1){
                ok = 0;
            }
        }

        if (s.length() % 2 == 0){
            if (a.size() >= 2){
                cout << "YES";
            }
            else{
                cout << "NO";
            }
        }
        else{
            if (a.size() >= 3){
                cout << "YES";
            }
            else if (a.size() == 2 and ok == 1){
                cout << "YES";
            }
            else{
                cout << "NO";
            }
        }
        cout << endl;

    }
    return 0;
}