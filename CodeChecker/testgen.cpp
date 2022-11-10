#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int random(int left = 0, int right = 1e8){
    if (left == right){
        return left;
    }
    return (rd() % (right - left + 1)) + left;
}


signed main(){
    srand(time(0));
    freopen("input.inp", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = random(1,5);
    int cap = random(1, n / 2);
    int m = random(2, 10);
    cout << n << " " << cap << " " << m << endl;
    for (int i = 1; i <= n; i++){
        int b = random(2, m);
        int a = random(1, b - 1);
        cout << a << " " << b << endl;
    }
    
    return 0;
}