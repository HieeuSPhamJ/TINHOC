#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define um unordered_map
#define int long long
using namespace std;

struct iii{
    int a, b, w;
};
struct node{
    int a, b, c;
};


const int maxN = 2 * 1e5 + 10;

int father[maxN];
um<int,um<int,um<int,int>>> conv;


bool cmp(iii a, iii b){
    return a.w < b.w;
}
bool cmpX(node a, node b){
    return a.a < b.a;
}
bool cmpY(node a, node b){
    return a.b < b.b;
}
bool cmpZ(node a, node b){
    return a.c < b.c;
}

int findFather(int child){
    if (child == father[child]){
        return child;
    }
    return father[child] = findFather(father[child]);
}

int calLen(node a, node b){
    return min({abs(a.a - b.a), abs(a.b - b.b), abs(a.c - b.c)}); 
}

int CONV(node a){
    return conv[a.a][a.b][a.c];
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // conv[-1][-1][-1] = 32;
    // cout << conv[-1][-1][-1] << endl;

    int n;
    cin >> n;
    
    for (int i = 0; i <= n; i++){
        father[i] = i;
    }
    
    vector <node> listNode;
    vector <node> listX;
    vector <node> listY;
    vector <node> listZ;

    for (int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        conv[a][b][c] = i;
        listNode.push_back({a,b,c});
        listX.push_back({a,b,c});
        listY.push_back({a,b,c});
        listZ.push_back({a,b,c});
    }

    sort(listX.begin(), listX.end(), cmpX);
    sort(listY.begin(), listY.end(), cmpY);
    sort(listZ.begin(), listZ.end(), cmpZ);

    vector <iii> E;

    for (int i = 0; i < listX.size(); i++){
        if (i - 1 >= 0){
            int len = calLen(listX[i], listX[i - 1]);
            E.push_back({CONV(listX[i]), CONV(listX[i - 1]), len});
        }
        if (i + 1 < listX.size()){
            int len = calLen(listX[i], listX[i + 1]);
            E.push_back({CONV(listX[i]), CONV(listX[i + 1]), len});
        }
    }

    for (int i = 0; i < listY.size(); i++){
        if (i - 1 >= 0){
            int len = calLen(listY[i], listY[i - 1]);
            E.push_back({CONV(listY[i]), CONV(listY[i - 1]), len});
        }
        if (i + 1 < listY.size()){
            int len = calLen(listY[i], listY[i + 1]);
            E.push_back({CONV(listY[i]), CONV(listY[i + 1]), len});
        }
    }

    for (int i = 0; i < listZ.size(); i++){
        if (i - 1 >= 0){
            int len = calLen(listZ[i], listZ[i - 1]);
            E.push_back({CONV(listZ[i]), CONV(listZ[i - 1]), len});
        }
        if (i + 1 < listZ.size()){
            int len = calLen(listZ[i], listZ[i + 1]);
            E.push_back({CONV(listZ[i]), CONV(listZ[i + 1]), len});
        }
    }

    

    sort(E.begin(), E.end(), cmp);
    
    int ans = 0;

    for (auto tempE: E){
        int a = findFather(tempE.a);
        int b = findFather(tempE.b);
        if (a == b){
            continue;
        }
        ans = ans + tempE.w;
        father[a] = b;
    }

    cout << ans;

    return 0;
}