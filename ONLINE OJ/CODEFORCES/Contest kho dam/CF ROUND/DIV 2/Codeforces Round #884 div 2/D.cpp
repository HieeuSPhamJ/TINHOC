#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int cnt[maxN];
char a[maxN];
vector <int> ans;

void up(int i, int x){
    for (auto c: ans){
        if(i - c >= 1){
            cnt[a[i - c]] = x;
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        ans.clear();
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                ans.push_back(i);
            }
            if (n % i == 0 and n / i != i){
                ans.push_back(n / i);
            }
        }
        for (int i = 1; i <= n; i++){
            up(i, 1);
            for(int j = 'a' ; j <= 'z'; j++){
                if(cnt[j] == false){
                    a[i] = j;
                    break;
                }
            }
            up(i, 0);
        }
        for (int i = 1; i <= n; i++){
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}

/*
*/