#include <bits/stdc++.h>
using namespace std;
 
long long cal(vector<int> x) {
    sort(x.begin(), x.end());
    return x[x.size() / 2] - x[(x.size() - 1) / 2] + 1;
}
 
 
int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> x, y;
        for (int i = 1; i <= n; ++i){
            int a, b;
            cin >> a >> b;
            x.push_back(a);
            y.push_back(b);
        }
        cout << cal(x) * cal(y) << endl;
    }
    return 0;
}