#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 10;
int a[maxN];
long long sum[maxN];
int dp[maxN];
int n, maxW;

bool check(int left, int right){
    return (sum[right] - sum[left] <= maxW);
}

int main(){
    freopen("MONKEY.INP", "r", stdin);
    freopen("MONKEY.OUT", "w", stdout);
    cin >> n >> maxW;
    sum[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int temp = 0;
        int left = 0;
        int right = i;
        while(left <= right){
            int mid = (left + right) / 2;
            if (check(mid, i) == 1){
                // cout << check(mid, i) << ' ' << left << ' ' << right << endl;
                ans = max(i - mid, ans);
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        
    }
    cout << ans;
    return 0;
}