#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<double,double> pii;
const int SZ = 100001;
const LL INF = 1000000010;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};
const double eps = 1e-6;

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

pii l[SZ];

double pf(double x) { return x * x; }

double dist(pii a,pii b)
{
    return sqrt(pf(a.x - b.x) + pf(a.y - b.y));
}

int randint() { return rand() << 16 | rand(); }

pii get(pii a,pii b,pii c)
{
    double a1 = b.x - a.x,b1 = b.y - a.y,c1 = (pf(a1) + pf(b1)) / 2;
    double a2 = c.x - a.x,b2 = c.y - a.y,c2 = (pf(a2) + pf(b2)) / 2;
    double d = a1 * b2 - a2 * b1;
    return make_pair(a.x + (c1*b2 - c2*b1)/d,a.y + (a1*c2 - a2*c1)/d);
}

bool is(pii a,pii b,pii c)
{
    double k1 = (a.y - b.y) / (a.x - b.x);
    double k2 = (c.y - b.y) / (c.x - b.x);
    return fabs(k1 - k2) < eps;
}

int main()
{
    int T = read();
    while(T --)
    {
        int n = read();
        for(int i = 1;i <= n;i ++)
            scanf("%lf%lf",&l[i].x,&l[i].y);
        if(n <= 2) { printf("0 0 %lf\n",dist(make_pair(0,0),l[1])); continue; }
        if(n <= 4) { printf("%lf %lf %lf\n",(l[1].x + l[2].x) / 2.0,(l[1].y + l[2].y) / 2.0,dist(l[1],l[2]) / 2.0); continue; }
        pii ans;
        double r;
        for(int t = 1;;t ++)
        {
            int a = randint() % n + 1,b = randint() % n + 1,c = randint() % n + 1;
            while(a == b || b == c || a == c || is(l[a],l[b],l[c]))
                a = randint() % n + 1,b = randint() % n + 1,c = randint() % n + 1;
            ans = get(l[a],l[b],l[c]);
            r = dist(l[a],ans);
            int tot = 0;
            for(int i = 1;i <= n;i ++)
                if(fabs(dist(ans,l[i]) - r) < eps) tot ++;
            if((n + 1) / 2 <= tot) break;
        }
        printf("%f %f %f\n",ans.x,ans.y,r);
    }
    return 0;
}
