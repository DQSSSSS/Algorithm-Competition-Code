#include<bits/stdc++.h>
using namespace std;

typedef __int128 LL;
const int MAXN=1e6+10;
const int mod=1e9+7;
const double eps=1e-7;

int n;
LL m;

map<LL,int> mp;
void Init(){
    mp.clear();
    LL a=1,b=2;
    for(;a<=1e15;){
        mp[a]=1;
        a+=b;
        swap(a,b);
    }
}

LL MulMod(LL a,LL b,LL c){
    return (a*b)%c;
}

LL exgcd(LL a,LL b,LL &x,LL &y){
    if(!b) { x=1,y=0; return a; }
    LL ret=exgcd(b,a%b,x,y);
    LL t = x;
    x = y,y = t-(a/b)*y;
    return ret;
}

LL excrt(LL *r,LL *a,int n) { // x%r=a
    for(int i = 1;i <= n;i ++) {
        for(int j = i+1;j <= n;j ++) {
            LL d = __gcd(a[i],a[j]);
            if(r[i]%d!=r[j]%d) return -1;
       }
    }
    LL R = r[1], M = a[1];
    for(int i = 2;i <= n;i ++) {
        LL a2 = r[i],b2 = a[i],x,y,d;
        d = exgcd(M,b2,x,y);
        LL c = a2 - R;
       // if (c%d) return -1;
        LL k1 = c/d*x,t = b2/d;
        k1 = (k1%t+t)%t;
        R = M*k1+R;
        M = M/d*b2;
        if(R > 1e15) return -2;
    }
    return R;
}

LL f[20],g[20];
int main(){
    Init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        long long x,y;
        scanf("%lld%lld",&x,&y);
        f[i] = x;
        g[i] = y;
    }
    m=excrt(g,f,n);
    //cout<<m<<endl;
    if (m<=1 || m>1e15) puts("Tankernb!");
    else if (mp[m]==1) puts("Lbnb!");
    else puts("Lbnb!");
    return 0;
}
