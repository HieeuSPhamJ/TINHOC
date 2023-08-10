#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

int ask(int i){
    cout << "? " << 1 << " " << i << endl;
    cout << flush;
    int inp;
    cin >> inp;
    return inp;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    int left = 3;
    int right = 1e18;
    int ans = 0;
    int count = 0;
    while(left <= right){
        count++;
        int mid = left + (right - left) / 3;
        if (count % 2){
            mid = (right + left) / 2;
        }
        int t = ask(mid);
        if (t == -1){
            right = mid - 1;
        }
        else{
            ans = mid;
            left = mid + 1;
        }
    }
    cout << "! " << ans;
    return 0;
}