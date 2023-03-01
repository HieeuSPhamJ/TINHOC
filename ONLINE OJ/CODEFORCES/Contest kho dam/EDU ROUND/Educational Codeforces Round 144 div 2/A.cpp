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
    string con = "";
    for (int i = 1; i <= 100; i++){
        if (i % 3 == 0){
            con += 'F';
        }
        if (i % 5 == 0){
            con += 'B';
        }
    }
    // cout << con << endl;
    while(test--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ok = 0;
        // cout << s << endl;
        for (int i = 0; i + s.length() - 1 < 100; i++){
            int check = 1;
            // cout << i << endl;
            for (int k = 0; k < s.length(); k++){
                // cout << con[i + k];
                if (con[i + k] != s[k]){
                    check = 0;
                    break;
                }
            }
            // cout << endl;
            if (check == 1){
                ok = 1;
                break;
            }
        }
        if (ok){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

/*
1
3
FFB
*/