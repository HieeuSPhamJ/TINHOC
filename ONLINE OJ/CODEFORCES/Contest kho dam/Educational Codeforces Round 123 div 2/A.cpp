#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int check[500] = {0};
        int ans = 1;
        for (int i = 1; i <= 6; i++){
            char inp;
            cin >> inp;
            if ('a' <= inp and inp <= 'z'){
                // cout << '-';
                check[inp - 'a'] = 1;
            }
            else{
                // cout << '+';
                // cout << check['R' - 'A'] << ;
                if (check[inp - 'A'] == 0){
                    ans = 0;
                }
            }
        }
        // cout << endl;
        if (ans == 1){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}