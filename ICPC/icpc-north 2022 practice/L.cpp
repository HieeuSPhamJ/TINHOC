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
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        stack <char> ans;
        while(n > 1){
            if (n % 2){
                ans.push('R');
            }
            else{
                ans.push('L');
            }
            n /= 2;
        }

        while(!ans.empty()){
            cout << ans.top();
            ans.pop();
        }
        cout << endl;
    }
    return 0;
}