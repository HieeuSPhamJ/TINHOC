#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

struct square{
    ll x, y, z;
    ll u, v, w;
    square(ll a, ll b, ll c, ll d, ll e, ll f){
        x = a;
        y = b;
        z = c;
        u = d;
        v = e;
        w = f;
    }
};

const int maxN = 10;

vector <square> squares;
set <ll> listX;
set <ll> listY;
set <ll> listZ;

int matrix[120][120][120];
int convertX[120];
int convertY[120];
int convertZ[120];
int reConvertX[120];
int reConvertY[120];
int reConvertZ[120];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    listX.insert(0);
    listY.insert(0);
    listZ.insert(0);
    for (int i = 1; i <= n; i++){
        int x, y, z, u, v, w;
        cin >> x >> y >> z >> u >> v >> w;
        square temp(x,y,z,u,v,w);
        squares.push_back(temp);
        listX.insert(x);
        listX.insert(u);
        listY.insert(y);
        listY.insert(v);
        listZ.insert(z);
        listZ.insert(w);
    }

    int j = 0;
    for(auto i: listX){
        convertX[j] = i;
        // cout << i << ' ';
        reConvertX[i] = j;
        j++;
    }
    // cout << endl;
    j = 0;
    for(auto i: listY){
        convertY[j] = i;
        // cout << i << ' ';
        reConvertY[i] = j;
        j++;
    }
    // cout << endl;
    j = 0;
    for(auto i: listZ){
        convertZ[j] = i;
        // cout << i << ' ';
        reConvertZ[i] = j;
        j++;
    }
    // cout << endl;


    for (auto i: squares){
        // cout << reConvertX[i.x] << " " << reConvertX[i.u] << endl;
        // cout << reConvertY[i.y] << " " << reConvertY[i.v] << endl;
        // cout << reConvertZ[i.z] << " " << reConvertZ[i.w] << endl;
        for (int x = reConvertX[i.x]; x <= reConvertX[i.u] - 1; x++){
        for (int y = reConvertY[i.y]; y <= reConvertY[i.v] - 1; y++){
        for (int z = reConvertZ[i.z]; z <= reConvertZ[i.w] - 1; z++){
            matrix[x][y][z] = 1;
        }   
        }   
        }
    }

    
    ll ans = 0;

    for (int z = 1; z <= maxN; z++){
    for (int x = 1; x <= maxN; x++){
    for (int y = 1; y <= maxN; y++){
        // cout << matrix[x][y][z] << ' ';
        if (matrix[x][y][z] == 0){
            continue;
        }
        ll lenx = (reConvertX[x] - reConvertX[x - 1]);
        ll leny = (reConvertY[y] - reConvertY[y - 1]);
        ll lenz = (reConvertZ[z] - reConvertZ[z - 1]);
        ans += (lenx  * leny * lenz);
    }   
    // cout << endl;
    }   
    // cout << endl;
    }
    cout << ans;


    return 0;
}