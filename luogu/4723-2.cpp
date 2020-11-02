#include<bits/stdc++.h>
#define For(i,a,b) for(i=(a);i<=(b);++i)
#define Forward(i,a,b) for(i=(a);i>=(b);--i)
#define Rep(i,a,b) for(register int i=(a),i##end=(b);i<=i##end;++i)
#define Repe(i,a,b) for(register int i=(a),i##end=(b);i>=i##end;--i)
#define Chkmin(a,b) a=a<b?a:b
using namespace std;
template<typename T>inline void read(T &x){
    T s=0,f=1;char k=getchar();
    while(!isdigit(k)&&k^'-')k=getchar();
    if(!isdigit(k)){f=-1;k=getchar();}
    while(isdigit(k)){s=s*10+(k^48);k=getchar();}
    x=s*f;
}
void file(void){
    freopen("polynomial.in","r",stdin);
    freopen("polynomial.out","w",stdout);
}
const int MAXN=1<<20;

typedef long long ll;

namespace polynomial
{
    static int mod=998244353,gen=3,g[21],rev[MAXN],Len;

    inline int ad(int a,int b){return (a+=b)>=mod?a-mod:a;}

    inline int power(int a,int b)
    {
        static int sum;
        for(sum=1;b;b>>=1,a=(ll)a*a%mod)if(b&1)
            sum=(ll)sum*a%mod;
        return sum;
    }

    inline void predone()
    {
        static int i,j;
        for(i=1,j=2;i<=19;++i,j<<=1)g[i]=power(gen,(mod-1)/j);
    }

    inline void calrev(int Len)
    {
        static int Logl;Logl=(int)floor(log(Len)/log(2)+0.3)-1;
        Rep(i,1,Len-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<Logl);
    }

    inline void NTT(int X[],int typ)
    {
        Rep(i,1,Len-1)if(i<rev[i])swap(X[i],X[rev[i]]);
        static int i,j,k,kk,w,t,wn,r;
        for(k=2,kk=1,r=1;k<=Len;k<<=1,kk<<=1,++r)
        {
            wn=g[r];
            for(i=0;i<Len;i+=k)for(j=0,w=1;j<kk;++j,w=(ll)w*wn%mod)
            {
                t=(ll)w*X[i+j+kk]%mod;
                X[i+j+kk]=ad(X[i+j],mod-t);
                X[i+j]=ad(X[i+j],t);
            }
        }
        if(typ==-1)
        {
            reverse(X+1,X+Len);
            static int invn;invn=power(Len,mod-2);
            Rep(i,0,Len-1)X[i]=(ll)X[i]*invn%mod;
        }
    }

    static int x[MAXN],y[MAXN];
    inline void mul(int a[],int b[])
    {
        memset(x,0,sizeof x);memset(y,0,sizeof y);
        Rep(i,0,(Len>>1)-1)x[i]=a[i],y[i]=b[i];
        NTT(x,1);NTT(y,1);
        Rep(i,0,Len-1)x[i]=(ll)x[i]*y[i]%mod;
        NTT(x,-1);
        Rep(i,0,Len-1)a[i]=x[i];
    }

    static int A[MAXN],B[MAXN];

    void Inv(int *a,int *b,int n)
    {
        if(n==1){b[0]=power(a[0],mod-2);return;}
        Inv(a,b,n>>1);
        Len=n<<1;
        calrev(Len);
        Rep(i,0,(Len>>1)-1)A[i]=a[i],B[i]=b[i];
        NTT(A,1);NTT(B,1);
        Rep(i,0,Len-1)B[i]=(ll)B[i]*B[i]%mod*A[i]%mod;
        NTT(B,-1);
        Rep(i,0,(Len>>1)-1)b[i]=ad(b[i],ad(b[i],mod-B[i]));
        Rep(i,0,Len)A[i]=B[i]=0;
    }

    static int X[MAXN],Y[MAXN],TT[MAXN];

    inline void Div(int *a,int n,int *b,int m)
    {
        if(n<m){Rep(i,0,m-1)b[i]=a[i];return;}
        memcpy(X,a,sizeof X);memcpy(Y,b,sizeof Y);
        reverse(b,b+m+1);reverse(X,X+n+1);
        Rep(i,n-m+1,n)X[i]=0;
        memset(TT,0,sizeof TT);
        for(Len=2;Len<=(n-m+1);Len<<=1);
        Inv(b,TT,Len);
        memcpy(b,TT,sizeof TT);
        while(Len<=(n<<2))Len<<=1;
        calrev(Len);
        mul(X,b);reverse(X,X+n-m+1);
        Rep(i,n-m+1,n)X[i]=0;
        mul(Y,X);
        Rep(i,0,m-1)b[i]=ad(a[i],mod-Y[i]);
        memcpy(a,X,sizeof X);
    }
}
using namespace polynomial;

static int n,F[MAXN],G[MAXN],m,AA[MAXN],KK[MAXN];

static int R[MAXN];

inline void MMM(int *A,int *B,int *Mo,int lp)
{
    Chkmin(lp,m<<1);
    calrev(Len);mul(A,B);
    cout << Len << endl;
    memcpy(R,Mo,sizeof R);
    Div(A,lp,R,m);
    Rep(i,m,m<<1)A[i]=0;
    Rep(i,0,m-1)A[i]=R[i];
}

inline void KSM(int *A,int x,int *B,int *Mo)
{
    for(int i=1;x;x>>=1,++i)
    {
        if(x&1) {
            printf("------------------%d----------------\n",x);
            for(int k = 0;k < m*2;k ++) printf("%d ",B[k]); puts("");
            for(int k = 0;k < m*2;k ++) printf("%d ",A[k]); puts("");
            for(int k = 0;k < m*2;k ++) printf("%d ",Mo[k]); puts("");
            MMM(B,A,Mo,m<<1);
            for(int k = 0;k < m*2;k ++) printf("%d ",B[k]); puts("");
        }
        printf("------------------%d----------------\n",x);
        for(int k = 0;k < m*2;k ++) printf("%d ",A[k]); puts("");
        for(int k = 0;k < m*2;k ++) printf("%d ",A[k]); puts("");
        for(int k = 0;k < m*2;k ++) printf("%d ",Mo[k]); puts("");
        MMM(A,A,Mo,m<<1);
        for(int k = 0;k < m*2;k ++) printf("%d ",A[k]); puts("");
    }
}

/**
6 4
3 -1 0 4
-2 3 1 5
------------------6----------------
0 1 0 0 0 0 0 0
0 1 0 0 0 0 0 0
998244349 0 1 998244350 1 0 0 0
0 0 1 0 0 0 0 0
------------------3----------------
1 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0
998244349 0 1 998244350 1 0 0 0
0 0 1 0 0 0 0 0
------------------3----------------
0 0 1 0 0 0 0 0
0 0 1 0 0 0 0 0
998244349 0 1 998244350 1 0 0 0
4 0 998244352 3 0 0 0 0
------------------1----------------
0 0 1 0 0 0 0 0
4 0 998244352 3 0 0 0 0
998244349 0 1 998244350 1 0 0 0
32 12 998244349 21 0 0 0 0
------------------1----------------
4 0 998244352 3 0 0 0 0
4 0 998244352 3 0 0 0 0
998244349 0 1 998244350 1 0 0 0
236 84 998244326 168 0 0 0 0
*/

int main(void){
//    file();
freopen("testdata (4).in","r",stdin);
    predone();
    read(n);read(m);
    for(Len=2;Len<=(m<<1);Len<<=1);
    Rep(i,1,m)read(F[m-i]),F[m-i]=ad(0,mod-F[m-i]);
    F[m]=1;
    Rep(i,0,m-1)read(AA[i]),AA[i]=ad(AA[i],mod);
    G[1]=1;KK[0]=1;
    KSM(G,n,KK,F);
    static int ans=0;
    Rep(i,0,m-1)ans=ad(ans,(ll)AA[i]*KK[i]%mod);
    cout<<ans<<endl;
//  cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
