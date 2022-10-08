#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 100010;

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    while (test--){
        int x;
        cin >> x;
        int left = 1;
        int right = n;
        int ans = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            if (a[mid] > x){
                right = mid - 1;
            }
            else{
                ans = mid;
                left = mid + 1;
            }
        }
        if (a[ans] == x){
            cout << 0;
        }
        else{
            if ((n - ans) % 2){
                cout << "-";
            }
            else{
                cout << "+";
            }
        }
        cout << endl;
    }
    return 0;
}