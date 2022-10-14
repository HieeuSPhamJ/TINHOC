#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define num first
#define val second
#define int long long
using namespace std;

vector <ii> lists;

bool cmp(ii a, ii b){
    return a.val < b.val;
}

signed main(){
    freopen("BURGLAR.INP", "r", stdin);
    freopen("BURGLAR.OUT", "w", stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        lists.push_back({a, b});
    }

    sort(lists.begin(), lists.end(), cmp);

    int sum = 0;
    int numBox = 0;    
    while(numBox + lists.back().num <= m and !lists.empty()){
        sum += lists.back().val * lists.back().num;
        numBox += lists.back().num;
        lists.pop_back();
    }

    // cout << numBox << endl;

    // cout << lists.back().val << ' ' << lists.back().num << endl;
    // cout << sum << endl;

    if (!lists.empty()){
        sum += (lists.back().val * (m - numBox));
    }
    cout << sum;

    return 0;
}