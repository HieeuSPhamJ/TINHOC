#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector <double> listA;
vector <double> listB;

double calLen(double a, double b){
    return sqrt(a * a + b * b);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        double a, b;
        cin >> a >> b;
        listA.push_back(calLen(a,b));
    }
    for (int i = 1; i <= n; i++){
        double a, b;
        cin >> a >> b;
        listB.push_back(calLen(a,b));
    }

    sort(listA.rbegin(), listA.rend());
    sort(listB.rbegin(), listB.rend());

    // for (auto i: listA){
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (auto i: listB){
    //     cout << i << " ";
    // }
    // cout << endl;

    double R = max(listA.back(), listB.back());
    // cout << listA.back() << " " << listB.back() << endl;
    listA.pop_back();
    listB.pop_back();
    while (!listA.empty() and !listB.empty() and listA.back() <= R or listB.back() <= R){
        R = max(listA.back(), listB.back());
        // cout << listA.back() << " " << listB.back() << endl;
        listA.pop_back();
        listB.pop_back();
    }

    cout << fixed << setprecision(6) << R << endl;
    

    return 0;
}