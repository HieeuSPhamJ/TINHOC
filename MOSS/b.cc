#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

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

        int f = max_element(a + 2, a + 1 + n) - a;

        vector <int> s;

        for (int i = f; i <= n; i++){
            s.push_back(a[i]);
        }

        int nn = n;

        n = f - 1;
        f = 1;
        s.push_back(a[n]);
        n--;
        for (int i = n; i >= 1; i--){
            if (a[i] < a[1]){
                f = i;
                break;
            }
            s.push_back(a[i]);
        }

        for (int i = 1; i <= f; i++){
            s.push_back(a[i]);
        }
        
        n = nn;

        vector <int> ss;

        ss.push_back(a[n]);
        n--;
        f = 1;
        for (int i = n; i >= 1; i--){
            if (a[i] < a[1]){
                f = i;
                break;
            }
            ss.push_back(a[i]);
        }

        for (int i = 1; i <= f; i++){
            ss.push_back(a[i]);
        }
        
        int ok = 0;
        for (int i = 0; i < n; i++){
            if (s[i] < ss[i]){
                ok = 1;
                break;
            }
            else if (s[i] > ss[i]){
                ok = 0;
                break;
            }
        }
        if (ok == 0){
            int cnt = 0;
            for (auto i: s){
                cnt++;
                if (cnt > nn){
                    break;
                }
                cout << i << " ";
            }
            cout << endl;
        }
        else{
            int cnt = 0;
            for (auto i: ss){
                cnt++;
                if (cnt > nn){
                    break;
                }
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

/*
4 3 2 1

3 2 1 4



*/