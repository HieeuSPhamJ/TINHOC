#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, a, b;
        cin >> n >> a >> b;
        int check[n + 10] = {0};
        check[a] = 1;
        check[b] = 1;
        vector <int> listMin;
        vector <int> listMax;

        listMin.push_back(a);
        listMax.push_back(b);

        for (int i = 1; i <= n and listMax.size() < n / 2; i++){
            if (check[i] == 0 and i < b){
                listMax.push_back(i);
            }
        }
        for (int i = n; i >= 1 and listMin.size() < n / 2; i--){
            if (check[i] == 0 and i > a){
                listMin.push_back(i);
            }
        }

        if (listMin.size() != n / 2 or listMax.size() != n / 2){
            cout << -1 << endl;
            continue;
        }

        for (auto i: listMin){
            cout << i << ' ';
        }
        for (auto i: listMax){
            cout << i << ' ';
        }
        // cout << "-";
        cout << endl;
    }
    return 0;
}