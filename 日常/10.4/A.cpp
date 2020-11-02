#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define     N       300005

int i,j,k,l,n,m,zz,ans;

struct Nod
{
    int x,y;
}s[N];

priority_queue <int> Q;

inline  bool    cmp(const Nod &l,const Nod &r){return l.x<r.x;}

int main()
{
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    {
        scanf("%d%d",&s[i].x,&s[i].y);
        s[i].y=s[i].x+s[i].y+m;
    }
    sort(s+1,s+n+1,cmp);
    Q.push(0-s[1].y);
    l=1;
    for (i=2;i<=n;i++)
    {
        zz=Q.top();
        zz=-zz;
        for (;zz<s[i].x;)
        {
            Q.pop();l++;
            if (Q.empty()) break;
            zz=0-Q.top();
        }
        if (zz>=s[i].x&&zz-m<=s[i].x){ans++;Q.pop();}
        Q.push(0-s[i].y);
    }
    printf("%d",ans);
}
