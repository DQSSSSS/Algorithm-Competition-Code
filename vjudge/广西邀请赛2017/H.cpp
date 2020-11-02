#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 3e5 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    scanf("%lld",&n);
    return n;
}

LL ksm(LL a,LL b,LL p) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % p;
        a = a *a % p;
        b >>= 1;
    }
    return ans;
}

int work(int N,int a) {
    if(a&1) return 1;
    int A = a,n = 0;
    while(A%2==0) A/=2,n++;
    //cout << n << endl;
    int ans = 0;
    for(int b = 1;n * b < N;b ++) {
        if(ksm(a,b,1ll<<N) == ksm(b,a,1ll<<N)) ans ++;
    }
    //cout << ans << endl;
    for(int m = 0;m <= N;m ++) {
        if(1ll*m*a>=N) {
            LL l = (N+(n*(1ll<<m))-1) / (n*(1ll<<m));
            LL r = 1ll<<(N-m);
            //cout << m << " " << l << " " << r << endl;
            if(l>r) continue;
            l --;
            ans += (r+1)/2-(l+1)/2;
        }
    }
    return ans;
}

int baoli(int N,int a) {
    int ans = 0;
    for(int b = 1;b <= (1<<N);b ++) {
        if(ksm(a,b,1<<N) == ksm(b,a,1<<N)) {
            ans ++;
        }
    }
    return ans;
}

int main(){
    int n,a;
    while(~scanf("%d%d",&n,&a)) {
        printf("%d\n",work(n,a));
    }
}


/*
30 1000000000
536870911
*/
