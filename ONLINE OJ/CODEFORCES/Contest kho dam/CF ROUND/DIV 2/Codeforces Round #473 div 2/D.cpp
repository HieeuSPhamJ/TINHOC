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
set <int> ls;
bool notprime[int(1e7 + 10)];

void init(){
    for (int i = 2; i * i < 1e7 + 10; i++){
        if (notprime[i] == 0){
            for (int j = i * i; j < 1e7 + 10; j += i){
                notprime[j] = 1;
            }
        }
    }
    for (int i = 2; i < maxN; i++){
        if (notprime[i] == 0){
            ls.insert(i);
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x;
        if (notprime[x] == 0){

        }
    }





    return 0;
}