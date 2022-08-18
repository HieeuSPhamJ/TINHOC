#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;
 
const int inf = 110;
 
int dp[110];
int str[110];
 
void print(){
    for (int i = 1; i <= 6; i++){
        cout << dp[i] << ' ';
    }
    cout << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        for (int i = 0; i <= 105; i++){
            dp[i] = inf;
            str[i] = -1;
        }
        string t;
        cin >> t;
        int n;
        cin >> n;
        vector <string> lists;
        for (int i = 1; i <= n; i++){
            string inp;
            cin >> inp;
            lists.push_back(inp);
        }
 
        t = " " + t;
 
        dp[0] = 0;
 
        for (int i = 1; i < t.size(); i++){
            for (int id = 1; id <= lists.size(); id++){
                string newString = lists[id - 1];
                if (newString.size() <= i){
                    int lastId = i - newString.size();
                    string nowString = t.substr(lastId + 1, newString.size());
                    int minVal = 1e9;
                    int tt = lastId;
                    for (int j = i; j >= tt; j--){
                        if (dp[j] != inf){
                            if (minVal > dp[j]){
                                minVal = dp[j];
                                lastId = j;
                            }
                        }
                    }
 
                    if (dp[lastId] == inf or nowString != newString){
                        continue;
                    }
                    dp[i] = min(dp[i], dp[lastId] + 1);
                    if (dp[i] == dp[lastId] + 1) str[i] = id;
                }
            }
        }
        if (dp[t.size() - 1] == inf){
            cout << -1 << endl;
            continue;
        }
        int ans = dp[t.size() - 1];
        cout << ans;
        cout << endl;
        n = (t.size() - 1);
        for (int i = n; i >= 1 and ans >= 1; i--){
            if (dp[i] == ans){
                cout << str[i] << " " << i - lists[str[i] - 1].size() + 1 << endl;
                ans--;
            }
        }
    }
    return 0;
}