#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1100010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;
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


LL n,a[SZ],c[SZ],tot = 0,sum[SZ],sum2[SZ],ans[SZ];

bool cmp(int a,int b) { return a > b; }

int check(LL d) {
	int t = 1;
	for(int i = 1,f = 0;i < n;) {
		if(c[i] > d) a[t ++] = c[i],i++;
		else {
			if(!f) a[t ++] = d,f = 1;
			else a[t ++] = c[i],i++;
		}
	}
	if(t == n) a[t ++] = d;
	for(int i = 1;i <= n;i ++) sum[i] = sum[i - 1] + a[i];
	for(int i = 1;i <= n;i ++) sum[i] -= 1ll*(i-1) * i;
	for(int i = 1,j = n;i <= n;i ++) {
		while(j > i && a[j] < i) j --;
//		cout << i << " " << j << endl;
		sum2[i] = sum2[i - 1] - min(i-1ll,a[i]) + max(j-i,0);
	}
	//for(int i = 1;i < n;i ++) cout << c[i] << " "; puts("");
	//for(int i = 1;i <= n;i ++) cout << a[i] << " "; puts("");
	//for(int i = 1;i <= n;i ++) cout << sum[i] << " " << sum2[i],puts("");
	//for(int i = 1;i <= n;i ++) cout << sum[i] << " " << sum2[i] << " " << i << " " << a[i],puts("");
	//for(int i = 1;i <= n;i ++) cout << sum2[i] << " "; puts("");
	int tt = 0;
	for(int i = 1;i <= n;i ++) {	
		if(sum[i] > sum2[i]) {
			if(d < a[i]) return -1;
			else return 1;
		}
		//cout << x << " " << y << endl;
	}
	return 0;
}

int divR() {
	int l = 1,r = tot + 1;
	while(r - l > 1) {
		int mid = l + r >> 1;
		if(check(ans[mid])<=0) l = mid;
		else r = mid; 
	}
	return l;
}

int divL() {
	int l = 0,r = tot;
	while(r - l > 1) {
		int mid = l + r >> 1;
		if(check(ans[mid])>=0) r = mid;
		else l = mid; 
	}
	return r;
}

int main() {
	n = read();
	LL b = 0;
	for(LL i = 1;i <= n;i ++) {
		c[i] = read();
		b += c[i];
	}
	sort(c + 1,c + 1 + n,cmp);
	for(int d = b % 2;d <= n;d += 2) ans[++ tot] = d;
	n ++;
	//cout << check(2);
	int l = divL(),r = divR();
	//cout << l << " " << r << endl;
	for(int i = l;i <= r;i ++) printf("%d ",ans[i]);
	if(l > r) puts("-1");
	return 0;
}


