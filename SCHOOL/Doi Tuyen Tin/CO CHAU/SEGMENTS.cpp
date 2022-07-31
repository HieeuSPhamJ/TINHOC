#include<bits/stdc++.h>
#define ii pair <int,int>
#define x first
#define y second
#define int long long
using namespace std;

vector <ii> lists;

signed main(){
    freopen("SEGMENTS.INP", "r", stdin);
    freopen("SEGMENTS.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        lists.push_back({min(a,b), max(a, b)});
    }

    sort(lists.begin(), lists.end());

    int temp = lists[0].y;
    int ans = 1;
    for (int i = 1; i < n; i++){
        if (lists[i].x <= temp){
            temp = min(temp, lists[i].y);
        }
        else{
            ans++;
            temp = lists[i].y;
        }
    }

    cout << ans;

    return 0;
}