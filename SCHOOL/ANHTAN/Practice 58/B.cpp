#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
// #define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;

unordered_map <int,int> trash_can;
int prefix[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    while(cin >> s){
        int n = s.length();
        int ans = 0;
        trash_can.clear();
        for (int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1];
            if (s[i - 1] == 'A'){
                prefix[i]++;
            }
            else{
                prefix[i]--;
            }

            if (abs(prefix[i]) <= 1){
                ans = max(ans, i);
            }
            // cout << "With: " << i << endl;         
            for (int pre = prefix[i] - 1; pre <= prefix[i] + 1; pre++){
                int t = trash_can[pre];

                if (t != 0){
                    ans = max(ans, i - t);
                }
            }
            
            if (trash_can[prefix[i]] == 0){
                trash_can[prefix[i]] = i;
            }
            else{
                trash_can[prefix[i]] = min(trash_can[prefix[i]], i);
            }
        }

        cout << ans << endl;
    }

    return 0;
}

/*

-2

-3 <= x <= -2

prei - prej <= 1
prej >= prei - 1

prei - prej >= -1
prej <= prei + 1

*/