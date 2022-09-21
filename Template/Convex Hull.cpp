#include<bits/stdc++.h>

#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'

using namespace std;

const int maxN = 10010;

vector <ii> listNode;

int cw(ii a, ii b, ii c){
    return a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se) < 0;
}

int ccw(ii a, ii b, ii c){
    return a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se) > 0;
}


void ConvexHull(){
    ii farLeft = listNode.front();
    ii farRight = listNode.back();

    vector <ii> up;
    vector <ii> down;
    up.push_back(farLeft);
    down.push_back(farLeft);

    for (int i = 1; i < listNode.size(); i++){
        ii now = listNode[i];
        if (i == listNode.size() - 1 or cw(farLeft, now, farRight)){
            while(up.size() >= 2 and !cw(up[up.size() - 2], up[up.size() -  1], now)){
                up.pop_back();
            }
            up.push_back(now);
        }

        if (i == listNode.size() - 1 or ccw(farLeft, now, farRight)){
            while(down.size() >= 2 and !ccw(down[down.size() - 2], down[down.size() -  1], now)){
                down.pop_back();
            }
            down.push_back(now);
        }
    }

    int len = up.size() + max(0ll, (int)down.size() - 2);
    cout << len << endl;
//    for (auto i: up){
//        cout << i.fi << " " << i.se << endl;
//    }
//    cout << "---" << endl;
    for (auto i: down){
        cout << i.fi << " " << i.se << endl;
    }
//    cout << "---" << endl;
    for (int i = (int)up.size() - 2; i >= 1; i--){
        cout << up[i].fi << " " << up[i].se << endl;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while(cin >> n){
        if (n == 0){
            break;
        }
        set <ii> inp;
        for (int i = 1; i <= n; i++){
            int x, y;
            cin >> x >> y;
            inp.insert({x, y});
        }
        listNode.clear();
        for (auto i: inp){
            listNode.push_back(i);
        }

        ConvexHull();
    }
    return 0;
}
