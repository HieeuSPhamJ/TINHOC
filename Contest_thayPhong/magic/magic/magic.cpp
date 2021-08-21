#include <bits/stdc++.h>
using namespace std;
int m,n;
char a[60][60];
//char ans[110][110];
int x,y;

int main(){
  cin>>m>>n;
  int ip = 1;
  int jp = 1;
  for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++)
      cin>>a[i][j];
  cin>>x>>y;


  for (int i=1;i<=m;i++){
    for (int j=1;j<=n;j++){
      if (ip == x and jp == y) {
        if (a[i][j] == '#') cout<<'.';
        else cout<<'#';
      }
      else cout<<a[i][j];
      //cout<<' '<<ip<<' '<<jp<<' ';
      jp++;
    }
    for (int j=n;j>0;j--){
      if (ip == x and jp == y) {
        if (a[i][j] == '#') cout<<'.';
        else cout<<'#';
      }
      else cout<<a[i][j];
      //cout<<' '<<ip<<' '<<jp<<' ';
      jp++;
    }
    jp = 1;
    ip++;
    cout<<endl;
  }


  for (int i=m;i>0;i--){
    for (int j=1;j<=n;j++){
      if (ip == x and jp == y) {
        if (a[i][j] == '#') cout<<'.';
        else cout<<'#';
      }
      else cout<<a[i][j];
      //cout<<' '<<ip<<' '<<jp<<' ';
      jp++;
    }
    for (int j=n;j>0;j--){
      if (ip == x and jp == y) {
        if (a[i][j] == '#') cout<<'.';
        else cout<<'#';
      }
      else cout<<a[i][j];
      //cout<<' '<<ip<<' '<<jp<<' ';
      jp++;
    }
    jp = 1;
    ip++;
    cout<<endl;
  }
  //cout<<ip<<' '<<jp;

return 0;
}
