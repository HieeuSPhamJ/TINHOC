#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int mod = 1e9 + 7;
const int maxN = 305;

long long dp[maxN][maxN][maxN];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        int n = s.size();
        s = ' ' + s;
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= n + 1; j++){
                for (int k = 0; k <= n + 1; k++){
                    dp[i][j][k] = 0;
                }   
            }
        }
        dp[0][0][0] = 1;
        for (int i = 0; i <= n; i++){
            for (int oneEye = 0; oneEye <= i; oneEye++){
                for (int halfFace = 0; halfFace <= i; halfFace++){
                    long long now = dp[i][oneEye][halfFace]; 
                    if (dp[i][oneEye][halfFace] <= 0){
                        continue;
                    }
                    if (s[i + 1] == 'T'){
                        (dp[i + 1][oneEye + 1][halfFace] += now) %= mod;
                        if (halfFace > 0){
                            (dp[i + 1][oneEye][halfFace - 1] += now * halfFace) %= mod; 
                        }
                    }
                    else{
                        (dp[i + 1][oneEye][halfFace] += halfFace * now) %= mod;
                        if (oneEye > 0){
                            (dp[i + 1][oneEye - 1][halfFace + 1] += oneEye * now) %= mod;
                        }
                    }
                }
            }
        }
        cout << dp[n][0][0] % mod;

        cout << endl;
    }


    return 0;
}