#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 3 * 1e5 + 10;

ii negaBoi[maxN];
ii negaGi[maxN];
ii posiBoi[maxN];
ii posiGi[maxN];

ii ans[maxN];

bool cmp(ii a, ii b){
    return a.f < b.f;
}

int checkBoi[maxN];
int checkGi[maxN];


int main(){
    freopen("couples.inp", "r", stdin);
    freopen("couples.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int phong;
    cin >> phong;

    int lenNegaBoi = 0;
    int lenNegaGi = 0;
    int lenPosiBoi = 0;
    int lenPosiGi = 0;
    int x = 0;
    int y = 0;
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        if (inp > 0){
            posiBoi[lenPosiBoi] = {inp, i};
            lenPosiBoi++;

        }
        else{
            negaBoi[lenNegaBoi] = {-inp, i};
            lenNegaBoi++;
        }
    }
    int m;
    cin >> m;
    x = 0;
    y = 0;
    for (int i = 1; i <= m; i++){
        int inp;
        cin >> inp;
        if (inp > 0){
            posiGi[lenPosiGi] = {inp, i};
            lenPosiGi++;
        }
        else{
            negaGi[lenNegaGi] = {-inp, i};
            lenNegaGi++;
        }
    }

    sort(negaGi, negaGi + lenNegaGi);
    sort(posiGi, posiGi + lenPosiGi);
    sort(posiBoi, posiBoi + lenPosiBoi);
    sort(negaBoi, negaBoi + lenNegaBoi);

    int lenAns = 0;

    for (int i = 0, j = 0; i < lenNegaBoi and j < lenPosiGi;){
        ii boi = negaBoi[i];
        ii gi = posiGi[j];
        if (boi.f > gi.f){
            ans[lenAns] = {boi.s, gi.s};
            lenAns++;
            i++;
            j++;
        }
        else if (boi.f <= gi.f){
            i++;
        }
    }
    for (int i = 0, j = 0; i < lenPosiBoi and j < lenNegaGi;){
        ii boi = posiBoi[i];
        ii gi = negaGi[j];
        if (boi.f < gi.f){
            ans[lenAns] = {boi.s, gi.s};
            lenAns++;
            i++;
            j++;
        }
        else if (boi.f >= gi.f){
            j++;
        }
    }
    


    cout << lenAns << endl;

    for (int i = 0; i < lenAns; i++){
        cout << ans[i].f << " " << ans[i].s << endl;
    }
    

    return 0;
}