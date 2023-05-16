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

int n;
int notprime[maxN];
vector <int> ls;

void init(){
    notprime[0] = 1;
    notprime[1] = 1;
    for (int i = 2; i * i < maxN; i++){
        if (notprime[i] == 0){
            for (int j = i * i; j < maxN; j += i){
                notprime[j] = 1;
            }
        }
    }
    for (int i = 2; i < maxN; i++){
        if (notprime[i] == 0){
            ls.push_back(i);
        }
    }
}

int SQRT(int n){
    int i = sqrt(n);
    for (int i = min(0ll, n - 3); i <= n + 3; i++){
        if (i * i == n){
            return i;
        }
    }
    return -1;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int t = -1;
        for (auto p: ls){
            if (n % p == 0){
                t = p;
                break;
            }
        }
        int a = t;
        int b = n / a;
        if (n % (a * a) == 0){
            cout << a << " " << b / a << endl;
        }
        else{
            swap(a,b);
            cout << SQRT(a) << " " << b << endl;
        }
    }
    return 0;
}