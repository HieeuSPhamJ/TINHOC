#include<bits/stdc++.h>
using namespace std;

const int maxN =1e7 + 10;

long long a[maxN];
// priority_queue <int, vector <int>, greater <int> > myHeap;

int main(){
    long long n, m, k, x, q;
    cin >> n >> m >> k >> x >> q;
    a[1] = x;
    for (int i = 2; i <= n; i++){
        a[i] = (a[i - 1] * k) % m;
    }
    for (int i = 1; i <= n; i++){
        a[i] = a[i] - q;
        // cout << a[i] << ' ';
        // myHeap.push(a[i]);
    }

    int test;
    cin >> test;
    while (test--){
        long long l, d, r;
        cin >> l >> r >> d;
        long long ans = -1e18;
        for (int i = 1; i <= n; i++){
            long long tempA = a[i];
            if (i >= l and i <= r){
                tempA -= d;
            }
            ans = max(ans, tempA);
            // cout << a[i] - d << ' ';
        }
        cout << ans;

        cout << endl;
    }
    return 0;
}