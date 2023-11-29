#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

map <ii, int> countPoint[10];
set <ii> listPair;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << countPoint[3][{1,3}];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        int count = 0;
        int x = a;
        int y = b;
        cout << "Point: " << a << " " << b << endl;
        if (a != 0 or b != 0){
            while(1){
                if (a > 0 and b >= 0){
                    break;
                }
                count++;
                int a0 = a, b0 = b;
                a = b0;
                b = -a0;
                cout << a << " " << b << endl; 
            }
            x = a;
            y = b;
            int gcd = __gcd(a,b);
            x /= gcd;
            y /= gcd;
        }
        countPoint[count][make_pair(x,y)]++;
        listPair.insert({x,y});
    }
    int ans = 0;
    for (auto i: listPair){
        ans += countPoint[0][i] * countPoint[1][i];
        ans += countPoint[1][i] * countPoint[2][i];
        ans += countPoint[2][i] * countPoint[3][i];
        ans += countPoint[3][i] * countPoint[0][i];
    }
    cout << ans;
    return 0;
}