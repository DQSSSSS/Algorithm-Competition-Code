#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int dx[]={1,-1,0,0,1,1,-1,-1};
const int dy[]={0,0,1,-1,1,-1,1,-1};
const long double eps=1e-11;
const int INF=1e9+10;
const int MAXN=1005;
const int mod=1e9+7;

int sgn(long double a){
    if (fabs(a)<eps) return 0;
    if (a<0) return -1;
    else return 1;
}

struct Point2f{
    //Point2f():id(0),x(0),y(0){}
    //Point2f(int _id,int _x,int _y):id(_id),x(_x),y(_y){}
    void input(int a){id=a;scanf("%d%d",&x,&y);}
   // Point2f operator - (Point2f u){return Point2f(x-u.x,y-u.y);}
   // Point2f operator / (int u){return Point2f(x/u,y/u,x);}
    //Point2f &operator += (Point2f u){x+=u.x,y+=u.y; return *this;}
    Point2f operator = (Point2f u){return (Point2f){id,x,y};}
    //bool operator == (Point2f u){return x==u.x && y==u.y;}
    bool operator != (Point2f u){return x!=u.x || y!=u.y;}
    //bool operator<(const Point2f& u) const
    //    {return x==u.x?y<u.y:x<u.x; }    
    int id,x,y;
};

bool cmp(const Point2f &v, const Point2f& u)
{
	/*puts("233"); 
	cout<<v.x<<' '<<v.y<<endl;
	cout<<u.x<<' '<<u.y<<endl;
	cout<<(v.x==u.x?v.y<u.y:v.x<u.x)<<endl;
	puts("");*/
	return v.x==u.x?v.y<u.y:v.x<u.x; 
}    
    

int n,m,C;
Point2f f[MAXN],g[MAXN];
/*
int edge[105][105],fa[MAXN],h[MAXN];
LL ans;
*/
/*LL power(LL a,LL b){
    LL c=1;
    while(b){
        if (a%2==1) c=a*c%mod;
        a=a*a%mod;
        b/=2;
    }
    return c;
}

int get(int u){
    if (fa[u]==u) return u;
    fa[u]=get(fa[u]);
    return fa[u];
}

void Rotate(){
    for(int i=1;i<=n;i++) swap(g[i].x,g[i].y),g[i].x*=-1;
    sort(g+1,g+n+1,cmp);
    for(int i=2;i<=n;i++) g[i]+=(f[1]-g[1]);
    sort(g+1,g+n+1,cmp);
    for(int i=1;i<=n;i++) if (f[i]!=g[i]) return;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            if (edge[f[i].id][f[j].id]!=edge[g[i].id][g[j].id]) return;
        }
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++){
        int a,b; a=get(f[i].id),b=get(g[i].id);
        if (a!=b) fa[a]=b;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        fa[i]=get(i);
        if (i==fa[i]) cnt++;
    }
    ans+=power(C,cnt);
    cout<<power(C,cnt)<<endl;
    ans%=mod;
}*/

int main(){
    int T; scanf("%d",&T);
    while(T--){
//        memset(edge,0,sizeof(edge)); ans=0;
        scanf("%d%d%d",&n,&m,&C);
        for(int i=1;i<=n;i++) f[i].input(i);
        puts("");
        
        
        for(int i=1;i<=n;i++) g[i].x=f[i].x,g[i].y=f[i].y,g[i].id=f[i].id;
        for(int i=1;i<=n;i++) cout<<f[i].x<<' '<<f[i].y<<endl;
        sort(f+1,f+n+1,cmp);
        puts("");
        for(int i=1;i<=n;i++) cout<<f[i].x<<' '<<f[i].y<<endl;        
        
       /* cout<<n<<endl;
        for(int i=1;i<=n;i++) cout<<g[i].x<<' '<<g[i].y<<endl;
        sort(g+1,g+n+1,cmp);
        puts("");
        for(int i=1;i<=n;i++) cout<<g[i].x<<' '<<g[i].y<<endl;
        
        */
        /*for(int i=1;i<=m;i++){
            int a,b; scanf("%d%d",&a,&b);
            edge[a][b]=edge[b][a]=1;
        }
        Rotate();  
        Rotate();
        Rotate();
        Rotate();
        ans=ans*power(4,mod-2)%mod;
        printf("%lld\n",ans);*/
    }
    return 0;
}
