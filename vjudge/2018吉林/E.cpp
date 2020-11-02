#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=1e3+10;
const int mod=1e9+7;
const double eps=1e-7;

int sgn(double a){
    if (fabs(a)<eps) return 0;
    if (a>0) return 1;
    return -1;
}

int main(){
    int T,cas=0; scanf("%d",&T);
    while(T--){
        double r,h;
        scanf("%lf%lf",&r,&h);
        double ppx,ppy,ppz,ddx,ddy,ddz;
        scanf("%lf%lf%lf",&ppx,&ppy,&ppz);
        scanf("%lf%lf%lf",&ddx,&ddy,&ddz);
        long double px=ppx,py=ppy,pz=ppz,dx=ddx,dy=ddy,dz=ddz;
        long double ox=px,oy=py,oz=pz;
        long double k = r*r/h/h;
        long double a = dx * dx + dy * dy - k * dz * dz;
        long double b = 2 * (dx * ox + dy * oy - k * dz * (oz - h));
        long double c = ox * ox + oy * oy - k * (oz - h) * (oz - h);
        long double discrim = b * b - 4 * a * c;
        long double rootDiscrim = sqrt(discrim);
        /*long double q;
        if (b < 0) q = (-b + rootDiscrim)/2;
        else q = (-b - rootDiscrim)/2;
        long double t0 = q / a;
        long double t1 = c / q;
        long double ans=min(t0,t1);
        if(ans < 1e-8) ans = 0;*/
        long double ans = (-b-rootDiscrim)/2/a;
        printf("Case %d: %.10f\n",++cas,(double)ans);
    }
    return 0;
}
