#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

signed main(){
    freopen("ANIMALS.INP", "r", stdin);
    freopen("ANIMALS.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    
    vector <int> lists;

    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        lists.push_back(inp * (n - i + 1));
    }
    sort(lists.begin(), lists.end());

    int sum = 0;
    int count = 0;
    for (auto i: lists){
        if (sum + i <= m){
            sum += i;
            count++;
        }
    }
    cout << count;
    return 0;
}