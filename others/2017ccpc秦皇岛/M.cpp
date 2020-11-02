#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int MAXN=2000000+10;
const int mod=1e9+7;
const int INF=1e9+10;
const double EPS=1e-8;
const double PI=acos(-1);
typedef long long T;

double sqr(double a){
    return a*a;
}

int sgn(double a){
    if (fabs(a)<=EPS) return 0;
    if (a<0) return -1;
    else return 1;
}

struct Point{
    Point(T _x=0,T _y=0):x(_x),y(_y){}
    void input(){scanf("%d%d",&x,&y);}    
    double distance(Point p){
        return sqrt(sqr(x-p.x)+sqr(y-p.y));
    }
    T x,y;
    
    friend Point Dot(Point u,Point v){return Point(u.x*v.x,u.y*v.y);}
    friend T Cross(Point u,Point v){return (u.x*v.y-u.y*v.x);}
};

struct Circle{
    Circle(){}
    Circle(Point p,LL r):center(p),radius(r){}
    
    double area(){return PI*radius*radius;}
    
    //两圆的关系
    //5 相离
    //4 外切
    //3 相交
    //2 内切
    //1 内含
    //需要 Point 的 distance
    //测试：UVA12304
    int relationcircle(Circle v){
        double d = center.distance(v.center);
        if(sgn(d - radius - v.radius) > 0)return 5;
        if(sgn(d - radius - v.radius) == 0)return 4;
        double l = fabs(radius - v.radius);
        if(sgn(d - radius - v.radius)<0 && sgn(d - l)>0)return 3;
        if(sgn(d - l)==0)return 2;
        if(sgn(d - l)<0)return 1;
        return 0;
    }
    
    double areacircle(Circle v){
        int rel = relationcircle(v);
        if(rel >= 4)return 0.0;
        if(rel <= 2)return min(area(),v.area());
        double d = center.distance(v.center);
        double hf = (radius+v.radius+d)/2.0;
        double ss = 2*sqrt(hf*(hf - radius)*(hf - v.radius)*(hf - d));
        double a1 = acos((radius*radius+d*d - v.radius*v.radius)/(2.0*radius*d));
        a1 = a1*radius*radius;
        double a2 = acos((v.radius*v.radius+d*d - radius*radius)/(2.0*v.radius*d));
        a2 = a2*v.radius*v.radius;
        return a1+a2 - ss;
    }
    
    Point center;
    T radius;    
};

int n,R,r;
Circle f[1005];
double ans[1005];
int xc[1005];

int main(){
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&R,&r);
        for(int i=1;i<=n;i++){
            int a,b; scanf("%d%d",&a,&b);
            f[i]=Circle(Point(a,b),r);
        }
        Circle c1(Point(),R-r);
        double mx=0;
        for(int i=1;i<=n;i++){
            ans[i]=f[i].areacircle(c1);
            mx=max(mx,ans[i]);
        }
        int num=0;
        for(int i=1;i<=n;i++)
            if (sgn(mx-ans[i])==0) num++;
        printf("%d\n",num);
        int cnt=0;
        for(int i=1;i<=n;i++) 
            if (sgn(mx-ans[i])==0) xc[++cnt]=i;
        for(int i=1;i<=cnt;i++)
        	printf("%d%c",xc[i],i==cnt?'\n':' ');
    }
    return 0;
}

