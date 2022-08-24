#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 105; 
const int mod = 1000000007;

string s1, s2, t; 
int last[maxN][26]; 
int dp[maxN][105][2][2]; 

void solve() {
    int tLen = t.size(); 
    int n = s1.size();
    dp[0][0][1][1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < tLen; j++) {
        for (int state1 = 0; state1 <= 1; state1++) {
            for (int state2 = 0; state2 <= 1; state2++) {
            for (int nextChar = 0; nextChar <= 25; nextChar++) {
                if (j == tLen - 1 && nextChar == t[j] - 'a') {
                    continue;
                }
                if (state1 == 1 && nextChar < s1[i] - 'a') {
                    continue;
                }
                if (state2 == 1 && nextChar > s2[i] - 'a') {
                    continue; 
                }
                int nextState1 = state1; 
                if (state1 == 1 && nextChar > s1[i] - 'a') {
                    nextState1 = 0;
                }
                int nextState2 = state2;
                if (state2 == 1 && nextChar < s2[i] - 'a') {
                    nextState2 = 0;
                }
                int nextj = 0; 
                if (j == 0) {
                    if (nextChar == t[j] - 'a') {
                        nextj = 1; 
                    }
                }
                else {
                    nextj = last[j][nextChar];
                }
                if (nextj == tLen) {
                    continue; 
                }
                (dp[i + 1][nextj][nextState1][nextState2] += dp[i][j][state1][state2]) %= mod; 
            }
            }
        }
        }
    }
    int ans = 0;
    for (int j = 0; j < tLen; j++) {
        for (int state1 = 0; state1 <= 1; state1++) {
        for (int state2 = 0; state2 <= 1; state2++) {
            (ans += dp[n][j][state1][state2]) %= mod; 
        }
        }   
    }
    cout << ans << endl;   
}

void init() {
    memset(dp, 0, sizeof(dp)); 
    memset(last, 0, sizeof(last));
    int n = t.size();
    string st = "";
    for (int i = 1; i < n; i++) {
        st += t[i - 1]; 
        for (int c = 0; c <= 25; c++) {
        string tmp = st;
        tmp += char(c + 'a');
        for (int j = i + 1; j >= 1; j--) {
            if (c == t[j - 1] - 'a') {
            int p = i + 1;
            int q = j; 
            while (q > 0) {
                if (t[q - 1] != tmp[p - 1]) {
                break;
                }
                p--;
                q--;
            }
            if (q == 0) {
                last[i][c] = j;
                break;
            }
            }
        }
        }
    }
}

signed main() {
    int test;
    cin >> test;
    while (test--) {
        cin >> s1 >> s2 >> t;
        init();
        solve();     
    }
    return 0; 
}