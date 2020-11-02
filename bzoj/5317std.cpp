#include<cstdio>
#include<algorithm>
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
typedef long long ll;
using namespace std;

const int N=200010;
int n,m,q,tot;
struct P{ ll x,y; }s,p[N],p1[N],p2[N],v1[N],v2[N],t[N],a[N];
P operator +(const P &a,const P &b){ return (P){a.x+b.x,a.y+b.y}; }
P operator -(const P &a,const P &b){ return (P){a.x-b.x,a.y-b.y}; }
ll operator *(const P &a,const P &b){ return a.x*b.y-a.y*b.x; }
ll len(P a){ return a.x*a.x+a.y*a.y; }

bool cmp(const P &a,const P &b){ ll k=(a-s)*(b-s); return k ? k>0 : len(a-s)<len(b-s); }

int Graham(P a[],int n){
    rep(i,1,n) t[i]=a[i];
    rep(i,2,n) if (t[i].x<t[1].x || (t[i].x==t[1].x && t[i].y<t[1].y)) swap(t[1],t[i]);
    s=t[1]; sort(t+2,t+n+1,cmp); int top=1;
    rep(i,2,n){
        while (top>1 && (t[top]-t[top-1])*(t[i]-t[top-1])<=0) top--;
        t[++top]=t[i];
    }
    printf("%d\n",top);
    for(int i = 1;i <= top;i ++) printf("(%lld,%lld)\n",t[i].x,t[i].y);
    rep(i,1,top) a[i]=t[i];
    return top;
}

bool jud(P x){
    P vx=x-p[1];
    if (vx*(p[tot]-p[1])<0 || vx*(p[2]-p[1])>0) return 0;
    int px=lower_bound(p+2,p+tot+1,x,cmp)-p-1;
    return (x-p[px])*(p[px%tot+1]-p[px])<=0;
}

int main(){
    freopen("war1.in","r",stdin);
    scanf("%d%d%d",&n,&m,&q);
    rep(i,1,n) scanf("%lld%lld",&p1[i].x,&p1[i].y);
    rep(i,1,m) scanf("%lld%lld",&p2[i].x,&p2[i].y),p2[i].x=-p2[i].x,p2[i].y=-p2[i].y;
    n=Graham(p1,n); m=Graham(p2,m);
    return 0;
    rep(i,1,n-1) v1[i]=p1[i+1]-p1[i]; v1[n]=p1[1]-p1[n];
    rep(i,1,m-1) v2[i]=p2[i+1]-p2[i]; v2[m]=p2[1]-p2[m];
    p[1]=p1[1]+p2[1]; tot=1;
    int l1=1,l2=1;
    while (l1<=n || l2<=m)
        tot++,p[tot]=p[tot-1]+((l1<=n && (l2>m || (v1[l1]*v2[l2]>=0))) ? v1[l1++] : v2[l2++]);
    while (tot>1 && (p[tot]-p[tot-1])*(p[1]-p[tot-1])<=0) tot--;

    printf("%d\n",tot);
    for(int i = 1;i <= tot;i ++) printf("(%lld,%lld)\n",p[i].x,p[i].y);
    return 0;
    s=p[1]; P qs;
    rep(i,1,q) scanf("%lld%lld",&qs.x,&qs.y),printf("%d\n",jud(qs));
    return 0;
}
