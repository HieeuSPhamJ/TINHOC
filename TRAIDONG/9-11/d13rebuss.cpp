#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define all(adudeepdarklor) adudeepdarklor.begin(),adudeepdarklor.end()
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;

int dp[100][2];
string a, b, sum;

void init(){
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    int e1 = 9;
    int e2 = 9;
    int e3 = 9;
    if (a[0] != '*'){
        s1 = e1 = a[0] - '0';
    }
    if (b[0] != '*'){
        s2 = e2 = b[0] - '0';
    }
    if (sum[0] != '*'){
        s3 = e3 = sum[0] - '0';
    }
    for (int d1 = s1; d1 <= e1; d1++){
    for (int d2 = s2; d2 <= e2; d2++){
    for (int d3 = s3; d3 <= e3; d3++){
        int ab = d1 + d2;
        if (ab % 10 == d3){
            // cout << d1 << " " << d2 << " " << d3 << endl;
            dp[0][ab / 10]++;
        }
    }
    }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> sum;
    reverse(all(a));
    reverse(all(b));
    reverse(all(sum));
    int n = max({(int)a.length(), (int)b.length(), (int)sum.length()});
    int n1 = (int)a.length();
    int n2 = (int)b.length();
    while(a.length() < n){
        a = a + "0";
    }
    while(b.length() < n){
        b = b + "0";
    }
    while(sum.length() < n){
        sum = sum + "0";
    }

    init();

    for (int i = 0; i < n - 1; i++){
        for (int rem = 0; rem <= 1; rem++){
            int now = dp[i][rem];
            if (now == 0){
                continue;
            }
            // cout << "DP: " << i << " " << rem << " " << now << endl;
            int s1 = 0;
            int s2 = 0;
            int s3 = 0;
            int e1 = 9;
            int e2 = 9;
            int e3 = 9;

            if (a[i + 1] != '*'){
                s1 = e1 = a[i + 1] - '0';
            }
            else if (i + 1 == n1 - 1){
                s1 = 1;
            }

            if (b[i + 1] != '*'){
                s2 = e2 = b[i + 1] - '0';
            }
            else if (i + 1 == n2 - 1){
                s2 = 1;
            }

            if (sum[i + 1] != '*'){
                s3 = e3 = sum[i + 1] - '0';
            }
            else if (i + 1 == n - 1){
                s3 = 1;
            }

            for (int d1 = s1; d1 <= e1; d1++){
            for (int d2 = s2; d2 <= e2; d2++){
            for (int d3 = s3; d3 <= e3; d3++){
                int ab = d1 + d2 + rem;
                if (ab % 10 == d3){
                    // cout << d1 << " " << d2 << " " << d3 << endl;
                    // cout << ab / 10 << endl;
                    (dp[i + 1][ab / 10] += now) %= mod;
                }
            }
            }
            }
        }
    }

    // cout << a << endl << b << endl << sum << endl;

    // for (int r = 0; r <= 1; r++){
    // for (int i = 0; i < n; i++){
    //     cout << dp[i][r] << " ";
    // }
    // cout << endl;
    // }
    cout << dp[n - 1][0] << endl;
    return 0;
}