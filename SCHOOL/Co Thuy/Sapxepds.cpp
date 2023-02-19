#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3e5 + 10;

int n;
int a[maxN];
vector <int> aonly;

void nenso(){
    vector <int> lists;
    unordered_map <int,int> conv;
    for (int i = 1; i <= n; i++){
        lists.push_back(a[i]);
    }
    sort(all(lists));
    int cnt = 0;
    for (auto i: lists){
        if (aonly.empty() or aonly.back() != i){
            aonly.push_back(i);
            cnt++;
            conv[i] = cnt;
        }
    }
    for (auto &i: aonly){
        i = conv[i];
    }
    for (int i = 1; i <= n; i++){
        a[i] = conv[a[i]];
    }
}

int last[maxN];
int meet[maxN];
int dp[maxN];


signed main(){
    // freopen("Sapxepds.INP", "r", stdin);
    // freopen("Sapxepds.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        aonly.clear();
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            last[i] = 0;
            meet[i] = 1e18;
            dp[i] = 0;
        }
        nenso();
        for (int i = 1; i <= n; i++){
            last[a[i]] = i;
            meet[a[i]] = min(meet[a[i]], i);
        }
        int ans = 0;
        for (auto i: aonly){
            dp[i] = 1;
            if (last[i - 1] <= meet[i]){
                dp[i] = max(dp[i],dp[i - 1] + 1);
                ans = max(ans,dp[i]);
            }
        }
        cout << aonly.size() - ans << endl;
        
    }
    return 0;
}