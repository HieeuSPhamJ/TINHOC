#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3e5 + 10;

ii a[maxN];
int va[maxN];
int res[maxN];


int sum = 0;
multiset <int> use, notuse;

void print(){
    cout << "sum: " << sum << endl;
    cout << "use: ";
    for(auto i: use){
        cout << i << " ";
    }
    cout << endl;
    cout << "notuse: ";
    for(auto i: notuse){
        cout << i << " ";
    }
    cout << endl;

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,h;
    cin >> n >> m >> h;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        sum += a[i].se;
    }
    h = sum - h;
    sum = 0;
    for (int i = 1; i <= n; i++){
        cout << "With:" << i << endl;
        int v = a[i].fi;
        int t = a[i].se;
        sum += v;
        if (va[t] == 0){
            va[t] += v;
            use.insert(va[t]);
        }
        else{
            if (use.find(va[t]) != use.end()){
                use.erase(use.find(va[t]));
                va[t] += v;
                use.insert(va[t]);
            }
            else{
                notuse.erase(notuse.find(va[t]));
                va[t] += v;
                notuse.insert(va[t]);
            }
        }

        while(notuse.size() and *notuse.rbegin() > *use.begin()){
            auto it = notuse.end();
            it--;
            sum += *it;
            use.insert(*it);
            notuse.erase(it);
        }
        
        while(sum >= h){
            sum -= *use.begin();
            notuse.insert(*use.begin());
            use.erase(use.begin());
            if (i >= 4){
                break;
            }
        }
        
        print();

        res[i] = m - (int)use.size();
    }
    res[0] = -1;
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }

    return 0;
}

/*
2 1 2 2 1 3 3
3 1 4 1 5 9 2



*/