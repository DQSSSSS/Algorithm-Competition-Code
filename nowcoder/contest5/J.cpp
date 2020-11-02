#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
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

int main() {
	LL n = read(),p2 = read(),p3 = read();
	LL ans = 1e18;
   	for(LL i = 0;i <= 3;i ++) {
    	LL r2 = i,rst = n - i * 2,r3 = rst / 3;
    	if(rst < 0) continue;
    	LL t1 = r2 * p2 + r3 * p3 + ((rst % 3) ? p2 : 0);
    	LL t2 = r2 * p2 + r3 * p3 + ((rst % 3) ? p3 : 0);
    	ans = min(ans,min(t1,t2));
   	}
   	for(LL i = 0;i <= 2;i ++) {
    	LL r3 = i,rst = n - i * 3,r2 = rst / 2;
    	if(rst < 0) continue;
    	LL t1 = r2 * p2 + r3 * p3 + ((rst % 2) ? p2 : 0);
    	LL t2 = r2 * p2 + r3 * p3 + ((rst % 2) ? p3 : 0);
    	ans = min(ans,min(t1,t2));
   	}
	cout << ans << endl;
	return 0;
}
