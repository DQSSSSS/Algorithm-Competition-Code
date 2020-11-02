#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 6e5 + 10;
int T, n, m, sz;
long long ca[N], ta[N], cb[N], tb[N];
 
struct point {
	long long r, add;
	long long odd, even;
	point() {}
	point(long long r, long long odd, long long even, long long add) :r(r), odd(odd), even(even), add(add) {}
	bool operator<(const point a) {
		return r == a.r ? add > a.add : r < a.r;
	}
}g[N];
 
int main() {
	for (scanf("%d", &T); T--;) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld", &ca[i], &ta[i]);
		}
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) {
			scanf("%lld%lld", &cb[i], &tb[i]);
		}
		sz = 0;
		g[sz++] = point(0, 1, 1, 1);
		g[sz++] = point(1, 1, 1, -1);
		for (long long c = 0, i = 1, j = 1; i <= n && j <= m;) {
			long long tc = min(ta[i], tb[j]);
 
			long long l = c, r = c;
			if (ca[i] == cb[j]) {
				int flag = l % 2 ? 1 : 0;
				g[sz++] = point(l, flag, !flag, tc);
				g[sz++] = point(r + 1, flag, !flag, -tc);
			}
			else {
				if (ca[i] == 0) {
					if (cb[j] == 1) l -= tc, c -= tc, r--;
					else r += tc, c += tc, l++;
 
					int flag = l % 2 ? 1 : 0;
					g[sz++] = point(l, flag, !flag, 1);
					g[sz++] = point(l + 1, !flag, flag, 1);
					g[sz++] = point(r + 1, 1, 1, -1);
				}
				else if (cb[j] == 0) {
					if (ca[i] == 1) r += tc, c += tc, l++;
					else l -= tc, c -= tc, r--;
 
					int flag = l % 2 ? 1 : 0;
					g[sz++] = point(l, flag, !flag, 1);
					g[sz++] = point(l + 1, !flag, flag, 1);
					g[sz++] = point(r + 1, 1, 1, -1);
				}
				else {
					if (ca[i] == 1) r += tc + tc, c += tc + tc, l += 2;
					else l -= tc + tc, c -= tc + tc, r -= 2;
					int flag = l % 2 ? 1 : 0;
					g[sz++] = point(l, flag,  !flag, 1);
					g[sz++] = point(r + 1, flag, !flag, -1);//.
				}
			}
 
			if (!(ta[i] -= tc)) i++; 
			if (!(tb[j] -= tc)) j++;
		}
		sort(g, g + sz);
		long long odd = 0, even = 0, ans = 0;
		for (int i = 0, j = 0; i < sz; i = j) {
			for (j = i; j < sz && g[i].r == g[j].r; j++) {
				odd += g[j].odd * g[j].add;
				even += g[j].even * g[j].add;
			}
			ans = max(ans, max(odd, even));
		}
		printf("%lld\n", ans);
	}
	return 0;
}
