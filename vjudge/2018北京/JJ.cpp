#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
#define __int128 LL
const int MAXN=2e3+10;
const int mod=998244353;
const double eps=1e-7;

struct Point{
    Point(__int128 _x=0,__int128 _y=0):x(_x),y(_y) {}
    void Read() {LL a,b; scanf("%lld%lld",&a,&b); x=a; y=b;}

    Point operator + (const Point &p) const {return Point(x+p.x,y+p.y);}
    Point operator - (const Point &p) const {return Point(x-p.x,y-p.y);}
    Point operator % (const int m) const {return Point(x%m,y%m);}

    bool operator == (const Point &p) const {return x==p.x && y==p.y;}

    __int128 x,y;

    friend Point Rotate90(Point p) {return Point(-p.y,p.x);}
    friend int CrossOp(Point p1,Point p2) {
        __int128 p1x=p1.x,p2x=p2.x,p1y=p1.y,p2y=p2.y;
        __int128 v=p1x*p2y-p1y*p2x;
        if (v<0) return -1;
        if (v==0) return 0;
        return 1;
    }
    friend int DotOp(Point p1,Point p2){
        __int128 p1x=p1.x,p2x=p2.x,p1y=p1.y,p2y=p2.y;
        __int128 v=p1x*p2x+p1y*p2y;
        if (v<0) return -1;
        if (v==0) return 0;
        return 1;
    }
    friend LL Cross(Point p1,Point p2) {
        LL p1x=p1.x%mod,p2x=p2.x%mod,p1y=p1.y%mod,p2y=p2.y%mod;
        return ((p1x*p2y)%mod-(p1y*p2x)%mod)%mod;
    }
};
int n;
vector<Point> f,g,h,sum;

void Solve(int idx,LL& sum1,LL& sum2){
    Point p=f[idx];
    h.clear();
    for(int i=0;i<n;i++){
        if (f[i]==p) continue;
        h.push_back(f[i]-p);
    }
    sort(h.begin(),h.end(),[&](const Point& p1,const Point& p2){
        LL tmp=CrossOp(p1,p2);
        LL prt1,prt2;
        if (p1.y<0 || (p1.y==0 && p1.x>=0)) prt1=-1;
        else prt1=1;
        if (p2.y<0 || (p2.y==0 && p2.x>=0)) prt2=-1;
        else prt2=1;
        return prt1<prt2 || (prt1==prt2 && tmp>0);
    });

    g.clear(); g.push_back(h[0]);
    for(int i=1;i<h.size();i++){
        if (CrossOp(h[i],g.back())==0 && DotOp(h[i],g.back())>0) g[g.size()-1]=g[g.size()-1]+h[i];
        else g.push_back(h[i]);
    }

    /*g.clear();
    for(int i=0;i<h.size();i++) g.push_back(h[i]);*/

    int n=g.size();
    g.resize(n*2);
    for(int i=n;i<2*n;i++) g[i]=g[i-n];
    sum.resize(2*n); sum[0]=g[0]%mod;
    for(int i=1;i<2*n;i++) sum[i]=(sum[i-1]+g[i])%mod;

    int l=0,r=0;
    for(int i=0;i<n;i++){
        Point dir1=Rotate90(g[i]);
        Point dir2=Rotate90(dir1);
        while(l<i+n && (l<i || (CrossOp(g[i],g[l+1])>0 && CrossOp(g[l+1],dir1)>0))){
            l++;
        }
        while(r<i+n && (r<l || (CrossOp(g[r+1],dir2)>0 && CrossOp(g[r+1],dir1)<=0))){
            r++;
        }
        //cout<<i<<' '<<l<<' '<<r<<endl;
        sum1+=Cross(g[i],sum[r]-sum[i])%mod;
        sum1%=mod;

        sum2+=Cross(g[i],sum[r]-sum[l])%mod;
        sum2%=mod;
    }
}

LL GetAns(){
    LL ret=0;
    LL all=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if (DotOp(f[j]-f[i],f[k]-f[i])>0 &&
                    DotOp(f[i]-f[j],f[k]-f[j])>0 &&
                    DotOp(f[i]-f[k],f[j]-f[k])>0){
                        if (CrossOp(f[i]-f[j],f[k]-f[j])>0) ret+=Cross(f[i]-f[j],f[k]-f[j]);
                        else ret-=Cross(f[i]-f[j],f[k]-f[j]);
                        ret%=mod;
                    }
                if (CrossOp(f[i]-f[j],f[k]-f[j])>0) all+=Cross(f[i]-f[j],f[k]-f[j]);
                else all-=Cross(f[i]-f[j],f[k]-f[j]);
                all%=mod;
            }
        }
    }
    //cout<<all*3<<' '<<all-ret<<endl;
    if (ret<0) ret+=mod;
    return ret;
}

int main(){
    freopen("J.in","r",stdin); freopen("1.out","w",stdout);
    //default_random_engine rng(time(0));
    //uniform_int_distribution<LL> uid(-1000000000000000000,1000000000000000000);
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        //n=200;
        f.clear(); f.resize(n);
        for(int i=0;i<n;i++){
            f[i].Read();
            //f[i].x=uid(rng);
            //f[i].y=uid(rng);
        }
        LL sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            Solve(i,sum1,sum2);
        }
        //cout<<power(3,mod-2)<<endl;
        //cout<<sum1<<' '<<sum2<<endl;
        LL inv3=332748118;
        LL ans=((sum1*inv3)%mod-sum2)%mod;
        if (ans<0) ans+=mod;
        assert(0<=ans && ans<mod);
        printf("%lld\n",(long long)(ans));


        /*LL tans=GetAns();
        cout<<(long long)tans<<endl;
        if (tans!=ans){
            cout<<ans<<endl;
            cout<<tans<<endl;
            for(int i=0;i<n;i++){
                cout<<(long long)f[i].x<<' '<<(long long)f[i].y<<endl;
            }
        }*/
    }
    return 0;
}
