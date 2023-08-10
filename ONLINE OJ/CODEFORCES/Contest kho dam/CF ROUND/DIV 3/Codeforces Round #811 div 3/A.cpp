#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

bool cmp(ii a, ii b){
    if (a.fi == b.fi){
        return a.se < b.se;
    }
    return a.fi < b.fi;
}

void printAns(ii a, ii b){
    if (a.se >= b.se){
        cout << a.fi - b.fi << " " << a.se - b.se;
    }
    else{
        cout << a.fi - b.fi - 1 << " " << (a.se - b.se + 60) % 60;
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, x, y;
        cin >> n >> x >> y;
        vector <ii> lists;
        ii time = {x,y};
        for (int i = 1;i <= n; i++){
            int h, m;
            cin >> h >> m;
            lists.push_back({h,m});
            lists.push_back({h + 24,m});
        }

        sort(lists.begin(), lists.end(), cmp);

        ii ans = {0,0};

        for (auto i: lists){
            if (i == time){
                ans = i;
                break;
            }
            // cout << i.fi << ' ' << i.se << " " << cmp(time, i) << endl; 
            if (cmp(time, i)){
                ans = i;
                break;
            }
        }

        // cout << ans.fi << " " << ans.se <<  " - ";

        printAns(ans, time);
 
    }
    return 0;
}