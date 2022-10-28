#include<bits/stdc++.h>
#define ii pair <int,int>
#define dd pair <double,double>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int h;
vector <ii> listNode;
vector <ii> listConvexHull;

void print(ii x){
    cout << "(" << x.fi << ", " << x.se << ")" << " ";
}

int cw(ii a, ii b, ii c){
    return a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se) < 0;
}

int ccw(ii a, ii b, ii c){
    return a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se) > 0;
}

int dcw(dd a, dd b, dd c){
    return a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se) < 0;
}

int dccw(dd a, dd b, dd c){
    return a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se) > 0;
}

dd getInte(ii A, ii B, ii C = {0,h}, ii D = {1,h}){
    double a1 = B.se - A.se;
    double b1 = A.fi - B.fi;
    double c1 = a1*(A.fi) + b1*(A.se);
 
    double a2 = D.se - C.se;
    double b2 = C.fi - D.fi;
    double c2 = a2*(C.fi)+ b2*(C.se);
 
    double determinant = a1*b2 - a2*b1;

    double x = (b2*c1 - b1*c2)/determinant;
    double y = (a1*c2 - a2*c1)/determinant;
    return {x, y};
}


ii ConvexHull(int right){
    listConvexHull.clear();
    ii farLeft = listNode[right];
    ii farRight = listNode.back();
    vector <ii> up;
    up.push_back(farLeft);
    for (int i = right; i < listNode.size(); i++){
        ii now = listNode[i];
        if (i == listNode.size() - 1 or cw(farLeft, now, farRight)){
            while(up.size() >= 2 and !cw(up[up.size() - 2], up[up.size() -  1], now)){
                up.pop_back();
            }
            up.push_back(now);
        }
    }
    ii hill = {0,0};
    // for (auto i: up){
    //     listConvexHull.push_back(i);
    //     if (i.se > hill.se){
    //         hill = i;
    //     }
    // }    

    if ((int)up.size() == 1){
        return up[0];
    }

    return up[1];

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n >> h;
    for (int i = 1; i <= n; i++){
        ii inp;
        cin >> inp.fi >> inp.se;
        listNode.push_back(inp);
    }

    int ans = 0;
    
    for (int i = 2; i < n - 1; i+=2){
        ii valley = listNode[i];
        ii hill = ConvexHull(i);
        // print(valley);
        // print(hill);
        // cout << endl;
        dd inte = getInte(valley, hill);
        // cout << inte.fi << " " << inte.se << endl;
    }

    return 0;
}