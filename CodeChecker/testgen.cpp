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
        "hard";
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
    int n = random(2,100);
    int test = random(1,100);
    cout << n << " " << test << endl;
    vector<int> ds;
    for(long i=2; i<=n; i++) ds.push_back(i);
    random_shuffle(ds.begin(),ds.end());
    int l=1;
    int x=0;
    while(x<n-1){
        x=random(x+1,n-1);
        cout<<1<<' '<<ds[l-1]<<'\n';
        for(long i=l; i<x; i++){
            cout<<ds[i-1]<<' '<<ds[i]<<'\n';
        }
        l=x+1;
    }
    while(test--){
        int t = random(0,1);
        cout << t << " ";
        if (t == 1){
            cout << random(1,n) << endl;
        }
        else{
            cout << random(1,n) << " " << random(1,n) << " " << random(1,n) << endl;
        }
    }
    return 0;
}