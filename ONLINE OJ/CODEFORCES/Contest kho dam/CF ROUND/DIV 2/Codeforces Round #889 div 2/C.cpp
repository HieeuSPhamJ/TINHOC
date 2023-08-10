#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int a[202];
vector <ii> ls;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        ls.clear();
        int n;
        cin >> n;
        int cnt = 0;
        int mn = 0;
        int mp = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if (a[i] <= 0){
                cnt++;
                // cout << a[i] << endl;
                if (-a[mn] < -a[i]){
                    mn = i;
                }
            }
            else{
                if (a[mp] < a[i]){
                    mp = i;
                }
            }
            
        }
        // cout << mn << " " << mp << endl;
        if (cnt >= n / 2 + n % 2){
            // cout << "NEG" << endl;
            while(abs(a[mn]) <= abs(a[mp]) and a[mn] != 0){
                a[mn] *= 2;
                ls.push_back({mn,mn});
            }
            for (int i = 1; i <= n; i++){
                if (a[i] > 0){    
                    a[i] += a[mn];
                    ls.push_back({i,mn});
                }
            }
            for (int i = n - 1; i >= 1; i--){
                while (a[i] > a[i + 1]){
                    ls.push_back({i, i + 1});
                    a[i] += a[i + 1];
                }
            }
        }
        else{
            while(abs(a[mp]) <= abs(a[mn]) and a[mp] != 0){
                a[mp] *= 2;
                ls.push_back({mp,mp});
            }  

            for (int i = 1; i <= n; i++){
                if (a[i] < 0){
                    a[i] += a[mp];
                    ls.push_back({i,mp});
                }
            }
 
            for (int i = 2; i <= n; i++){
                if (a[i - 1] > a[i]){
                    ls.push_back({i, i - 1});
                    a[i] += a[i - 1];
                }
            }
        }

        cout << ls.size() << endl;
 
        for (auto i: ls){
            cout << i.fi << " " << i.se << endl;
        }
        

    }
    return 0;
}

/*
7 3 9 -5 -15 14 9 -6 -12 -2 6 -11 7 -3 -19 -5 -7 -7 -16 -2

With: 2 3
2 1
With: 3 9
3 2
With: 4 -5
4 3
4 3
With: 5 -15
5 4
5 4
With: 6 14
6 5
With: 7 9
7 6
With: 8 -6
8 7
8 7
With: 9 -12
9 8
9 8
With: 10 -2
10 9
10 9
With: 11 6
11 10
With: 12 -11
12 11
12 11
With: 13 7
13 12
With: 14 -3
14 13
14 13
With: 15 -19
15 14
15 14
With: 16 -5
16 15
16 15
With: 17 -7
17 16
17 16
With: 18 -7
18 17
18 17
With: 19 -16
19 18
19 18
With: 20 -2
20 19
20 19
32
*/