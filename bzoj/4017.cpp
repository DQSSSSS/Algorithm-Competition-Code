#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
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

void print(int x) {
	for(int i = 22;i >= 0;i --) printf("%d",x >> i & 1);
}

int n,a[SZ];

LL work1() {
	LL b[33][2];
	memset(b,0,sizeof b);
	LL x = 0;
	for(int i = 0;i <= n;i ++) {
		x ^= a[i];
		for(int j = 0;j <= 22;j ++)
			b[j][x >> j & 1] ++;
	}
	LL ans = 0;
	for(int i = 0;i <= 22;i ++)
		(ans += (1 << i) * b[i][0] % mod * b[i][1] % mod) %= mod;
	return ans;
}

int bits[SZ];

void Add(int x,int d,int n) {
	for(int i = x;i <= n;i += i & -i) bits[i] += d;
}

int Ask(int x,int n) {
	int ans = 0;
	for(int i = x;i > 0;i -= i & -i) ans += bits[i];
	return ans;
}

LL lsh[SZ];

LL work2() {
	LL ans = 0;
	for(LL j = 0;j <= 38;j ++) {
		lsh[0] = 0;
		LL S = (1ll << j) - 1ll;
		LL sum = 0;
		for(int i = 0;i <= n;i ++) {
			sum += a[i];
			LL x = sum & S;
			lsh[++ lsh[0]] = x;
			lsh[++ lsh[0]] = x | (1ll << j);
		}
		sort(lsh + 1,lsh + 1 + lsh[0]);
		lsh[0] = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;
		sum = 0;
		LL t = 0;
		for(int i = 1;i <= lsh[0];i ++) bits[i] = 0;
		for(int i = 0;i <= n;i ++) {
			sum += a[i];
			LL x = sum & S;
			LL l = lower_bound(lsh + 1,lsh + 1 + lsh[0],x) - lsh;
			LL r = lower_bound(lsh + 1,lsh + 1 + lsh[0],x | (1ll << j)) - lsh;
			if(sum >> j & 1) {
				t ^= (Ask(l,lsh[0]) + i - Ask(r,lsh[0])) & 1;
				Add(r,1,lsh[0]);
			}
			else {
				t ^= (Ask(r,lsh[0]) - Ask(l,lsh[0])) & 1;
				Add(l,1,lsh[0]);
			}
		}	
		if(t) ans |= 1ll << j;
	}
	return ans;
}

LL baoli1() {
	LL ans = 0;
	for(int i = 1;i <= n;i ++) {
		LL x = 0;
		for(int j = i;j <= n;j ++) {
			x ^= a[j];
			(ans += x) %= mod;
		}
	}
	return ans;
}

LL baoli2() {
	LL ans = 0;
	for(int i = 1;i <= n;i ++) {
		LL x = 0;
		for(int j = i;j <= n;j ++) {
			x += a[j];
			ans ^= x;
		}
	}
	return ans;
}

int main() {
	n = read();
	for(int i = 1;i <= n;i ++) a[i] = read();
	printf("%lld %lld\n",work1(),work2());
	return 0;
}
	
