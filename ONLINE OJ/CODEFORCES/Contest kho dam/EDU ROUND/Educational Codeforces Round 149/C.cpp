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
        int n = s.length();
        reverse(all(s));
        int last = -1;
        for (int i = 0; i < n; i++){
            if (s[i] != '?'){
                last = s[i] - '0';
                break;
            }
        }
    
        if (last != -1){
            vector <int> ls;
            for (int i = 0; i < n; i++){
                if (s[i] == '?'){
                    ls.push_back(last);
                }
                else{
                    ls.push_back(s[i] - '0');
                    last = s[i] - '0';
                }
            }
            reverse(all(ls));
            for (auto i: ls){
                cout << i;
            }
        }
        else{
            for (int i = 1; i <= n; i++){
                cout << 0;
            }
        }
        cout << endl;
    }

    return 0;
}