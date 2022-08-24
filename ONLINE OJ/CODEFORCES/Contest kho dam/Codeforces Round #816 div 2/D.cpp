#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

struct iii{
    int i, j, x;
};

bool cmp(iii x, iii y){
    if (x.i == y.i){
        return x.j < y.j;
    }
    return x.i < y.i;
}

const int maxN = 2 * 1e5 + 10;

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        a[i] = -1;
    }
    int test;
    cin >> test;
    vector <iii> Q;
    while(test--){
        int i, j, x;
        cin >> i >> j >> x;
        if (i > j){
            swap(i,j);
        }
        if (i == j){
            a[i] = x;
        }
        else{
            Q.push_back({i,j,x});
        }
    }
    sort(Q.begin(), Q.end(), cmp);

    for (auto q: Q){
        if (a[q.i] == -1 and a[q.j] == -1){
            a[q.i] = 0;
            a[q.j] = a[q.i] xor q.x;
        }
        else if (a[q.i] == -1){
            a[q.i] = a[q.j] xor q.x;
        }
        else if (a[q.j] == -1){
            a[q.j] = a[q.i] xor q.x;
        }
    }

    for (int i = 1; i <= n; i++){
        if (a[i] == -1){
            cout << 0 << ' ';
        }
        else{
            cout << a[i] << ' ';
        }
    }

    return 0;
}