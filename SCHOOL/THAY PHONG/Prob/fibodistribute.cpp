#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;

int a[maxN];
unordered_map <int,int> check;
vector <int> ls;

void init(){
    int a = 1;
    int b = 1;
    while(a <= 1e16){
        // cout << a << endl;
        ls.push_back(a);
        check[a] = 1;
        int t = a;
        a += b;
        b = t;
    }
    // cout << check.size() << endl;
}

int pre[maxN];
int dp[maxN];
int isok[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    dp[0] = 1;
    isok[0] = 1;

    for (int i = 1; i <= n; i++){
        // cout << "With: " << i << ": " << endl;
        for (auto sum: ls){
            int l = 1;
            int r = i;
            int t = -1;
            while(l <= r){
                int mid = (l + r) / 2;
                int tsum = (pre[i] - pre[mid - 1]);
                if (tsum == sum){
                    t = mid;
                    break;
                }
                if (tsum > sum){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            if (t == -1){
                continue;
            }
            if (isok[t - 1] == 1){
                // cout << t << endl;
                isok[i] = 1;
                (dp[i] += dp[t - 1]) %= mod;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}