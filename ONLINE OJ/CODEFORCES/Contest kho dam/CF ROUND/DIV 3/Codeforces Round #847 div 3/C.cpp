#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 110;

vector <int> a[maxN];
int final[maxN];

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
            for (int j = 0; j < n - 1; j++){
                int x;
                cin >> x;
                a[i].push_back(x);
            }
        }
        for (int t = 1; t <= n; t++){
            unordered_set <int> s;
            int ans = 0;
            for (int i = 1; i <= n; i++){
                if(a[i].size() and s.find(a[i].back()) != s.end())
                {
                    ans = a[i].back();
                    break;
                }
                s.insert(a[i].back());
            }
            for (int i = 1; i <= n; i++){
                if(a[i].size() and a[i].back() == ans){
                    a[i].pop_back();
                }
            }
            final[t] = ans;
        }
        for (int i = n; i >= 1; i--){
            cout << final[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
4 2 1
4 2 3
2 1 3
4 1 3
*/