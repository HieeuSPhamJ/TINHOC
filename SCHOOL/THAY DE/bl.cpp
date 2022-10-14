#include<bits/stdc++.h>

#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'

using namespace std;

const int maxN = 10010;

vector <ii> listNode;
vector <ii> listConvexHull;

int cw(ii a, ii b, ii c){
    return a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se) < 0;
}

int ccw(ii a, ii b, ii c){
    return a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se) > 0;
}


void ConvexHull(){
    listConvexHull.clear();
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
    // cout << len << endl;
//    for (auto i: up){
//        cout << i.fi << " " << i.se << endl;
//    }
//    cout << "---" << endl;
    

    for (auto i: down){
        // cout << i.fi << " " << i.se << endl;
        listConvexHull.push_back(i);
    }
//    cout << "---" << endl;
    for (int i = (int)up.size() - 2; i >= 1; i--){
        // cout << up[i].fi << " " << up[i].se << endl;
        listConvexHull.push_back(up[i]);
    }

    // for (auto i: listConvexHull){
    //     cout << i.fi << " " << i.se << endl;
    // }
    // cout << "=====" << endl;
}

int calArea(ii a, ii b, ii c){
    return a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se);
}


void AreaConvexHull(){
    ConvexHull();

    int ans = 0;

    int len = listConvexHull.size();
    ii root = listConvexHull[0];
    for (int i = 0; i < len; i++){
        ii a = listConvexHull[i % len];
        ii b = listConvexHull[(i + 1) % len];
        int area = (calArea(root, a, b));
        ans += area;
    }
    ans = abs(ans);
    cout << ans / 2 << "." << (ans % 2) * 5 << endl;
}

signed main(){
    // freopen("bl.INP", "r", stdin);
    // freopen("bl.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
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

    AreaConvexHull();

    while(n > 3){
        n--;
        char x;
        cin >> x;
        if (x == 'U'){
            ii t = {0,0};
            for (auto i: inp){
                if (t.se <= i.se){
                    t = i;
                }
            }
            inp.erase(inp.find(t));
        }
        else if (x == 'D'){
            ii t = {1e18,1e18};
            for (auto i: inp){
                if (t.se >= i.se){
                    t = i;
                }
            }
            inp.erase(inp.find(t));
        }
        else if (x == 'L'){
            ii t = {1e18,1e18};
            for (auto i: inp){
                if (t.fi >= i.fi){
                    t = i;
                }
            }
            inp.erase(inp.find(t));
        }
        else if (x == 'R'){
            ii t = {0,0};
            for (auto i: inp){
                if (t.fi <= i.fi){
                    t = i;
                }
            }
            inp.erase(inp.find(t));
        }

        listNode.clear();
        for (auto i: inp){
            listNode.push_back(i);
        }

        AreaConvexHull();

    }
    return 0;
}
