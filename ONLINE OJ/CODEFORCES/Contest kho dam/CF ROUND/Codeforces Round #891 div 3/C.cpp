#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e6 + 10;

int a[maxN];
int b[maxN];


bool cmp(int a, int b){
    return a > b;
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
        int m = n * (n - 1) / 2;
        for (int i = 1; i <= m; i++){
            cin >> b[i];
        }
        sort(b + 1 , b + 1 + m, cmp);
        a[1] = 1e9;
        for(int i = 2, sum = 1; i <= n; i++){
            a[i] = b[sum];
            sum += i;
        }
        for (int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}



