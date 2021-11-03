#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[102][102];
pair <int,int> mapColorFirst[2003];
pair <int,int> mapColorSecond[2003];
int checkColor[2003];
set <int> mySet;

bool checkFull(int color){
    for (int x=mapColorFirst[color].first;x<=mapColorSecond[color].first;x++){
        for (int y=mapColorFirst[color].second;y<=mapColorSecond[color].second;y++){
            if (a[x][y]!=color){
                // cout<<a[x][y];
                return false;
            }
        }
    }
    return true;
}

void fillColor(int color){
    for (int x=mapColorFirst[color].first;x<=mapColorSecond[color].first;x++){
        for (int y=mapColorFirst[color].second;y<=mapColorSecond[color].second;y++){
            a[x][y]=color;
        }
    }
}

void solveSmall(){
    while(mySet.begin()!=mySet.end()){
        for (set<int>::iterator i=mySet.begin();i!=mySet.end();i++){
            int color=*i;
            if (checkFull(color)){
                cout<<mapColorFirst[color].first<<' '<<mapColorFirst[color].second<<' ';
                cout<<mapColorSecond[color].first<<' '<<mapColorSecond[color].second<<' ';
                cout<<color<<endl;
                mySet.erase(color);
                fillColor(color);
                break;
            }
        }
        cout<<'@';
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("WC1.INP","r",stdin);
    freopen("WC1.OUT","w",stdout);
    int test;
    cin>>test;
    while(test--){
        memset(checkColor,0,sizeof(0));
        cin>>m>>n;
        for (int i=1;i<=n;i++){
            for (int e=1;e<=m;e++){
                int inp;
                cin>>inp;
                a[i][e]=inp;
                mySet.insert(inp);
                if (checkColor[inp]==0){
                    mapColorFirst[inp]={i,e};
                    checkColor[inp]=1;
                }
                mapColorSecond[inp]={i,max(mapColorSecond[inp].second,e)};
            }
        }
        solveSmall();
        // cout<<checkFull(7);
        // int color=7;
        // cout<<mapColorFirst[color].first<<' '<<mapColorFirst[color].second<<' ';
        // cout<<mapColorSecond[color].first<<' '<<mapColorSecond[color].second<<' ';
        // cout<<color<<endl;
        cout<<endl;
    }

}