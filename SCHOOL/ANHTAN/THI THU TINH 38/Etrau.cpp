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
    int n, test;
    cin >> n >> test;

    multiset <int> mySet;

    for (int i = 1; i <= n; i++){
        mySet.insert(i);
    }
    while(test--){
        int i;
        cin >> i;
        if (mySet.size() < i){
            cout << 0 << endl;
        }
        else{
            auto id = mySet.begin(); 
            i--;
            while(i--){
                id++;
            }

            cout << *id << endl;
            mySet.erase(id);
        }
    }
    return 0;
}
