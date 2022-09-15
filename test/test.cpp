#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    multiset <int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);

    for (auto i: ms){
        cout << i << " ";
    }
    cout << endl;

    ms.erase(ms.find(2));
    
    
    for (auto i: ms){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}