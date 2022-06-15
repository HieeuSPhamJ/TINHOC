#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

const int maxN = 1e4 + 10;

string s[maxN];
string sO[maxN];
int dp[maxN];
unordered_map <string, int> countMap;

bool cmp(string a, string b){
    return a.length() < b.length();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s[i];
        countMap[s[i]]++;
    }
    // for (int i = 1; i <= n; i++){
    //         cout << countMap[s[i]] << endl;
    // }

    for (int i = 1; i <= n; i++){
        unordered_map <string, int> tempMap;
        int ans = 0;
        for (int l = 0; l < s[i].length(); l++){
            for (int r = l; r < s[i].length(); r++){
                string tempS = "";
                for (int x = l; x <= r; x++){
                    tempS = tempS + s[i][x];
                }
                // cout << tempS << ' ';
                if (tempMap[tempS] == 0){
                    ans += countMap[tempS];
                    tempMap[tempS] = 1;
                }
            }   
        }
        // cout << endl;
        cout << ans - 1 << endl;
    }

    return 0;
}