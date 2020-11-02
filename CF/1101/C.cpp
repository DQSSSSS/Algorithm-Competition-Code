#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 8e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

struct haha {
    int l,r,id,b;
}a[SZ];

bool cmpr(haha a,haha b) {  return a.r < b.r;}
bool cmpid(haha a,haha b) {  return a.id < b.id;}

int Add[SZ];
int Del[SZ];
int lsh[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        lsh[0] = 0;
        for(int i = 1;i <= n;i ++) {
            a[i].l = read();
            a[i].r = read();
            a[i].id = i;
            lsh[++ lsh[0]] = a[i].l;
            lsh[++ lsh[0]] = a[i].r;
        }
        sort(lsh+1,lsh+1+lsh[0]);
        lsh[0]=unique(lsh+1,lsh+1+lsh[0])-lsh-1;

        for(int i = 1;i <= lsh[0];i ++) Add[i] = Del[i] = 0;
        for(int i = 1;i <= n;i ++) {
            a[i].l = lower_bound(lsh+1,lsh+1+lsh[0],a[i].l)-lsh;
            a[i].r = lower_bound(lsh+1,lsh+1+lsh[0],a[i].r)-lsh;
            Add[a[i].l] ++;
            Del[a[i].r] ++;
        }

        int sum = 0,p = -1;
        for(int i = 1;i <= lsh[0];i ++) {
            sum += Add[i];
            sum -= Del[i];
            if(sum == 0) { p = i; break; }
        }

        if(p == lsh[0]) puts("-1");
        else {
            for(int i = 1;i <= n;i ++)
                if(a[i].r <= p) a[i].b = 1;
                else a[i].b = 2;
            for(int i = 1;i <= n;i ++) printf("%d ",a[i].b); puts("");
        }
    }
}
