#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

int check[10000];
int a[10000];

int checkSQ(int n){
    int sq = sqrt(n);
    if (sq * sq == n){
        return 1;
    }
    return 0;
}

void backtracking(int id,int n){
    if (id == n + 1){
        // for (int i = 0; i <= n; i++){
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        int x = 1;
        for (int i = 0; i <= n; i++){
            if (checkSQ(i + a[i]) == 0){
                x = 0;
            }
        }
        if (x){
            for (int i = 0; i <= n; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }

    }
    for (int i = 0; i <= n; i++){
        if (check[i] == 0){
            a[id] = i;
            check[i] = 1;
            backtracking(id + 1, n);
            check[i] = 0;
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n = test;
        cout << "===" << n + 1 << "===" << endl;
        backtracking(0,n);
        
    }
    return 0;
}