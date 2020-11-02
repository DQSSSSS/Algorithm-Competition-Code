#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;

int read() {
    int n;
    scanf("%d",&n);
	return n;
}

LL Div(int n,int m,int k) {
    int l = 0,r = m+1;
    while(r-l>1) {
        int mid = l + r >> 1;
        if(m/mid+k <= n) r = mid;
        else l = mid;
    }
    return r;
}

mt19937 rd(time(0));

int randlr(int l,int r) { return rd()%(r-l+1)+l; }

LL work(int n,int m,int k) {
   // puts("------------");
    int t1 = 0;
    LL ans = (m+1)*k;
    for(LL b = Div(n,m,k),r;b <= m;b = r + 1) {
        r = m / (m / b);
        LL c = m / b + k;
        if(b*c < ans) {
            ans = b * c;
           // ans = min(ans,b * c);
        //    printf("%lld %lld %lld\n",b,c,b*c);
        }
        t1 ++;
        if(t1 >= randlr(7500,15000)) break;
    }
    return ans;
}

int main(){
    /*for(int n = 50;n <= 100;n ++) {
        for(int m = 0;m <= 100;m ++) {
            for(int k = 1;k <= n;k ++) {
                work(n,m,k);
            }
        }
    }*/
    int T = read();
    while(T --) {
        int n = read(),m = read(),k = read();
        printf("%lld\n",work(n,m,k));
    }
}
/**
158 486 5
504
*/
