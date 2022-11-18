#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct side{
    int t1, t2, t3;
};

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    side a, b;
    cin >> a.t1 >> a.t2 >> a.t3 >> b.t1 >> b.t2 >> b.t3;
    if (a.t3 > b.t3){
        swap(a,b);
    }
    int add = min(abs(a.t3 - b.t3), min(a.t1, a.t2));
    a.t3 += add;
    a.t1 -= add;
    a.t2 -= add;
    add = min(abs(a.t3 - b.t3), a.t1 / 3);
    a.t3 += add;
    a.t1 -= 3 * add;
    
    if (a.t2 > b.t2){
        swap(a,b);
    }
    add = min(abs(a.t2 - b.t2), a.t1 / 2);
    a.t2 += add;
    a.t1 -= 2 * add;
    // cout << a.t1 << " " << a.t2 << " " << a.t3 << " " << b.t1 << " " << b.t2 << " " << b.t3 << endl;
    if (a.t1 != b.t1 or a.t2 != b.t2 or a.t3 != a.t3){
        // cout << "darkdark bu bu lmao" << endl;


        // return 0;
    }
    cout << 9 * a.t3 + 4 * a.t2 + 1 * a.t1;
    return 0;
}