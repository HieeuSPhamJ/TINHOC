#include<bits/stdc++.h>

#define int long long
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'

using namespace std;

const int maxN = 1e6 + 10;

int MA = 0;
int a[maxN];
int res[maxN];
int notPrime[maxN];
vector <int> listPrime;

void init(){
    notPrime[0] = notPrime[1] = 1;

    for (int i = 2; i * i <= MA + 5; i++){
        if (notPrime[i] == 0){
            for (int j = 2; i * j <= MA; j++){
                notPrime[i * j] = 1;
            }
        }
    }

    for (int i = 2; i <= MA; i++){
        if (notPrime[i] == 0){
            listPrime.push_back(i);
//            cout << i << " ";
        }
    }
//    cout << listPrime.size();
}


signed main(){
    freopen("APRIME.INP", "r", stdin);
    freopen("APRIME.OUT", "w", stdout);
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set <int> mySet;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        MA = max(MA, a[i]);
        mySet.insert(a[i]);
    }
    vector <int> lists;
    for (auto i: mySet){
        lists.push_back(i);
    }
    init();
    for (int xi = 0; xi <(int)lists.size(); xi++){
        int x = lists[xi];
//        cout << x << " ";
        int ans = 0;
        for (int iis = 0; iis <(int)listPrime.size(); iis++){
            int i = listPrime[iis];
            int a2 = i * i;
            if (a2 >= x){
                continue;
            }
            for (int jis = 0; jis <(int)listPrime.size(); jis++){
                int j = listPrime[jis];
                int a3 = j * j * j;
                if (a2 + a3 >= x){
                    continue;
                }
                int a1 = x - a2 - a3;
                if (notPrime[a1] == 0){
                    ans++;
                }

            }
        }
        res[x] = ans;
//        cout << ans << endl;
    }

    for (int i = 1; i <= n; i++){
        cout << res[a[i]] << endl;
    }

    return 0;
}



