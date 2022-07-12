#include<bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int b[maxN];

vector <ii> listLight;

bool cmp(ii a, ii b){
    return a.s <= b.s;
}

int main(){
    freopen("Bwpoint.INP", "r", stdin);
    freopen("Bwpoint.OUT", "w", stdout); 

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        listLight.push_back({1, a[i]});
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
        listLight.push_back({-1, b[i]});
    }
    
    sort(listLight.begin(), listLight.end(), cmp);

    int count = 0;

    for (int i = 1; i < (int)listLight.size(); i++){
        if (listLight[i].f + listLight[i - 1].f == 0){
            count++;
            listLight[i].f = listLight[i - 1].f = 54;
        }
        if (listLight[i].f + listLight[i + 1].f == 0){
            count++;
            listLight[i].f = listLight[i + 1].f = 54;
        }
    }

    cout << count;

    return 0;
}