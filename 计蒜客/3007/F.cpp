#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int a[SZ];

int baoli(int n,int m) {
    static int b[SZ];
    for(int i = 1;i <= n;i ++) b[i] = a[i];
    while(m --) {
        int maxans = 0,id = 0;
        for(int i = 1;i <= n;i ++){
            if(b[i] > maxans) maxans = b[i],id = i;
        }
        b[id] --;
        int minans = 1e9; id = 0;
        for(int i = 1;i <= n;i ++){
            if(b[i] < minans) minans = b[i],id = i;
        }
        b[id] ++;
    }
    int maxans = 0,id = 0;
    for(int i = 1;i <= n;i ++){
        if(b[i] > maxans) maxans = b[i],id = i;
    }
    int minans = 1e9; id = 0;
    for(int i = 1;i <= n;i ++){
        if(b[i] < minans) minans = b[i],id = i;
    }
   // for(int i = 1;i <= n;i ++) printf("%d ",b[i]); puts("");
    return maxans - minans;
}

mt19937 rd(time(0));

int randlr(int l,int r) {
    return rd() % (r-l+1) + l;
}

int main() {
    int n,m;
    while(~scanf("%d%d",&n,&m)) {
    //while(1) {        n = randlr(1,10); m = randlr(1,1000);
        for(int i = 1;i <= n;i ++) {
            a[i] = read();
            //a[i] = randlr(1,1000);
        }
        int minans,maxans;
        int l,r;
        l = 0,r = 1e9+1;
        while(r-l>1) {
            int mid = l + r >> 1;
            LL sum = 0;
            for(int i = 1;i <= n;i ++) {
                if(a[i] <= mid) sum += mid - a[i];
            }
            if(sum > m) r = mid;
            else l = mid;
        }
        minans = l;
        l = 0,r = 1e9+1;
        while(r-l>1) {
            int mid = l + r >> 1;
            LL sum = 0;
            for(int i = 1;i <= n;i ++) {
                if(a[i] >= mid) sum += a[i] - mid;
            }
            if(sum > m) l = mid;
            else r = mid;
        }
        maxans = r;
        int ans;
        if(minans >= maxans) {
            LL sum = 0;
            for(int i = 1;i <= n;i ++) sum += a[i];
            if(sum % n == 0) ans = 0;
            else ans = 1;
        }
        else
            ans = maxans - minans;
        printf("%d\n",ans);
        /*int bl = baoli(n,m);
        if(ans != bl) {
            printf("%d %d\n",n,m);
            for(int i = 1;i <= n;i ++) printf("%d ",a[i]);
            puts("");
            printf("%d\n%d\n",ans,bl);
            return 0;
        }*/
    }
}
/**
10 925
32 482 404 829 219 518 119 292 151 426
*/
