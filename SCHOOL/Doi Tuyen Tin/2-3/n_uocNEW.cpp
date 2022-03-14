#include<bits/stdc++.h>
using namespace std;
int n;
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
long long ans = 1e18+10;
vector <int> vect;

void phantich(int n){
    int i = 2;
    while(n > 1){
        if (n % i == 0){
            vect.push_back(i);
            n /= i;
        }
        else{
            i++;
        }
    }
}

void backTracking(int d, long long temp, int nx){
    // cout << temp << endl;
    if(nx > n or d >= 16){
        return;
    }
    if(nx == n and temp < ans) {
        ans = temp;
    }
    for(int i = 1; i <= 70; i++){
        if(ans < temp) {
            break;
        }
        backTracking(d+1, temp *= p[d], nx*(i+1));
    }
}

int main(){
    int nq;
    cin >> nq;
    for (int x = 1; x <= nq; x++){
        ans = 1e18 + 10;
        long long ans2 = 1;
        vect.clear();
        n = x;
        phantich(n);
        backTracking(0, 1, 1);
        for (int i = vect.size() - 1, e = 0; i >= 0; i--, e++){
            // cout << p[e] << ' ' << vect[i] << endl;
            ans2 *= pow(p[e], vect[i] - 1);

        }
        if (ans != ans2){
            cout << '@' << x << ' ' << ans << ' ' << ans2 << endl;
        }
        // cout << ans << ' ' << ans2 << endl;
    }
    return 0;
}