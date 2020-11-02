#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1000000010;
const double eps = 1e-7;
const double g2 = sqrt(2);


struct point{
    double x,y;
}p[SZ],S[SZ];

double pw2(double x)
{
    return x * x;
}
point operator -(const point &a,const point &b)
{
    return (point){a.x - b.x,a.y - b.y};
}

double operator *(const point &a,const point &b)
{
    return a.x * b.y - a.y * b.x;
}

double dist1(const point &a,const point &b)
{
    LL x = abs(a.x - b.x);
    LL y = abs(a.y - b.y);
    if(x < y) swap(x,y);
    return (double)y * g2 + (double)(x - y);
}


double dist(const point &a,const point &b)
{
    return sqrt(pw2(a.x - b.x) + pw2(a.y - b.y));
}


bool cmp(const point &a,const point &b)
{
    double t = (a - p[1]) * (b - p[1]);
    if(fabs(t) < eps)
        return dist(a,p[1]) < dist(b,p[1]);
    return t < 0;
}

int n;

double graham()
{
    int k = 1;
    for(int i = 2;i <= n;i ++)
        if(p[i].x < p[k].x || (p[i].x == p[k].x && p[i].y < p[k].y))
            k = i;
    swap(p[1],p[k]);
    sort(p + 2,p + 1 + n,cmp);
    int top = 0;
    S[++ top] = p[1]; S[++ top] = p[2];
    for(int i = 3;i <= n;i ++)
    {
        while(top > 1 && (p[i] - S[top - 1]) * (S[top] - S[top - 1]) < 0)
            top --;
        S[++ top] = p[i];
    }
    double ans = 0;
    for(int i = 1;i <= top;i ++)
        ans += dist1(S[i],S[i == top ? 1 : i + 1]);
    return ans;
}

int main()
{
    freopen("e.in","r",stdin);
    int m;
    scanf("%d",&m);
    n = 0;
    for(int i = 1;i <= m;i ++)
    {
        double x,y;
        scanf("%lf%lf",&x,&y);
        p[++ n].x = x - 1; p[n].y = y;
        p[++ n].x = x + 1; p[n].y = y;
        p[++ n].x = x; p[n].y = y - 1;
        p[++ n].x = x; p[n].y = y + 1;
    }
    printf("%.5f",graham());
    return 0;
}
