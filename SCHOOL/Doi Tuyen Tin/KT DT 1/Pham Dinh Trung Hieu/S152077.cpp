#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int prefix[maxN];

signed main(){
    freopen("S152077.INP", "r", stdin);
    freopen("S152077.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int mid = -1;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (x < k){
            a[i] = -1;
        }
        else if (x > k){
            a[i] = 1;
        }
        else{
            mid = i;
            a[i] = 0;
        }
    }

    for (int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + a[i];
    }

    unordered_map <int,int> cnt;

    for (int i = 0; i < mid; i++){
        cnt[prefix[i]]++;
    }

    int ans = cnt[prefix[mid - 1]];

    for (int i = mid + 1; i <= n; i++){
        ans += cnt[prefix[i]];
    }

    cout << ans << endl;

    return 0;
}