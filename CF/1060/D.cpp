#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 4000010;
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

int n;
/*
bool check(LL mid) {
	LL t = a[1].first,lst = 0,now = 0;
	for(int i = 1;i <= n;i ++) {
		
	}
}
*/

//pii a[SZ];
bool cmp(pii a,pii b) { return a.first + a.second > b.first + b.second; }

LL a[SZ],b[SZ];

int main() {
	n = read();
	for(int i = 1;i <= n;i ++) {
		int x = read(),y = read();
		a[i] = x;
		b[i] = y;
	}
	sort(a + 1,a + 1 + n);
	sort(b + 1,b + 1 + n);
	/*LL l = 1,r = 1e15;
	while(r - l > 1) {
		LL mid = l + r >> 1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout << l << endl;*/
	LL ans = 0;
	for(int i = 1;i <= n;i ++) ans += max(a[i],b[i]);
	cout << ans + n << endl;
	return 0;
}	
