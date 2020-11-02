#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Point{
    LL x,y;
    Point(LL xx=0,LL yy=0):x(xx),y(yy){}
    LL operator^(const Point& b)const{return x*b.y-b.x*y;}
    LL operator*(const Point& b)const{return x*b.x+y*b.y;}
    Point operator-(const Point& b)const{return Point(x-b.x,y-b.y);}
    double dis(const Point& b)const{return ((double)x-b.x)*(x-b.x)+((double)y-b.y)*(y-b.y);}
}a[5005],b[5005],c[5005],P;
bool cmp(Point x,Point y){
    LL d=(x-P)^(y-P);
    if(d>0)return 1;
    if(d<0)return 0;
    return x.dis(P)<y.dis(P);
}
LL C2(int x){if(x<2)return 0;return (LL)x*(x-1)/2;}
LL C3(int x){if(x<3)return 0;return (LL)x*(x-1)*(x-2)/6;}
int main(){
    freopen("F.in","r",stdin);
    freopen("std.out","w",stdout);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld%lld",&a[i].x,&a[i].y);
    bool f=1;
    for(int i=1;i<n-1;i++){
        if(((a[i]-a[1])^(a[i+1]-a[1]))!=0){f=0;break;}
    }
    if(f){puts("0");return 0;}
    LL ans=0;
    for(int i=0;i<n;i++){
        int k1=0,k2=0;
        for(int j=0;j<n;j++){
            if(i==j)continue;
            if(a[j].y>a[i].y||(a[j].y==a[i].y&&a[j].x>a[i].x))b[k1++]=a[j];
            else c[k2++]=a[j];
        }
        P=a[i];
        sort(b,b+k1,cmp);
        sort(c,c+k2,cmp);
        for(int j=0;j<k2;j++)b[j+k1]=c[j];
        for(int j=0;j<n-1;j++)b[j+n-1]=b[j];

        LL tmp=0;;
        for(int j=0,k=0;j<n-1;j++){
            while(k<j+n-1&&(((b[k]-P)^(b[j]-P))<=0))k++;
            tmp+=C2(k-j-1);
            int m=j;
            while(j+1<n-1&&((b[j]-P)^(b[j+1]-P))==0&&((b[j]-P)*(b[j+1]-P))>=0){
                j++;
                tmp+=C2(k-j-1);
            }
            if(k>=n){
                int t=k-1;
                while(t>j&&((b[t]-P)^(b[j]-P))==0)t--;
                tmp=tmp-(j-m+1)*C2(k-t-1)-(k-t-1)*C2(j-m+1);
            }
        }
        ans+=C3(n-1)-tmp;
    }
    cout<<ans<<endl;
    return 0;
}
