#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int n, LEFT;
int a[maxN];

double timeHad[3][maxN];
double velocity[3][maxN];

void init(){
    n++;
    a[n] = LEFT;
    velocity[0][0] = 1;
    velocity[1][n] = 1;
    for (int i = 1; i < n; i++){
        velocity[0][i] = velocity[0][i - 1] + 1;        
    }
    velocity[0][n] = velocity[0][n - 1];
    for (int i = 1; i <= n; i++){
        timeHad[0][i] = timeHad[0][i - 1] + abs(a[i] - a[i - 1]) / velocity[0][i - 1];
    }

    for (int i = n - 1; i >= 1; i--){
        velocity[1][i] = velocity[1][i + 1] + 1;        
    }
    velocity[1][0] = velocity[1][1];
    for (int i = n - 1; i >= 0; i--){
        timeHad[1][i] = timeHad[1][i + 1] + abs(a[i] - a[i + 1]) / velocity[1][i + 1];
    }

    // for (int i = 0; i <= n; i++){    
    //     cout << a[i] <<": " << velocity[0][i] << " - " << velocity[1][i] << endl;
    // }
    // cout << "----------" << endl;
    // for (int i = 0; i <= n; i++){
    //     cout << a[i] <<": " << timeHad[0][i] << " - " << timeHad[1][i] << endl;
    // }
    // cout << endl;

}

double calLeft(double i){
    int iin = i;
    int left = 0;
    int right = n;
    int lastPos = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        if (a[mid] <= iin){
            lastPos = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    double ans = timeHad[0][lastPos];
    double s = abs(i - (double)a[lastPos]);
    return ans + s / velocity[0][lastPos];
}

double calRight(double i){
    int iin = ceil(i);
    int left = 0;
    int right = n;
    int lastPos = n;
    while(left <= right){
        int mid = (left + right) / 2;
        if (a[mid] >= iin){
            lastPos = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    // cout << lastPos << endl;
    double ans = timeHad[1][lastPos];
    double s = abs(i - (double)a[lastPos]);
    return ans + s / velocity[1][lastPos];
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> LEFT;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    init();

    double left = 0;
    double right = LEFT;
    double ans = 0;
    double delta = 1e8;
    while(left <= right){
        double mid = (left + right) / 2;
        double timeLeft = calLeft(mid);
        double timeRight = calRight(mid);
        // cout << left << " " << mid << " " << right << endl;
        // cout << timeLeft << " " << timeRight << endl;

        if (timeLeft < timeRight){
            left = mid;
        }
        else if (timeLeft > timeRight){
            right = mid;
        }
        double newDelta = abs(timeLeft - timeRight);
        if (delta > newDelta){
            delta = newDelta;
            ans = timeLeft;
        }
        if (newDelta < 0.000001){
            break;
        }
        if (timeLeft == timeRight){
            ans = timeLeft;
            break;
        }
    }

    // cout << calRight(0.5) << endl;
    cout << fixed << setprecision(9) << ans;
    return 0;
}