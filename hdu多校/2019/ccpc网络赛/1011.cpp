#include<cstdio>
typedef long long ll;
ll Case,n,m,k,x,y,P,B,s[8388808],ans,i,j,T;
int C7[7][7],C17[17][17];
ll exgcd(ll a,ll b){
  if(!b)return x=1,y=0,a;
  ll d=exgcd(b,a%b),t=x;
  return x=y,y=t-a/b*y,d;
}
inline ll rev(ll a,ll P){exgcd(a,P);while(x<0)x+=P;return x%P;}
struct Num{
  ll a,b;
  Num(){a=1,b=0;}
  Num(ll _a,ll _b){a=_a,b=_b;}
  Num operator*(const Num&x)const{return Num((a*x.a)&8388607,b+x.b);}
  Num operator/(const Num&x)const{return Num((a*rev(x.a,P))&8388607,b-x.b);}
  ll val(){
    if(b>=23)return 0;
    return (a<<b)&8388607;
  }
}now;
Num cal(ll n){return n?Num(s[n&8388607],n>>1)*cal(n>>1):Num(1,0);}
void pre(){for(i=s[0]=1;i<P;i++)if(i%B)s[i]=s[i-1]*i%P;else s[i]=s[i-1];s[P]=s[P-1];}
int lucas7(int n,int m){
  if(n<m)return 0;
  if(!m||n==m)return 1;
  return C7[n%7][m%7]*lucas7(n/7,m/7)%7;
}
int lucas17(int n,int m){
  if(n<m)return 0;
  if(!m||n==m)return 1;
  return C17[n%17][m%17]*lucas17(n/17,m/17)%17;
}
inline ll po(ll a,ll b,ll P){
  ll t=1;
  for(;b;b>>=1,a=a*a%P)if(b&1)t=t*a%P;
  return t;
}
ll pool[3];
inline ll query(ll n,ll m){
  ll P=998244352;
  static ll a[3];
  static ll b[3];
  a[0]=8388608;
  a[1]=7;
  a[2]=17;
  now=cal(n)/cal(m)/cal(n-m);
  b[0]=now.val();
  b[1]=lucas7(n,m);
  b[2]=lucas17(n,m);
  ll ans=0;
  for(int i=0;i<3;i++)ans+=pool[i]*b[i];
  return (ans%P+P)%P;
}
struct FastIO{
  static const int S=1310720;
  int wpos,pos,len;char wbuf[S];
  FastIO():wpos(0){}
  inline int xchar(){
    static char buf[S];
    if(pos==len)pos=0,len=fread(buf,1,S,stdin);
    if(pos==len)return -1;
    return buf[pos++];
  }
  inline int xuint(){//-1±íÊ¾¿ÕÁË
    int c=xchar(),x=0;
    while(c<=32&&~c)c=xchar();
    if(c==-1)return -1;
    for(;'0'<=c&&c<='9';c=xchar())x=x*10+c-'0';
    return x;
  }
}io;
inline void gao(){
   int t1,t2,p,q,n,m;
   int mo=998244353;
   int sum=0;
   while(1){
     t1=io.xuint();
     if(t1==-1)break;
     t2=io.xuint();
     p=io.xuint();
     q=io.xuint();
     n=io.xuint();
     m=io.xuint();
    	ll ans = 1;
    	while (m--)
    	{
    		int x, y, v;
    		x=io.xuint();
    		y=io.xuint();
    		v=io.xuint();
    		if (x % p == 0 && y % q == 0)
    		{
    			int i = x/p, j = y/q;
    			if (i+j>n) continue;
    			ans *= po(v, 1LL*query(n,i)*query(n-i,j)%(mo-1)*po(t1, i, mo-1)%(mo-1) *po(t2, j, mo-1)%(mo-1), mo);
                ans %= mo;
                //sum++;
                //if(sum>=20000)return;
    		}
    	}
    	printf("%lld\n", ((ans % mo) + mo) % mo);
    }
}
int main(){
freopen("2.in","r",stdin);
  for(C7[0][0]=i=1;i<7;i++)for(C7[i][0]=j=1;j<=i;j++)C7[i][j]=(C7[i-1][j-1]+C7[i-1][j])%7;
  for(C17[0][0]=i=1;i<17;i++)for(C17[i][0]=j=1;j<=i;j++)C17[i][j]=(C17[i-1][j-1]+C17[i-1][j])%17;
  T=998244352;
  B=2,P=8388608;
  pre();
  pool[0]=(998244352/8388608)*rev(998244352/8388608,8388608)%998244352;
  pool[1]=(998244352/7)*rev(998244352/7,7)%998244352;
  pool[2]=(998244352/17)*rev(998244352/17,17)%998244352;
  gao();
}
