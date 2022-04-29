#include<bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
int a[100010];
vector <int> b;
int stop;
int dp[100010];

void check(string s){
    b.clear();
    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] == '0'){
            b.push_back(a[i + 1]);
        }
        else{
            b.insert(b.begin(), a[i + 1]);
        }
    }
    
    dp[0] = 1;
    for (int i = 1; i < n; i++){
        int temp = 0;
        for (int j = i - 1; j >= 0; j--){
            if (b[i] > b[j]){
                temp = max(temp, dp[j]);
            }
        }
        // cout << dp[i] << ' ';
        dp[i] = temp + 1;
    }
    // cout << endl;
    // cout << dp[n] << endl;
    ans = max(ans, dp[n - 1]);
}

void backtracking(int index, string s){
    if (index > n){
        // cout << s << endl;
        check(s);
        // cin >> stop;
        return;
    }
    backtracking(index + 1, s + '0');
    backtracking(index + 1, s + '1');
    
    
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    backtracking(1, "");
    cout << ans;

    return 0;
}
