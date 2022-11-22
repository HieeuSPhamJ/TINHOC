#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];

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
        }
        int left = 1;
        while(a[left] >= a[left + 1] and left <= n){
            left++;
        }
        left = min(left, n);
        int right = n;
        while(a[right] >= a[right - 1] and right >= 1){
            right--;
        }
        if (right == 0){
            right++;
        }
        // cout << left << " " << right << endl;
        if (left == right){
            cout << "YES" << endl;
            continue;
        }
        if (left > right and a[left] == a[right]){
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;

    }
    return 0;
}