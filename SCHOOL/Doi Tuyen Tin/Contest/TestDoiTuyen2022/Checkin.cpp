#include<bits/stdc++.h>
using namespace std;

const int maxN = 100010;

int n, m;
int a[maxN];

bool check(long long mid){
    long long count = m;
    for (int i = 1; i <= n; i++){
        count -= (mid / a[i]);
        if (count <= 0){
            return true;
        }
    }
    return false;
}

int main(){
    freopen("Checkin.INP", "r", stdin);
    freopen("Checkin.OUT", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    long long left = 1;
    long long right = 1e18;
    long long mid;
    long long ans = right;
    while(left <= right){
        mid = (left + right) / 2;
        if (check(mid)){
            right = mid - 1;
            ans = min(ans, mid);
        }
        else{
            left = mid + 1;
        }
    }
    cout << ans;

    return 0;
}