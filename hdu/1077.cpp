#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

LD pf(LD x) { return x * x; }


struct haha {
	LD x,y;
	haha operator -(const haha &o) const { return (haha){x-o.x,y-o.y}; }
	haha operator +(const haha &o) const { return (haha){x+o.x,y+o.y}; }
	LD operator *(const haha &o) const { return x*o.y-y*o.x; }
	LD length() { return sqrt(pf(x)+pf(y)); }
}a[2010];

const haha ckd = (haha){1000,5.16473};

LD ask_dist(haha a,haha b) {
	return sqrt(pf(a.x - b.x) + pf(a.y - b.y));
}


LD ask_angle(haha a,haha b) {
	haha p = b - a;
//	cout << l1 * l2 / l1.length() / l2.length() << endl;
	//cout << p.x << " " << p.y << endl;
	LD ans = atan(p.y / p.x);
	if(p.x < 0 && p.y < 0) ans -= PI;
	if(p.x < 0 && p.y > 0) ans += PI;
	return ans;
}

LD lsh[SZ];
int t[SZ];

int main() {
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int n,T = read();
	while(T --) {
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++) {
			double x,y;
			scanf("%lf%lf",&x,&y);
			a[i].x = x; a[i].y = y;
		}
		//cout << ask_angle(a[6],a[2]) << endl;
		int ans = 1;
		for(int k = 1;k <= n;k ++) {
			LD nowx = a[k].x,nowy = a[k].y;
			int tot = 0;
			for(int i = 1;i <= n;i ++) {
				if(i == k) continue;
				LD dist = ask_dist(a[k],a[i]);
				if(dist >= 2) continue;
				LD phi = acos(dist / 2);
				LD alpha = ask_angle(a[k],a[i]);
				LD l = alpha - phi;
				LD r = alpha + phi;
				if(l < -PI && r < -PI) l += 2 * PI,r += 2 * PI;
				else if(l < -PI) l += 2 * PI;
				else if(r > PI) r -= 2 * PI;
				lsh[++ tot] = l;
				lsh[++ tot] = r;
			}
			sort(lsh + 1,lsh + 1 + tot);
			int len = unique(lsh + 1,lsh + 1 + tot) - lsh - 1;
			for(int i = 1;i <= len;i ++) t[i] = 0;
			for(int i = 1;i <= n;i ++) {
				if(i == k) continue;
				LD dist = ask_dist(a[k],a[i]);
				if(dist >= 2) continue;
				LD phi = acos(dist / 2);
				LD alpha = ask_angle(a[k],a[i]);
				LD l = alpha - phi;
				LD r = alpha + phi;
			//	cout << alpha << " " << phi << endl;
				if(l < -PI && r < -PI) l += 2 * PI,r += 2 * PI;
			//	cout << k << " " << i << " " << l << " " << r << endl;;
				if(l < -PI) {
					l += 2 * PI;
			//		cout << l << " " << r << endl;
					int id = lower_bound(lsh + 1,lsh + 1 + len,l) - lsh;
					int idr = lower_bound(lsh + 1,lsh + 1 + len,r) - lsh;
					t[id] ++; t[1] ++; t[idr + 1] --;
				}
				else if(r > PI) {
					r -= 2 * PI;
			//							cout << l << " " << r << endl;

					int id = lower_bound(lsh + 1,lsh + 1 + len,l) - lsh;
					int idr = lower_bound(lsh + 1,lsh + 1 + len,r) - lsh;
					t[id] ++; t[1] ++; t[idr + 1] --;
				}
				else {
				//					cout << l << " " << r << endl;

					int id = lower_bound(lsh + 1,lsh + 1 + len,l) - lsh;
					int idr = lower_bound(lsh + 1,lsh + 1 + len,r) - lsh;
					t[id] ++; t[idr + 1] --;
				}
			}
			for(int i = 1;i <= len;i ++) t[i] += t[i - 1],ans = max(ans,t[i] + 1);
			//for(int i = 1;i <= len;i ++) cout << lsh[i] << " "; puts("");
			//for(int i = 1;i <= len;i ++) cout << t[i] << " "; puts("");
		//	puts("");
		}
		printf("%d\n",ans);
	}
	return 0;
}
/***

0.231428 0.304977 1.03001 1.15694 1.70357 1.7493 1.8978 5.8646 6.17169 6.1825
  4		   5		5		4		3		2		1		1	  2		3

*/
