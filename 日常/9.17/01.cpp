#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#define eps 1e-4
using namespace std;
int T;
long double x1,x2,x3;
long double y2,y3,X,Y,x,y;
long double Y1;
long double r,a,b,c,d,e,f;
int main(){
    scanf("%d",&T);
    while (T--){
    cin>>x1>>Y1>>x2>>y2>>x3>>y3>>X>>Y;
    a=2*(x2-x1);
    b=2*(y2-Y1);
    c=x2*x2+y2*y2-x1*x1-Y1*Y1;
    d=2*(x3-x2);
    e=2*(y3-y2);
    f=x3*x3+y3*y3-x2*x2-y2*y2;
    x=(b*f-e*c)/(b*d-e*a);
    y=(d*c-a*f)/(b*d-e*a);
    if ((X-x)*(X-x)+(Y-y)*(Y-y)>(x-x1)*(x-x1)+(y-Y1)*(y-Y1))puts("Accepted");
    else puts("Rejected");
    }
    return 0;
}
