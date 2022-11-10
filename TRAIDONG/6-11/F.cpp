#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 510;

int a[maxN];
int m[maxN][maxN];

int check(int i, int j){
    if (a[i] < 0 or a[j] > 0){
        return 0;
    }
    if (a[i] * a[j] == 0){
        if (a[i] == a[j]){
            return 3;
        }
        return 1;
    }
    if (a[i] == a[j]){
        return 1;
    }
    return 0;
}

int dp(int left, int right){
    if (m[left][right] != -1){  
        cout << left << " " << right << " " << m[left][right] << endl;
        return m[left][right];
    }
    if (left == right - 1){
        m[left][right] = check(left, right);
        cout << left << " " << right << " " << m[left][right] << endl;
        return m[left][right];
    }
    if (left == right){
        m[left][right] = 0;
        cout << left << " " << right << " " << m[left][right] << endl;
        return m[left][right];
    }
    m[left][right] = dp(left + 1, right - 1) * check(left, right);
    for (int i = left + 1; i < right; i++){
        m[left][right] += dp(left, i) * dp(i + 1, right) * check(left, i);
    }
    cout << left << " " << right << " " << m[left][right] << endl;
    return m[left][right];
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    memset(m, -1, sizeof(m));
    for (int i = 1; i <= n; i++){
        if (s[i] == '('){
            a[i] = 1;
        }
        else if (s[i] == ')'){
            a[i] = -1;
        }
        else if (s[i] == '['){
            a[i] = 2;
        }
        else if (s[i] == ']'){
            a[i] = -2;
        }
        else if (s[i] == '{'){
            a[i] = 3;
        }
        else if (s[i] == '}'){
            a[i] = -3;
        }
        else{
            a[i] = 0;
        }
        cout << a[i] << " ";
    }
    cout << endl;
    cout << dp(1,n);
    return 0;
}