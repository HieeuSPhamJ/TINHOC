#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 3 * 1e5 + 10;

int n, m;
pair <ii,int> a[maxN];
int ans[maxN];

void Try(deque <pair<ii,int>> &lists){
    
    while(lists.size() >= 2 and lists.front().fi.se == -1 and lists[1].fi.se == -1){
        int time = abs(lists[0].fi.fi - lists[1].fi.fi) / 2;
        time += lists[0].fi.fi;
        ans[lists[0].se] = ans[lists[1].se] = time;
        lists.pop_front();
        lists.pop_front();
    }

    for (auto i: lists){
        cout << i.fi.fi << " ";
    }
    cout << endl;

    reverse(lists.begin(), lists.end());

    while(lists.size() >= 2 and lists.front().fi.se == 1 and lists[1].fi.se == 1){
        int time = abs(lists[0].fi.fi - lists[1].fi.fi) / 2;
        time += m - lists[0].fi.fi;
        ans[lists[0].se] = ans[lists[1].se] = time;
        lists.pop_front();
        lists.pop_front();
    }

    reverse(lists.begin(), lists.end());

    if (lists.size() == 2 and lists[0].fi.se == -1 and lists[1].fi.se == -1){
        int x1 = lists[0].fi.fi;
        int x2 = lists[1].fi.fi;
        int time = x1 + (m - x2) + m;
        time / 2;
        ans[lists[0].se] = ans[lists[1].se] = time;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            cin >> a[i].fi.fi;
            ans[i] = -1;
        }
        for (int i = 1; i <= n; i++){
            char x;
            cin >> x;
            if (x == 'R'){
                a[i].fi.se = 1;
            }    
            else{
                a[i].fi.se = -1;
            }
            a[i].se = i;
        }
        sort(a + 1, a + 1 + n);

        deque <pair <ii,int>> lists[2];

        for (int i = 1; i <= n; i++){
            int t = a[i].fi.fi % 2;
            int ok = 1;
            // cout << "With: " << a[i].se << endl;
            if (a[i].fi.se == -1 and lists[t].size()){
                if (lists[t].back().fi.se == 1){
                    // cout << lists[t].back().se << endl;
                    int time = abs(lists[t].back().fi.fi - a[i].fi.fi);
                    ans[i] = time / 2;
                    ans[lists[t].back().se] = time / 2;
                    lists[t].pop_back();
                    ok = 0;
                }
            }
            if (ok){
                lists[t].push_back(a[i]);
            }
        }

        for (int t = 0; t <= 1; t++){
            Try(lists[t]);
        }


        for (int i = 1; i <= n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}