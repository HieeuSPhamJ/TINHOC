#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int solve(int n, int a, int b){
    int left = 1;
    int right = 1e18;
    int ans = 1e18;
    while(left <= right){
        int mid = (left + right) / 2;
        int temp=mid/ a + mid / b;
        if(temp >= n){
            right = mid - 1;
            ans = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return ans;
}


signed main(){
    freopen("DEMBAI.inp", "r", stdin);
    freopen("DEMBAI.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, a, b;
        cin >> n >> a >> b;
        int ans = solve(n,a,b);
        cout << (ans + a - 1) / a + (ans + b - 1) / b<< ' ' << max((ans + a - 1) / a * a, (ans + b - 1) / b * b) << endl;
    }
    return 0;
}