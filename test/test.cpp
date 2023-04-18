#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

<<<<<<< HEAD
const int maxN = 5e3 + 10;

int a[maxN];
int dp[maxN][maxN];
int p[maxN];
int nxt[maxN][27];
=======
const int maxN = 1e6 + 10;

int dp[maxN];

void aduuuu(){
    for (int i = 0; i < maxN; i++){
        dp[i] = 1e18;
    }
    dp[0] = 0;
    for (int i = 0; i < maxN; i++){
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        if (i > 1){
            for (int j = 2; j <= i and i * j < maxN; j++){
                dp[i * j] = min(dp[i * j], dp[i] + 1);
            }
        }
    }
}
>>>>>>> eec7c1378889e76c8deadccb564c08100976fa9d

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
<<<<<<< HEAD
    int m,n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++){
        char x;
        cin >> x;
        a[i] = x - 'a';
    }
    for (int i = 2; i <= m; i++){
        int t = p[i - 1];
        // cout << "With: " << t << endl;
        while (t > 0 and a[t + 1] != a[i]){
            // cout << t << " " << p[t] << endl;
            t = p[t];
        }
        p[i] = t;
        // cout << t << " " << i << " " << t + 1 << endl; 
        if (a[i] == a[t + 1]){
            p[i]++;
        }
    }

    for (int i = 1; i <= m; i++){
        for (int c = 0; c <= 25; c++){
            int t = p[i];
            while(t > 0 and a[t + 1] =! c){
                t = p[t];
            }
            
        }
    }
    cout << endl;
    
=======
    aduuuu();
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

>>>>>>> eec7c1378889e76c8deadccb564c08100976fa9d
    return 0;
}