#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

vector <int> lists[maxN];
int a[maxN];
int visited[maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n + 1; i++){
            lists[i].clear();
            visited[i] = 0;
        }
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if (lists[a[i]].size() > 1){
                lists[a[i]].pop_back();
            }
            lists[a[i]].push_back(i);
        }
        queue <ii> q;
        for (auto i: lists[1]){
            q.push({0,i});
        }

        int ans = 0;

        while(!q.empty()){
            ii t = q.front();
            q.pop();
            ans = max(ans,visited[t.se]);
            if (t.fi != visited[t.se]){
                continue;
            }
            for (auto i: lists[a[t.se] + 1]){
                if (visited[i] < t.fi + abs(t.se - i)){
                    visited[i] = t.fi + abs(t.se - i);
                    q.push({visited[i], i});
                }
            }
            // if (!lists[a[t.se] + 1].empty()){
            //     int i = lists[a[t.se] + 1].front();
            //     if (visited[i] < t.fi + abs(t.se - i)){
            //         visited[i] = t.fi + abs(t.se - i);
            //         q.push({visited[i], i});
            //     }
            //     i = lists[a[t.se] + 1].back();
            //     if (visited[i] < t.fi + abs(t.se - i)){
            //         visited[i] = t.fi + abs(t.se - i);
            //         q.push({visited[i], i});
            //     }
            // }
        }
        cout << ans << endl;

    }
    return 0;
}

/*


*/