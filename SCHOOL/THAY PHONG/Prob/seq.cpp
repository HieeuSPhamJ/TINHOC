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

int sum(int l, int r){
    return prefix[r] - prefix[l - 1];
}

int dp(int l, int r){
    // cout << "#" << l << " " << r << "#" << endl;
    if (l == r){
        return 0;
    }
    int left = l;
    int right = r - 1;
    int check = 0;

    while(left <= right){
        int mid = (left + right) / 2;
        if (sum(l, mid) < sum(mid + 1, r)){
            left = mid + 1;
        }
        else if (sum(l, mid) > sum(mid + 1, r)){
            right = mid - 1;
        }
        else{
            check = mid;
            break;
        }
    }

    if (check){
        return max(dp(l,check), dp(check + 1, r)) + 1;
    }
    return 0;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            prefix[i] = prefix[i - 1] + a[i];
        }

        cout << dp(1,n) << endl;
        // int left = 1;
        // int right = n;
        // int check = 0;

        // while(left <= right){
        //     int mid = (left + right) / 2;
        //     cout << left << " " << mid << " " << right << endl;
        //     if (sum(1, mid) < sum(mid + 1, n)){
        //         left = mid + 1;
        //     }
        //     else if (sum(1, mid) > sum(mid + 1, n)){
        //         right = mid - 1;
        //     }
        //     else{
        //         check = mid;
        //         break;
        //     }
        // }
        // cout << check;
    }
    return 0;
}