#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;
const LD PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int n;

void manacher(const char s[],int r[]) {
	int mid = 0,maxr = 0;
	for(int i = 1;i <= n;i ++) {
		int h;
		if(mid + maxr - 1 >= i) h = min(mid + maxr - i,r[2 * mid - i]);
		else h = 1;
		while(i - h >= 1 && i + h <= n && s[i - h] == s[i + h]) h ++;
		r[i] = h;
		if(i + h > maxr) maxr = h,mid = i;
	}
}	

int bits[SZ],len;

LL Ask(int x) {
	LL ans = 0;
	for(int i = x;i <= len;i += i & -i)
		ans += bits[i];
	return ans;
}

void Add(int x,int d) {
	for(int i = x;i > 0;i -= i & -i)
		bits[i] += d;
}

int a[SZ];
char s[SZ];

struct haha {
	int x,val,c;
}ask[SZ * 2];

bool cmp(haha a,haha b) { return a.x < b.x; }

int lsh[SZ * 2],val[SZ];

int main() {
	int T = read();
	while(T --) {
		scanf("%s",s + 1);
		n = strlen(s + 1);
		manacher(s,a);
		lsh[0] = 0;
		
		for(int i = 1;i <= n;i ++) {
			val[i] = a[i] + i;
			lsh[++ lsh[0]] = val[i];
			lsh[++ lsh[0]] = i + 1;
		}
		sort(lsh + 1,lsh + 1 + lsh[0]);
		len = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;
		for(int i = 1;i <= len;i ++) bits[i] = 0;
		for(int i = 1;i <= n;i ++) 
			val[i] = lower_bound(lsh + 1,lsh + 1 + len,val[i]) - lsh;
		int tot = 0;
		for(int i = 2;i <= n;i ++) {
			int v = lower_bound(lsh + 1,lsh + 1 + len,i + 1) - lsh;
			ask[++ tot] = (haha){i - 1,v,1};
			ask[++ tot] = (haha){i - a[i],v,-1};
		}
		sort(ask + 1,ask + 1 + tot,cmp);
		LL ans = 0;
		for(int i = 1,j = 1;i <= tot;i ++) {
			while(j <= ask[i].x) {
				Add(val[j],1); j ++;
			}
			ans += Ask(ask[i].val) * ask[i].c;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
