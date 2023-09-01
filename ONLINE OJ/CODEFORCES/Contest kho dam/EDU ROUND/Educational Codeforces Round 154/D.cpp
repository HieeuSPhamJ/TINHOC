#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3e5 + 10;

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        if (n == 1){
            cout << 0 << endl;
            continue;
        }
        deque <ii> ls;
        int la = 1;
        if (a[1] == a[2]){
            la = 2;
            ls.push_back({1,1});
        }
        for (int i = 2; i < n; i++){
            if (a[i] * a[i + 1] < 0){
                ls.push_back({la,i});
                la = i + 1;
            }
            else if (a[i] == a[i + 1]){
                ls.push_back({la,i});
                la = i + 1;
            }
            else if (la != i and (a[i] - a[i - 1]) * (a[i + 1] - a[i]) < 0){
                ls.push_back({la,i});
                la = i + 1;
            }
        }
        ls.push_back({la,n});
        int res = 0;
        la = -1;
        if (a[ls.front().fi] < a[ls.front().se]){
            
            ls.pop_front();
        }
        for (auto i: ls){
            cout << i.fi << " " << i.se << endl;
            if (i.se - i.fi == 0){
                res++;
                continue;
            }
            if (la == -1 and a[i.fi] < a[i.se] and a[i.fi] > 0){
                la = 1;
                continue;
            }
            if (la == -1 and a[i.fi] < a[i.se] and a[i.fi] < 0){
                continue;
            }
            if (la == -1 and a[i.fi] > a[i.se] and a[i.fi] > 0){
                res++;
                continue;
            }
            if (la == -1 and a[i.fi] > a[i.se] and a[i.fi] < 0){
                res++;
                la = 1;
                continue;
            }

            if (a[i.fi] < a[i.se] and a[i.fi] > 0){
                res++;
                continue;
            }
            if (a[i.fi] < a[i.se] and a[i.fi] < 0){
                res += (i.se - i.fi + 1);
                continue;
            }
            if (a[i.fi] > a[i.se] and a[i.fi] > 0){
                res += (i.se - i.fi + 1);
                continue;
            }
            if (a[i.fi] > a[i.se] and a[i.fi] < 0){
                res++;
                continue;
            }
            
        }

        cout << res << endl;
    }   
    return 0;
}