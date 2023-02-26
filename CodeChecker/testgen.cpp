#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int random(int left, int right){
    if (left >= right){
        return left;
    }
    return (rd() % (right - left + 1)) + left;
}

void randomTree(int n){
    for (int i = 2; i <= n; i++){
        cout << random(1,i - 1) << " " << i << endl;
    }
}

string randomStr(const int len) {
    static const char alphanum[] =
        "01";
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
    int n = 5;
    int m = random(0,n / 2);
    int k = random(1,n);

    set <ii> lists;
    for (int i = 2; i <= n; i++){
        lists.insert({random(1, i - 1), i});
    }

    for (int i = 1; i <= m; i++){
        int a = random(1,n - 1);
        int b = random(a + 1, n);
        lists.insert({a,b});
    }
    cout << n << " " << lists.size() << " " << k << endl;

    for (auto i: lists){
        cout << i.fi << " " << i.se << " " << random(1,20) << endl;
    }
    for (int i = 1; i <= k; i++){
        cout << i << " ";
    }
    return 0;
}