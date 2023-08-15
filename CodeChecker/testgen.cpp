#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



int random(int left, int right){
    if (left >= right){
        return left;
    }
    return (rng() % (right - left + 1)) + left;
}

void randomTree(int n){
    for (int i = 2; i <= n; i++){
        cout << random(1,i - 1) << " " << i << endl;
    }
}

string randomStr(const int len) {
    static const char alphanum[] =
        "-101";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}


signed main(){
    srand(time(0));
    freopen("input.inp", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 100;
    // int m = random(n - 1, 1.5 * n);
    int m = random(n - 1, n * (n - 1) / 2);
    set <ii> s;
    for (int i = 2; i <= n; i++){
        int a = random(1,i - 1);
        int b = i;
        // cout << a << " " << b << endl;
        s.insert({a,b});
    }
    for (int i = n; i <= m; i++){
        int a = random(1,n - 1);
        int b = random(a,n);
        s.insert({min(a,b), max(a,b)});
    }
    m = s.size();
    cout << n << " " << m << endl;
    for (auto i: s){
        cout << i.fi << " " << i.se << " " << random(1,1000) << endl;
    }

    int test = random(1,n);

    cout << test << endl;

    for (int i = 1; i <= test; i++){
        int a = random(1,n - 1);
        int b = random(a,n);
        cout << a << " " << b << endl;
    }

    return 0;
}