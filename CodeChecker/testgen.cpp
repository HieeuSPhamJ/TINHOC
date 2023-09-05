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

vector <int> adj[1000];

signed main(){
    srand(time(0));
    freopen("input.inp", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
<<<<<<< HEAD
    int n = 5;
    int m = random(1,10);
    set <ii> s;
    for (int i = 2; i <= n; i++){
        s.insert({random(1,i-1), i});
    }

    for (int i = 1; i <= m; i++){
        int a = random(1,n - 1);
        int b = random(a,n);
        adj[a].push_back(b);
        adj[b].push_back(a);
        s.insert({a,b});
    }
    int k = random(1,n);
    vector <int> ls;
    ls.push_back(1);
    set <int> ts;
    ts.insert(1);
    for (int i = 1; k; k--){
        int b = random(1,n);
        if (i == b or ts.find(b) != ts.end()){
            break;
        }
        ls.push_back(b);
        ts.insert(b);
        s.insert({min(i,b), max(i,b)});
    }
    m = s.size();
    cout << n << " " << m << endl;
    cout << random(1,n) << " " << random(1,n) << " " << random(0,20) << " " << ls.size() << endl;
    for (auto i: ls){
        cout << i << " ";
    }
    cout << endl;
    for (auto i: s){
        cout << i.fi << " " << i.se << " " << random(1,10) << endl;
    }
=======
    int n = random(2,1000);
    cout << n << endl;
    randomTree(n);
>>>>>>> 504a6cc3a59da46aa77138bf91bb5be96c0834ff
    return 0;
}