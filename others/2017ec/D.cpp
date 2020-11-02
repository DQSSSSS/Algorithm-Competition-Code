#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 10007;
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

LL biao[2000010];

int ws(LL x) {
	int ans = 0;
	while(x) x /= 10,ans ++;
	return ans;
}

LL mi[20],p,q;

void dfs(LL now,int d,LL lst) {
	if(d >= 3) {
		biao[++biao[0]] = now;
	}
	if(now % q) return ;
	LL nx = lst / q * p,x = ws(now),y = ws(nx);
	if(x+y > 15) return ;
	//cout << now << " " << now*mi[ws(nx)]+nx <<" " << d<< endl;
	dfs(now*mi[y]+nx,d+1,nx);
}

int main() {
	mi[0] = 1;
	for(int i = 1;i <= 18;i ++) mi[i] = mi[i - 1] * 10;
	for(LL k = 1;k <= 1e5;k ++) {
		for(q = 1;k * q * q <= 1e5;q ++) {
			int x = ws(k * q * q);
			for(p = q + 1;x+ws(k*p*q)+ws(k*p*p)<= 15;p ++) {
				if(__gcd(p,q) > 1) continue;
				//cout << k*q*q << " " << p << "/" << q << endl;
				dfs(k*q*q,1,k*q*q);
			}
		}
	}
	sort(biao + 1,biao + 1 + biao[0]);
	//cout << biao[0] << endl;
	//for(int i = 1;i <= 100;i ++) cout << i << " " << biao[i] << endl;
	int T = read(),cc = 0;
	while(T --) {
		LL l = read(),r = read();
		int R = lower_bound(biao + 1,biao + 1 + biao[0],r + 1) - biao - 1;
		int L = lower_bound(biao + 1,biao + 1 + biao[0],l) - biao - 1;
		printf("Case #%d: %d\n",++ cc,R - L);
	}
	return 0;
}
