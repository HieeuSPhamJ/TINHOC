#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int random(int left, int right){
    if (left == right){
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
        "LR";
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
    int n = random(1,5);
    int m = random(1,5);
    cout << n << endl;
    randomTree(n);
    cout << m << endl;
    while(m--){
        int t = random(1,2);
        if (t == 1){
            cout << "add " << random(1,n) << " " << random(-20,20) << endl;
        }
        else{
            cout << "max " << random(1,n) << " " << random(1,n) << endl;
        }
    }
    return 0;
}