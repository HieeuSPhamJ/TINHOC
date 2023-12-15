#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 3e5 + 10;
int n;
int a[maxN];

int sum1 = 0;
int sum2 = 0;
multiset <int> fs;
multiset <int, greater<int>> ss;
multiset <int> tss;

void print(){
    cout << sum1 << " " << sum2 << endl;
    for (auto i: fs){
        cout << i << " ";
    }
    cout << endl;
    for (auto i: ss){
        cout << i << " ";
    }
    cout << "| ";
    for (auto i: tss){
        cout << i << " ";
    }
    cout << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("SEQ3N.inp", "r")) {
        freopen("SEQ3N.inp", "r", stdin);
        freopen("SEQ3N.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= 3 * n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        int x = a[i];
        fs.insert(x);
        sum1 += x;
    }
    for (int i = n + 1; i <= 3 * n; i++){
        int x = a[i];
        if ((int)ss.size() < n){
            ss.insert(x);
            sum2 += x;
        }
        else{
            if (*ss.begin() > x){
                ss.insert(x);
                sum2 += x;
                sum2 -= *ss.begin();
                tss.insert(*ss.begin());
                ss.erase(ss.begin());
            }
            else{
                tss.insert(x);
            }
        }
    }

    // print();
    
    int res = -1e18;
    res = max(res, sum1 - sum2);
    for (int i = n + 1; i <= 2 * n; i++){
        int x = a[i];
        if (*fs.begin() < x){
            fs.insert(x);
            sum1 += x;
            sum1 -= *fs.begin();
            fs.erase(fs.begin());
        }
        if (ss.find(x) != ss.end()){
            ss.erase(ss.find(x));
            sum2 -= x;
            sum2 += *tss.begin();
            ss.insert(*tss.begin());
            tss.erase(tss.begin());
        }
        else{
            tss.erase(tss.find(x));
        }
        // cout << "With: " << i << endl;
        // print();
        res = max(res, sum1 - sum2);
    }
    cout << res << endl;
    return 0;
}