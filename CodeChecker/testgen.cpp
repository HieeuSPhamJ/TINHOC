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
        "ab";
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
    int n = random(1,10);
    int test = random(1,20);
    cout << n << " " << test << endl;

    vector <ii> tree;

    for (int i = 2; i <= n; i++){
        tree.push_back({i,random(1,i - 1)});
    }
    
    random_shuffle(tree.begin(), tree.end());
    int cnt = 0;
    while(test--){
        int t = random(1,3);
        if ((t == 3 and cnt == 0) or (t == 1 and tree.empty())){
            t = 2;
        }

        cout << t << " ";
        
        if (t == 1){
            cout << tree.back().fi << " " << tree.back().se << endl;
            tree.pop_back();
        }
        else if (t == 2){
            cnt++;
            cout << random(1,n) << endl;
        }
        else{
            cout << random(1,n) << " " << random(1,cnt) << endl;
        }
    }
    return 0;
}