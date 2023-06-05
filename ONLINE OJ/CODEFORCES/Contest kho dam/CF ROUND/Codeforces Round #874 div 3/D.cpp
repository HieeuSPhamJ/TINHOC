#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
vector <int> s[2];

void cal1(int n, int f){
    for (int i = f; i <= n; i++){
        s[0].push_back(a[i]);
    }

    n = f - 1;
    s[0].push_back(a[n]);
    f = 1;
    for (int i = n - 1; i >= 1; i--){
        s[0].push_back(a[i]);
        if (a[i] < a[1]){
            f = i;
            s[0].pop_back();
            break;
        }
    }
    for (int i = 1; i <= f; i++){
        s[0].push_back(a[i]);
    }
}

void cal2(int n){
    s[1].push_back(a[n]);
    n--;
    int f = 1;
    for (int i = n; i >= 1; i--){
        s[1].push_back(a[i]);
        if (a[i] < a[1]){
            f = i;
            s[1].pop_back();
            break;
        }
    }

    for (int i = 1; i <= f; i++){
        s[1].push_back(a[i]);
    }
}

signed main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int f = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if (i >= 2 and a[i] > a[f]){
                f = i;
            }
        }

        if (n == 1){
            cout << a[1] << endl;
            continue;
        }
        s[0].clear();
        s[1].clear();

        cal1(n,f);
        cal2(n);

        s[0].resize(n);
        s[1].resize(n);
        
        for (int i = 0; i < n; i++){
            if (s[0][i] < s[1][i]){
                for (auto i : s[1]){
                    cout << i << ' ';
                }
                goto bru;
            }
            else if (s[0][i] > s[1][i]){
                for (auto i : s[0]){
                    cout << i << ' ';
                }
                goto bru;
            }
        }
        for (auto i : s[1]){
            cout << i << ' ';
        }
        bru:;
        cout << endl;

    }
    return 0;
}

/*
4 3 2 1

3 2 1 4



*/