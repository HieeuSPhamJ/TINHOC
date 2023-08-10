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
        vector <int> div2;
        int count = 0;
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;
            while(inp % 2 == 0 and inp != 0){
                inp /= 2;
                count++;
            }
            int j = i;
            int turn = 0;
            while(j % 2 == 0 and j != 0){
                j /= 2;
                turn++;
            }
            div2.push_back(turn);
        }

        // for (auto i: div2){
        //     cout << i << " ";
        // }
        // cout << endl;



        sort(div2.rbegin(), div2.rend());

        int ans = 0;
        for (auto i: div2){
            if (count >= n){
                // cout << ans << endl;
                break;
            }
            count += i;
            ans++;
        }

        if (count >= n){
            cout << ans;
        }
        else{
            cout << -1;
        }
        cout << endl;

    }
    return 0;
}