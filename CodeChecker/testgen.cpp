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
    int n = 20;
    vector <int> ls;
    ls.push_back(1);
    ls.push_back(1);
    cout << n << endl;
    for (int i = 2; i <= n; i++){
        random_shuffle(all(ls));
        ls.pop_back();
        cout << i << " " << ls.back() << endl;
        ls.push_back(i);
        ls.push_back(i);
    }

    return 0;
}