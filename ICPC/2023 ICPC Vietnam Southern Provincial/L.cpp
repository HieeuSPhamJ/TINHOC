#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int m, n, a, b, k;

int sum2(int n)
{
    return n * (n + 1) / 2;
}

int sum1(int n)
{
    return sum2(n + 1) - 2 * sum2((n + 1) / 2);
}

int check(int len)
{
    int area = 2 * sum1(2 * len - 1) + 2 * len + 1;
    if (1 > a - len){
        area -= sum1(2 * len + 1 - 2 * a);
    }
    if (m < a + len){
        area -= sum1(2 * len + 1 - 2 * (m - a + 1));
    }
    if (1 > b - len){
        area -= sum1(2 * len + 1 - 2 * b);
    }
    if (n < b + len){
        area -= sum1(2 * len + 1 - 2 * (n - b + 1));
    }
    if (len - a >= b){
        area += sum2(len - (a + b) + 1);
    }
    if (len + b >= a + n + 1){
        area += sum2(len - (a + n - b + 1) + 1);
    }
    if (len + a>= m + 1 + b){
        area += sum2(len - (m - a + 1 + b) + 1);
    }
    if (len + a + b >= m + n + 2){
        area += sum2(len - (m - a + 1 + n - b + 1) + 1);
    }
    return area;
}

signed main(){
    // freopen("input.INP", "r", stdin);
    // freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> a >> b >> k;

    int l = 0, r = m + n;
    while (l + 1 < r){
        int mid = (l + r) / 2;
        if (m * n - check(mid) < k)
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;

    return 0;
}