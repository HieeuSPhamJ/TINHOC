#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int maxM = 1 << 17;

int a[20][20];
int dp[20][maxM];

bool check(int i, int j, int mask){
    string s;
    while(mask > 0){
        s = s + char((mask % 2) + '0');
        mask /= 2;
    }
	s += "0000000000000000";
	// cout << s;

	// cout << endl;
    if (s[i] == '1' and s[j] == '0'){
        return 1;
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < 20; i++){
        for (int j = 1; j < maxM; j++){
            dp[i][j] = inf;
        }
    }

    for (int i = 0; i < n; i++){
        dp[i][1 << i] = 0;
    }

    for (int mask = 0; mask <= (1 << n) - 1; mask++) {
        for (int i = 0; i < n; i++){
            for (int  j = 0; j < n; j++){
                //check bit thứ j = 0 và i = 1 anh
                if (check(i,j,mask)){
                    dp[j][mask | (1 << j)] = min(dp[j][mask | (1 << j)], dp[i][mask] + a[i][j]);
                }
            }
        }
    }


    int ans = inf;
    for (int i = 0; i < n; i++){
        ans = min(ans, dp[i][(1 << n) - 1]);
    }


    cout << ans;
    return 0;
}