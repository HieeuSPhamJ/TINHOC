#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;


int random(int left, int right){
    if (left >= right){
        return left;
    }
    return (rand() % (right - left + 1)) + left;
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
    cout << 1 << endl;
    int n = random(500,1000);
    cout << n << endl;
    for (int i = 1; i <= n; i++){
        cout << random(-100,100) << " ";
    }
    cout << endl;
    int test = 10;
    cout << test << endl;
    while(test--){
        cout << random(1,10) << " " << random(1,100) << endl;
    }
    return 0;
}