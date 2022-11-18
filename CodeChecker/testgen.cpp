#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int random(int left, int right){
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
    cout << 1 << endl;
    cout << random(1,10) << " " << random(1,10) << " " << random(1,10);


    return 0;
}