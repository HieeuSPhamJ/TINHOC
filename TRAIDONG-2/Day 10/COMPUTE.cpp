#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e6 + 5;
int n = 0;
int p;
int q = 1;
int tu[maxN];
int mau[maxN];
int tu1[maxN];
int mau1[maxN];
char a[maxN];
vector <int> adj[maxN];
stack <int> s;

void fix(int &a , int &b)
{
    int u = __gcd(a , b);
    a /= u;
    b /= u;
    if(b < 0)
    {
        a = -a;
        b = -b;
    }
}

void dfs(int i)
{
    if(!adj[i].empty())
    {
        int u = adj[i][0];
        int v = adj[i][1];
        if(a[u] == '+' or a[u] == '-' or a[u] == '*' or a[u] == '/')
            dfs(u);
        if(a[v] == '+' or a[v] == '-' or a[v] == '*' or a[v] == '/')
            dfs(v);
        if(mau[u] != 0 and mau[v] != 0)
        {
            if(a[i] == '+')
            {
                int p = mau[u] * mau[v] / __gcd(mau[u] , mau[v]);
                tu[i] = tu[u] * p / mau[u] + tu[v] * p / mau[v];
                mau[i] = p;
            }
            else if(a[i] == '-')
            {
                int p = mau[u] * mau[v] / __gcd(mau[u] , mau[v]);
                tu[i] = tu[u] * p / mau[u] - tu[v] * p / mau[v];
                mau[i] = p;
            }
            else if(a[i] == '*')
            {
                mau[i] = (mau[u] * mau[v]);
                tu[i] = (tu[u] * tu[v]);
            }
            else
            {
                if(tu[v] == 0 or mau[v] == 0)
                {
                    cout << "none";
                    exit(0);
                }
                tu[i] = (tu[u] * mau[v]);
                mau[i] = (mau[u] * tu[v]);
            }
            fix(tu[i] , mau[i]);
        }
    }
}

void get(int i)
{
    if(!adj[i].empty())
    {
        int u = adj[i][0];
        int v = adj[i][1];
        int p1 = 0;
        int q1 = 0;
        if(mau[u] != 0)
        {
            p1 = tu[u];
            q1 = mau[u];
        }
        else
        {
            p1 = tu[v];
            q1 = mau[v];
        }
        if(a[i] == '+')
        {
            int G = q * q1 / __gcd(q , q1);
            p = p * G / q - p1 * G / q1;
            q = G;
        }
        else if(a[i] == '-')
        {
            if(mau[v] != 0)
            {
                int G = q * q1 / __gcd(q , q1);
                p = p * G / q + p1 * G / q1;
                q = G;
            }
            else
            {
                int G = q * q1 / __gcd(q , q1);
                p = p1 * G / q1 - p * G / q ;
                q = G;
            }
        }
        else if(a[i] == '/')
        {
            if(mau[v] != 0)
            {
                p = p * p1;
                q = q * q1;
            }
            else
            {
                if(q1 == 0 or p1 == 0 or p == 0 or q == 0)
                {
                    for (int i = 1; i <= n; i++){
                        tu[i] = tu1[i];
                        mau[i] = mau1[i];
                    }
                    for (int i = 1; i <= n; i++){
                        if(a[i] == 'X')
                        {
                            tu[i] = 5;
                            mau[i] = 1;
                        }
                    }
                    dfs(n);
                    if(tu[n] == 0 and mau[n] == 1)
                        cout << "multiple";
                    else
                        cout << "none";
                    exit(0);
                }
                //cout << p1 << " " << q1 << " " << p << " " << q << endl;
                //exit(0);
                int t1 = p;
                int t2 = q;
                p = p1 * t2;
                q = q1 * t1;
            }
        }
        else
        {
            if(q1 == 0 or p1 == 0)
            {
                
                for (int i = 1; i <= n; i++){
                    tu[i] = tu1[i];
                    mau[i] = mau1[i];
                }
                for (int i = 1; i <= n; i++){
                    if(a[i] == 'X'){
                        tu[i] = 5;
                        mau[i] = 1;
                    }
                }
                dfs(n);
                if(tu[n] == 0 and mau[n] == 1)
                    cout << "multiple";
                else
                    cout << "none";
                exit(0);
            }
            p = p * q1;
            q = q * p1;
        }
        fix(p , q);

        //cout << p << " " << q << " " << i << " " << a[i] << " " << p1 << " " << q1 << endl;

        if(mau[u] == 0)
            get(u);
        else
            get(v);
    }
}


signed main(){
    //freopen("input.INP", "n", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "n")) {
        freopen(".inp", "n", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    bool ok = 0;
    char c;
    while(cin >> c){

        n++;
        if((c >= '0' and c <= '9') or c == 'X')
        {
            s.push(n);
            a[n] = c;
            if(c == 'X'){
                ok = 1;
            }
            else{
                tu[n] = a[n] - '0';
                mau[n] = 1;
            }
        }
        else
        {
            adj[n].push_back(s.top());
            s.pop();
            adj[n].push_back(s.top());
            s.pop();
            reverse(all(adj[n]));
            a[n] = c;
            s.push(n);
        }
    }
    
    for (int i = 1; i <= n; i++){
        tu1[i] = tu[i];
        mau1[i] = mau[i];
    }
    dfs(n);
    if(tu[n] == 0 and mau[n] == 1){
        cout << "multiple";
    }
    else{
        if(ok == 0){
            cout << "none";
        }
        else{
            get(n);
            for (int i = 1; i <= n; i++){
                tu[i] = tu1[i];
                mau[i] = mau1[i];
            }
            for (int i = 1; i <= n; i++){
                if(a[i] == 'X'){
                    tu[i] = p;
                    mau[i] = q;
                }
            }
            dfs(n);
            cout << p << " " << q << endl;
        }
    }

}
