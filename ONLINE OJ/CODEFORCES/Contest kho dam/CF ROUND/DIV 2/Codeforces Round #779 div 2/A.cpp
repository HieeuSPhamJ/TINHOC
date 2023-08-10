#include<bits/stdc++.h>
using namespace std;

const int maxN = 111;
char s[maxN];

/*
    10110110110110110101101101101101101
    1010110000100000101
    
*/
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s[i];
    }
    int count[3] = {0};
    int countDup[3] = {0};
    int ans = 0;
    for (int i = 1; i < n; i++){
        if (s[i] == '0' and s[i + 1] == '0'){
            ans += 2;
            // cout << '!';
        }
        else if (s[i] == '1' and s[i + 1] == '0' and s[i - 1] == '0'){
            ans++;
            // cout << '#';
        }
        // cout << s[i] << s[i + 1] << endl;
    }
    cout << ans;

    
    
}

int main(){
    int test;
    cin >> test;
    while(test--){
        solve();
        cout << endl;
    }

    return 0;
}

