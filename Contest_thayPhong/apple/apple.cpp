#include<bits/stdc++.h>
using namespace std;

int x[4],y[4];
int ax,ay;
int n;

double Dist(double x1,double y1,double x2,double y2){
    return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) );
}
double DienTich(double ax,double ay,double bx,double by,double cx,double cy){
    double da=Dist(ax,ay,bx,by);
    double db=Dist(bx,by,cx,cy);
    double dc=Dist(cx,cy,ax,ay);
    double p=(da+db+dc)/2;
    //cout<<p<<' '<<da<<' '<<db<<' '<<dc<<' ';
    return sqrt(p* (p-da) * (p-db) * (p-dc) );
}
int main(){
    //cout<<DienTich(1,1,1,3,3,3);
    cin>>n;
    for (int i=1;i<=3;i++)
            cin>>x[i]>>y[i];
    double ST=DienTich(x[1],y[1],x[2],y[2],x[3],y[3]);
    cout<<fixed<<setprecision(1)<<ST;
    int apple=0;
    for (int i=1;i<=n;i++){
            cin>>ax>>ay;
            double SA=DienTich(ax,ay,x[1],y[1],x[2],y[2]);
            double SB=DienTich(ax,ay,x[2],y[2],x[3],y[3]);
            double SC=DienTich(ax,ay,x[3],y[3],x[1],y[1]);
            if (abs(SA+SB+SC-ST)<=1e-6) apple++;
        }
        cout<<apple;
return 0;
}
