#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("TONGCHUSO.INP", "r", stdin);
    freopen("TONGCHUSO.OUT", "w", stdout);
    string n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n.size(); i++){
        ans += n[i] - '0';
    }
    cout << ans;
    return 0;
}