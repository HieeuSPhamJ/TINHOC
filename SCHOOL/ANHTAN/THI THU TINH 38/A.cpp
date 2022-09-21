#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

void print(multiset <int,greater<int>> mySet){
    for (auto i: mySet){
        cout << i << " ";
    }
    cout << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    multiset <int,greater<int>> mySet;

    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        mySet.insert(inp);
    }

    // print(mySet);

    int ans = 0;
    
    while(!mySet.empty()){
        auto id = mySet.begin();
        int val = *id;
        ans += val;
        mySet.erase(id);
        // print(mySet);
        while(true){
            auto newId = mySet.lower_bound(val - k);
            if (newId == mySet.end()){
                break;
            }
            else{
                val = *newId;
                mySet.erase(newId);
            }
        }
    }

    cout << ans;

    return 0;
}