#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int maxN = 1e5 + 10;

double a[maxN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    double sum = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + 1 + n);
    double ans = a[1];
    for (int i = 2; i <= n; i++){
        ans = double(ans + a[i]) / 2;
    }
    cout << fixed << setprecision(5) << n * ans - sum;
 

    return 0;
}