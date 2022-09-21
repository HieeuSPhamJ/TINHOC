#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;

int MA;
int a[maxN];
int notPrime[maxN];
int res[maxN];
vector <int> listPrime;

void init(){
    notPrime[0] = notPrime[1] = 1;
    for (int i = 2; i  * i <= MA + 5; i++){
        if (notPrime[i] == 0){
            for (int j = 2; i * j <= MA; j++){
                notPrime[i * j] = 1;
            }   
        }
    }

    for (int i = 2; i <= MA; i++){
        if (notPrime[i] == 0){
            listPrime.push_back(i);
            // cout << i << endl;
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    set <int> mySet;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        MA = max(MA, a[i]);
        mySet.insert(a[i]);
    }
    init();
    
    vector <int> lists;

    for (auto i: mySet){
        lists.push_back(i);
    }


    for (auto x: lists){
        // cout << x << endl;
        int ans = 0;
        for (auto i: listPrime){
            int a2 = i * i;
            if (a2 >= x){
                break;;
            }
            for (auto j: listPrime){
                int a3 = j * j * j;
                int a1 = x - a2 - a3;
                if (a1 <= 0){
                    break;
                }
                else if (notPrime[a1] == 0){
                    // cout << a1 << " " << i << " " << j << endl;
                    ans++;
                }
            }
        }
        res[x] = ans;
    }

    for (int i = 1; i <= n; i++){
        cout << res[a[i]] << endl;
    }
    return 0;
}