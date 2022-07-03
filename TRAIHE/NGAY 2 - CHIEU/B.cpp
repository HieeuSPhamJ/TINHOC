#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 1e7 + 10;

int a, b;
bool prime[maxN];
vector <int> lists;

bool check(int n){
    int sn = n;
    int nn = 0;
    while(sn > 0){
        nn *= 10;
        nn += (sn % 10);
        sn /= 10;
    }

    // cout << n << ' ' << nn << endl;

    if (nn == n){
        return 1;
    }
    return 0;
}

void init(){
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <= maxN; i++){
        if (prime[i] == 0){
            for (int j = 2; i * j <= maxN; j++){
                prime[i * j] = 1;
            }
        }
        // cout << prime[i] << ' ';
    }



    for (int i = a; i <= b; i++){
        if (prime[i] == 0){
            lists.push_back(i);
        }
    }   
}


int main(){
    freopen("palinprime.inp", "r", stdin);
    freopen("palinprime.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    init();

    long long sum = 0;

    for (auto i: lists){
        if (check(i)){
            sum += i;
        }
    }

    cout << sum;

    



    return 0;
}