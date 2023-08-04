#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define bound first
#define num second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

int n;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    set <ii, greater <ii>> s;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        s.insert({b,a});
    }
    int total = 0;
    int res = 0;
    while(s.size() >= 2){
        auto itla = s.end();
        itla--;
        if ((*itla).bound <= total){
            res += (*itla).num;
            cout << (*itla).bound << " " << (*itla).num << ": " << 1 << endl;
            total += (*itla).num;
            s.erase(itla);
            continue;
        }
        ii la = *itla;
        ii be = *s.begin();
        s.erase(s.begin());
        int t = min(be.num, be.bound);
        if (t + total >= la.bound){
            t = la.bound - total; 
            total += t;
            be.num -= t;
            res += 2 * t;
            cout << be.bound << " " << t << ": " << 2 << endl;
            s.insert(be);
            continue;
        }
        res += 2 * t;
        res += be.num - t;
        cout << be.bound << " " << t << ": " << 2 << endl;
        if (be.num - t > 0){
            cout << be.bound << " " << be.num - t << ": " << 1 << endl;
        }
        total += be.num;
    }

    if (s.size()){
        ii be = *s.begin();
        s.erase(s.begin());
        if (total >= be.bound){
            res += be.num;
            cout << be.bound << " " << be.num << ": " << 1 << endl;
        }
        else{
            int t = min(be.num, be.bound);
            res += 2 * t;
            res += be.num - t;
            cout << be.bound << " " << t << ": " << 2 << endl;
            if (be.num - t > 0){
                cout << be.bound << " " << be.num - t << ": " << 1 << endl;
            }
            total += be.num;
        }
    }   

    cout << res << endl;

    return 0;
}

/*

1 8
1 8
1 7
1 6
1 5
1 3
1 3
1 3

2 7
2 8
1 2
2 4
1 8

2 4 

*/