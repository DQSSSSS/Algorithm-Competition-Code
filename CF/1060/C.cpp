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

pii la[SZ],lb[SZ];
priority_queue<LL> q;
int a[SZ],b[SZ];

int main() {
	int n = read(),m = read();
	for(int i = 1;i <= n;i ++) a[i] = read();
	for(int i = 1;i <= m;i ++) b[i] = read();
	LL x = read();
	int ta = 0,tb = 0;
	for(int i = 1;i <= n;i ++) {
		LL x = 0;
		for(int j = i;j <= n;j ++) {
			x += a[j];
			la[++ ta] = make_pair(x,j-i+1);
		}
	}
	
	for(int i = 1;i <= m;i ++) {
		LL x = 0;
		for(int j = i;j <= m;j ++) {
			x += b[j];
			lb[++ tb] = make_pair(x,j-i+1);
		}
	}
	
	sort(la + 1,la + 1 + ta);
	sort(lb + 1,lb + 1 + tb);
	/*
	for(int i = 1;i <= ta;i ++) cout << la[i].first << " " << la[i].second << endl;
	
	puts("");
	for(int i = 1;i <= tb;i ++) cout << lb[i].first << " " << lb[i].second << endl;
	*/
	LL ans = 0,maxb = 0;
	for(int i = ta,j = 1;i >= 1;i --) {
		while(j <= tb && la[i].first * lb[j].first <= x) {
			q.push(lb[j].second);
			j ++;
		}
		if(q.size()) {
			ans = max(ans,la[i].second * q.top());
		}
	}
	cout << ans << endl;
	return 0;
}
