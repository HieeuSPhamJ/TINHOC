#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define int long long
#define s second
using namespace std;

const int maxN = 1e7 + 10;

int cal(int n){
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    int numLe = n / 2 + (n % 2);
    int lastLe = n - (n%2 == 0);

    int sum = ((1 + lastLe) * numLe )/ 2;
    return sum + cal(n / 2);
    
}

signed main(){
    freopen("odddiv.inp", "r", stdin);
    freopen("odddiv.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    cout << cal(b) - cal(a - 1);

    return 0;
}