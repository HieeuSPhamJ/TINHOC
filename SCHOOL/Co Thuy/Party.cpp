#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define st 0
#define bw 1
#define fw 2
using namespace std;

const int maxN = 2 * 1e5 + 10;

int n;
int n0;
int a[maxN];

void solvemi(){
    vector <int> lists;
    for (int i = 1; i <= n; i++){
        lists.push_back(a[i]); 
    }
    int ans = 0;
    while(!lists.empty()){
        ans++;
        int t = lists.back();
        while(!lists.empty() and abs(t - lists.back()) <= 2){
            lists.pop_back();
        }
    }
    cout << ans << " ";
}

int check[maxN];

void solvema(){
    n = n0;
    // cout << endl;
    for (int i = 1; i <= n; i++){
        // cout << a[i] << " ";
        if (check[a[i] - 1] == 0){
            // cout << check[a[i] - 1] << " " << a[i] - 1 << endl;
            check[a[i] - 1] = 1;
        }
        else if (check[a[i]] == 0){
            // cout << check[a[i]] << " " << a[i] << endl;
            check[a[i]] = 1;
        }
        else{
            // cout << check[a[i] + 1] << " " << a[i] + 1 << endl;
            check[a[i] + 1] = 1;
        }
        // for (int i = 0; i <= n + 1; i++){
        //     cout << check[i] << " ";
        // }
        // cout << endl;
    }
    // cout << endl;
    int ans = 0;
    for (int i = 0; i <= n + 1; i++){
        ans += check[i];
    }
    cout << ans << endl;
}

signed main(){
    freopen("Party.INP", "r", stdin);
    freopen("Party.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    n0 = n;

    sort(a + 1, a + 1 + n);

    solvemi();
    solvema();

    return 0;
}

/*
1 1 4 4 4 4 8 8 8
0 1 3 4 5 5 7 8 9
*/