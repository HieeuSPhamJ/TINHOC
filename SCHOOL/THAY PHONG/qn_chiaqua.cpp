#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int cnt[3];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        x /= 100;
        cnt[x]++;
        sum += x;
    }
    if (sum % 2){
        cout << "NO";
        return 0;
    }

    sum /= 2;
    // cout << cnt[1] << " " << sum << endl;
    if (cnt[1] >= sum){
        cout << "YES";
        return 0;
    }

    if ((cnt[1] != 0) == sum % 2){
        cout << "YES";
        return 0;
    }
    
    cout << "NO";
    return 0;
}