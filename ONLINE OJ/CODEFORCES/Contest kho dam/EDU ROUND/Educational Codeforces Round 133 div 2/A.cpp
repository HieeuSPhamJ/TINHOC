#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

vector <int> lists = {-3,-2,2,3};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;

        int ans = 1e9;
        
        if (n % 2 == 0){
            // ans = min(ans, n / 2);
            if (ans > (n / 2)){
                    ans = (n / 2);
                    // cout << "+" << ' ';
                }
        }
        if (n % 3 == 0){
            ans = min(ans, n / 3);
            if (ans > (n / 3)){
                    ans = (n / 3);
                    // cout << "-" << ' ';
                }
        }

        if (n - 4 >= 0 and (n - 4) % 3 == 0){
            ans = min(ans, n / 3 + 1);
        }


        for (auto i: lists){
            if (n + i >= 0 and (n + i) % 3 == 0){
                if (ans > (n + i) / 3 + 1){
                    ans = (n + i) / 3 + 1;
                    // cout << i << ' ';
                }
            }
            if (n + i >= 0 and (n + i) % 2 == 0){
                if (ans > (n + i) / 2 + 1){
                    ans = (n + i) / 2 + 1;
                    // cout << i << ' ';
                }
            }
            
        
        }
        cout << ans << endl;
    }
    return 0;
}