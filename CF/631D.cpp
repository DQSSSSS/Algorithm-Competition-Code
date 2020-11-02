#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,char> pii;
const int SZ = 200010;
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

pii a[SZ],b[SZ];
int nxt[SZ];

int main() {
	int n = read(),m = read();
	for(int i = 1;i <= n;i ++) {
		LL x; char c[2];
		scanf("%lld-%s",&x,c);
		a[i] = make_pair(x,c[0]);
	}
	
	for(int i = 1,j = 1;i <= n;i ++) {
		LL x = 0; char c = a[j].second;
		while(j <= n && a[j].second == c) x += a[j].first,j ++;
		a[i] = make_pair(x,c);
		if(j > n) { n = i; break; }
	}
	
	for(int i = 1;i <= m;i ++) {
		LL x; char c[3];
		scanf("%lld-%s",&x,c);
		b[i] = make_pair(x,c[0]);
	}
	
	for(int i = 1,j = 1;i <= m;i ++) {
		LL x = 0; char c = b[j].second;
		while(j <= m && b[j].second == c) x += b[j].first,j ++;
		b[i] = make_pair(x,c);
		if(j > m) { m = i; break; }
	}
	
	
	
	LL ans = 0;
	
	if(m == 1) {
		for(int i = 1;i <= n;i ++)
			if(a[i].second == b[1].second)
				ans += max(0ll,a[i].first - b[1].first + 1);
	}
	else if(m == 2) {
		for(int i = 1;i <= n - 1;i ++)
			if(a[i].second == b[1].second && a[i + 1].second == b[2].second)
				if(a[i].first >= b[1].first && a[i + 1].first >= b[2].first)
					ans ++;
	}
	else {
		pii b1 = b[1],bm = b[m];
		for(int i = 0;i < m - 2;i ++) b[i] = b[i + 2];
		for(int i = 0;i < n;i ++) a[i] = a[i + 1];
		m -= 2;
		a[n] = make_pair(0,0);
		b[m] = make_pair(0,0);
		
		nxt[0] = nxt[1] = 0;
		for(int i = 1;i < m;i ++) {
			int j = nxt[i];
			while(j && b[j] != b[i]) j = nxt[j];
			nxt[i + 1] = b[i] == b[j] ? j + 1 : 0;
		}
		
		for(int i = 0,j = 0;i < n;i ++) {
			while(j && b[j] != a[i]) j = nxt[j];
			if(b[j] == a[i]) j ++;
			if(j == m) {
				if(i >= m && i < n - 1) {
					if(a[i - m].second == b1.second && a[i + 1].second == bm.second)
						if(a[i - m].first >= b1.first && a[i + 1].first >= bm.first)
							ans ++;
				}
			}
		}
	}
	cout << ans << endl;
	//for(int i = 0;i <= n;i ++) cout << a[i].first << "-" << a[i].second << " "; puts("");
	//for(int i = 0;i <= m;i ++) cout << b[i].first << "-" << b[i].second << " "; puts("");
	return 0;
}
