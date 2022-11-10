#include<bits/stdc++.h>
#define ii pair <int,int>
#define iii pair <int,ii>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e7;

int n;
int a[4][4];
int POW[20];
iii trace[maxN];
int visited[maxN];


int fastpow(int n, int a){
    if (a == 1){
        return n;
    }
    int temp = fastpow(n, a / 2);
    int ans = temp * temp;
    if (a % 2){
        return ans * n;
    }
    else{
        return ans;
    }
}

int setmask(int mask, int i, int val){
    /*
    33333
    */
    int rem = mask % POW[i];
    int back = mask % POW[i - 1];
    return mask - rem + back + val * POW[i - 1]; 
}

int getmask(int mask, int i){
    mask /= POW[i - 1];
    return mask % 3; 
}

void init(){
    POW[0] = 1;
    for (int i = 1; i <= 16; i++){
        POW[i] = POW[i - 1] * 3;
    }
}
 
void convertToTernary(int N)
{
    if (N == 0)
        return;
    int x = N % 3;
    N /= 3;
    if (x < 0)
        N += 1;
 
    convertToTernary(N);
 
    if (x < 0)
        cout << x + (3 * -1);
    else
        cout << x;
}
void print(int Decimal)
{
 
    if (Decimal != 0) {
        convertToTernary(Decimal);
        cout << " ";
    }
    else
        cout << "0" << " ";
}

void truyvet(int nu){
    if (nu == 0){
        return;
    }
    truyvet(trace[nu].fi);
    // print(nu);
    cout << char('A' + trace[nu].se.fi) << char('A' + trace[nu].se.se) << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> a[i][j];
        }
    }
    init();
    queue <int> q;
    q.push(0);
    visited[0] = 0;
    trace[0] = {-1,{-1, -1}};
    while(!q.empty()){
        int t = q.front();
        // cout << "#";
        // print(t);
        // cout << endl;
        q.pop();
        int col[4];
        for (int i = n; i >= 1; i--){
            col[getmask(t,i)] = i;
        }
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (a[i][j] and i != j){
                    if (col[i] < col[j]){
                        int nu = setmask(t,col[i],j);
                        // print(nu);
                        q.push(nu);
                        visited[nu] = visited[t] + 1;
                        trace[nu] = {t, {i,j}};
                    }
                }
            }
        }
        // cout << endl;
    }


    // cout << setmask(0, 4, 2);
    int goal = POW[n] - 1;

    cout << visited[goal] << endl;
    truyvet(goal);

    return 0;
}