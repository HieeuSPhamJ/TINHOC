#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;

int n;
int a[maxN];
int used[maxN];

void reset(){
    for (int i = 0; i <= n + 5; i++){
        used[i] = 0;
    }
}

bool test(int d1){
    // cout << "Test: " << d1 << endl;
    reset();
    used[1] = 1;
    for (int i = 2, last = 1; i <= n; i++){
        if ((a[i] - a[last]) == d1){
            used[i] = 1;
            last = i;
        }
    }
    // for (int i = 1; i <= n; i++){
    //     cout << used[i] << " ";
    // }
    // cout << endl;
    int last;
    int d2 = 0;
    for (int i = 1; i <= n; i++){
        if (used[i] == 0){
            last = i;
            used[i] = 2;
            for (int j = i + 1; j <= n; j++){
                if (used[j] == 0){
                    d2 = abs(a[j] - a[i]);
                    // cout << "in" << j <
                    used[j] = 2;
                    last = j;
                    break;
                }
            }
            break;
        }
    }

    // cout << "D2: " << d2 << endl;
    // for (int i = 1; i <= n; i++){
    //     cout << used[i] << " ";
    // }
    // cout << endl;
    for (int i = last + 1; i <= n; i++){
        if (used[i] == 0){
            if (a[i] - a[last] == d2){
                used[i] = 2;
            }
        }
    }
    
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 1; i <= n; i++){
        if (used[i] == 0){
            return 0;
        }
        cnt1 += (used[i] == 1);
        cnt2 += (used[i] == 2);
    }
    if (cnt1 == n){
        cnt1--;
        cnt2++;
        used[n] = 2;
    }
    if (cnt2 == n){
        cnt2--;
        cnt1++;
        used[n] = 1;
    }
    
    cout << cnt1 << endl;
    for (int i = 1; i <= n; i++){
        if (used[i] == 1){
            cout << a[i] << " ";
        }
    }
    cout << endl;
    cout << cnt2 << endl;
    for (int i = 1; i <= n; i++){
        if (used[i] == 2){
            cout << a[i] << " ";
        }
    }
    cout << endl;
    return 1;
}

signed main(){

    // freopen("input.inp", "r", stdin);
    // freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    sort(a + 1, a + 1 + n);

    // for (int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    int d1 = abs(a[1] - a[2]);
    int d2 = abs(a[1] - a[3]);
    int d3 = abs(a[2] - a[3]);

    // cout << d1 << " " << d2 << " " << d3 << endl;
    
    if (test(d1)){
        // cout << "Case 1";
        return 0;
    }
    if (test(d2)){
        // cout << "Case 2";
        return 0;
    }
    if (test(d3)){
        // cout << "Case 3";
        return 0;
    }
    cout << -1;
    return 0;
}

/*
7
1 2 3 4 2 6 8
*/