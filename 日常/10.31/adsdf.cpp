#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod=1e9+7;

LL frac(LL a){
    if (a==1) return 1;
    return ((-(mod/a)*(frac(mod%a)))%mod+mod)%mod;
}

LL fac[200010],inv[200010];

LL C(LL n,LL m){
    LL ans = ((fac[n] * inv[m] % mod) * inv[n - m]) % mod;
    //cout<<n<<" " << m <<endl;
    return ans;
}

int main(){
    LL h,w,a,b;
    cin>>h>>w>>a>>b;
    fac[0] = 1;
    for(int i = 1;i <= 200000;i ++) fac[i] = (LL)fac[i - 1] * i % mod;
    //inv[0]=inv[1]=1;
    //for(int i=2;i<=100000;i++)
    //    inv[i]=((-(mod/a)*(inv[mod%a]))%mod+mod)%mod;
    inv[200000] = frac(fac[200000]); inv[0] = 1;
    for(int i = 200000 - 1;i >= 1;i --) inv[i] = (LL)inv[i + 1] * (i + 1) % mod;
    LL ans=C(h+w-2,h-1);
    for(int i=1;i<=b;i++){
        //cout<<C(h-a+i-2,h-a-1)<< " " << C(w-i+a-2,a-1)<<endl;
        ans=((ans-(C(h-a+i-2,h-a-1)*C(w-i+1+a-2,a-1)%mod))%mod+mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
