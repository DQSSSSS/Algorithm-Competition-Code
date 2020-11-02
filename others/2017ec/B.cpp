#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2e5 + 10;

double avg;
int a[SZ];

struct haha {
	int x;
	int d;
	haha(int x = 0,int d = 0):x(x),d(d) {}
};

bool operator <(haha a,haha b) { 
	return 1llu * a.x * a.x * b.d * (b.d + 1) < 1llu * b.x * b.x * a.d * (a.d + 1);
}
priority_queue<haha> q;

int main() {
	int T,cc = 0;
	scanf("%d",&T);
	while(T --) {
		int n,m;
		scanf("%d%d",&n,&m);
		int mm = m;
		avg = 0;
		for(int i = 1;i <= n;i ++) {
			scanf("%d",&a[i]);
			avg += a[i];
		}
		avg /= m;
		for(int i = 1;i <= n;i ++) {
			q.push(haha(a[i],1));
		}
		m -= n;
		while(m --) {
			haha x = q.top(); q.pop();
			x.d ++;
			q.push(x);
		}
		double ans = 0;
		while(q.size()) {
			haha x = q.top(); q.pop();
			//cout << x.x << " " << x.d << endl;
			double now = (double)x.x / x.d;
			int num = x.d;
			ans += (now - avg) * (now - avg) * num;
		}
		printf("Case #%d: %.10f\n",++ cc,ans / mm);
	}
	return 0;
}
