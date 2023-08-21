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
        if (s == "()"){
            cout << "NO" << endl;
        }
        else{
            int n = s.length();
            string s1 = "";
            string s2 = "";
            for (int i = 1; i <= n; i++){
                s1 = s1 + "()";
                s2 = s2 + "(";
            }   
            for (int i = 1; i <= n; i++){
                s2 = s2 + ")";
            }   
            cout << "YES" << endl;
            if (s1.find(s) >= s1.length()){
                cout << s1 << endl;
                continue;
            }
            else{
                cout << s2 << endl;
            }
        }
    }
    return 0;
}