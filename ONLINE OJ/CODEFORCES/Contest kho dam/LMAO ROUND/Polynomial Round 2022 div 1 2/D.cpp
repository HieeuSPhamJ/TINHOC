#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define iii pair <ii,int>
using namespace std;


vector <int> val;
vector <vector <int>> a;
vector <deque <int>> lists;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n, m, k;
        cin >> n >> m;
        a.clear();
        val.clear();
        lists.clear();
        k = 0;
        a.resize(n + 3);
        val.resize(n + 3);
        lists.resize(m + 3);
        for (int i = 1; i <= n; ++ i){
            a[i].resize(m + 3);
            for (int j = 1; j <= m; ++ j){
                cin >> a[i][j];
                if (a[i][j]){
                    ++ k;
                    ++ val[i];
                }
            }
        }
        if (k % n != 0){
            cout << -1 << endl;
            continue;
        }
        for (int j = 1; j <= m; ++ j){
            for (int i = 1; i <= n; ++ i){
                if (val[i] > k / n and a[i][j] == 1){
                    lists[j].push_back(i);
                }
            }
        }
        
        vector <iii> ans;
        for (int i = 1; i <= n; ++ i){
            if (val[i] < k / n){
                for (int j = 1; j <= m and val[i] < k / n; ++ j){
                    if (a[i][j] == 1) continue;
                    while (lists[j].empty() == 0 and (val[lists[j].front()] == k / n or a[lists[j].front()][j] == 0)){
                        lists[j].pop_front();
                    }
                    if (!lists[j].empty()){
                        ans.push_back(iii(ii(i, lists[j].front()), j));
                        swap(a[lists[j].front()][j], a[i][j]);
                        val[lists[j].front()]--;
                        val[i]++;
                    }
                }
            }
        }
        cout << ans.size() << endl;
        for (auto x : ans)
        {
            cout << x.fi.fi << ' ' << x.fi.se << ' ' << x.se << endl;
        }
    }
    return 0;
}