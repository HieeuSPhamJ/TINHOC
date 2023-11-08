#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
#define all(s) s.begin(), s.end()
using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



int random(int left, int right){
    if (left >= right){
        return left;
    }
    return (rng() % (right - left + 1)) + left;
}

int rt[100000];

int find(int nu){
    if (nu == rt[nu]){
        return nu;
    }
    return rt[nu] = find(rt[nu]);
}

void randomTree(int n){
    for (int i = 1; i <= n; i++){
        rt[i] = i;
    }
    int com = n;
    while(com > 1){
        int u = random(1,n);
        int v = random(1,n);
        if (find(u) == find(v)){
            continue;
        }
        com--;
        rt[find(u)] = find(v);
        cout << u << " " << v << endl;
    }
}

string randomStr(const int len) {
    static const char alphanum[] =
        "abcde";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}
vector <int> adj[1000];

signed main(){
    srand(time(0));
    freopen("input.inp", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 2000;
    cout << n << " " << random(1, 1e18) << endl;
    for (int i = 1; i <= n; i++){
        cout << random(1,2000) << " ";
    }
    return 0;
}