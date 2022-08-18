#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 200005;

int a[maxN];

signed main () {
    int test;
    cin >> test;
    while (test--){
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int count = 0;
        int left = 1;
        int res = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                count++;
            }
            while (count > k) {
                if (a[left] == 0) {
                count--;
                }
                left++;
            }
            if (res < i - left + 1) {
                res = i - left + 1;
            }
        }
        cout << res << endl;
    }
  return 0;
}