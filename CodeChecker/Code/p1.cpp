#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

map <int, int> beginEle;
map <int, int> endEle;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.inp", "r", stdin);
    freopen("out1.txt", "w", stdout);
    int test;
    cin >> test;
    while(test--){
        beginEle.clear();
        endEle.clear();
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;

            if (beginEle[inp] == 0){
                beginEle[inp] = i;
            }
            endEle[inp] = i;
        }

        for (int i = 1; i <= m; i++){
            int a, b;
            cin >> a >> b;
            int l = beginEle[a];
            int r = endEle[b];
            // cout << a << ' ' << b << ' ';
            // cout << l << ' ' << r << endl;
            if (l * r <= 0){
                cout << "NO";
            }
            else if (l < r){
                cout << "YES";
            }
            else{
                cout << "NO";
            }
            cout << endl;
        }
        // cout << endl;
    }
    return 0;
}