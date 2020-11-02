#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

const int MAXN = 200010;
const int MAXM = MAXN;

int n, K, L, R; char ch[MAXN];

int base = 13331;
long long Hash[MAXN], Pow[MAXN];

// string is 1-base, sa is 1-base
int w[MAXM];
inline void Sort(int a[], int ret[], int n, int m = MAXM - 1) {
	for (int i = 0; i <= m; i++) w[i] = 0;
	for (int i = 1; i <= n; i++) w[a[i]]++;
	for (int i = 1; i <= m; i++) w[i] += w[i - 1];
	for (int i = n; i >= 1; i--) ret[w[a[i]]--] = i;
}
int wa[MAXN], wb[MAXN], tmp[MAXN];
inline void getSA(int ch[], int sa[], int n) {
	int *x = wa, *y = wb;
	for (int i = 1; i <= n; i++) x[i] = ch[i];
	Sort(ch, sa, n);
	for (int j = 1, p = 1, m = MAXN - 1; p < n; m = p, j <<= 1) {
		p = 0;
		for (int i = n - j + 1; i <= n; i++) y[++p] = i;
		for (int i = 1; i <= n; i++) if (sa[i] > j) y[++p] = sa[i] - j;
		for (int i = 1; i <= n; i++) tmp[i] = x[y[i]];
		Sort(tmp, sa, n, m);
		for (int i = 1; i <= n; i++) sa[i] = y[sa[i]];
		swap(x, y); x[sa[1]] = p = 1;
		for (int i = 2; i <= n; i++) {
			if (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + j] == y[sa[i - 1] + j]) x[sa[i]] = p;
			else x[sa[i]] = ++p;
		}
	}
	sa[0] = n + 1; // for calculate height.
}
int Rank[MAXN];
inline void getHeight(int ch[], int sa[], int height[], int n) {
	for (int i = 1; i <= n; i++) Rank[sa[i]] = i;
	for (int i = 1, t = 0; i <= n; i++) {
		if (t > 0) t--;
		while (ch[i + t] == ch[sa[Rank[i] - 1] + t]) t++;
		height[Rank[i]] = t;
	}
}

inline long long getHash(int l, int r) {
	return Hash[r] - Hash[l - 1] * Pow[r - l + 1];
}

int sa[MAXN], a[MAXN], height[MAXN];

pair<int, int> interval[MAXN];

inline int cmp(pair<int, int> x, pair<int, int> y) {
	if (getHash(x.first, x.second) == getHash(y.first, y.second)) return 0;
	int Lx = x.second - x.first + 1, Ly = y.second - y.first + 1;
	int l = 1, r = min(Lx, Ly);
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (getHash(x.first, x.first + mid - 1) == getHash(y.first, y.first + mid - 1)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	if (r < min(Lx, Ly)) return a[x.first + r] < a[y.first + r] ? -1 : 1;
	else return Lx < Ly ? -1 : 1;
}

pair<int, int> select(long long k) {
	long long sum = 0;
	for (int i = L; i <= R; i++) if (interval[i].first <= interval[i].second) {
		int now = interval[i].second - interval[i].first + 1;
		if (sum + now >= k) {
			long long d = k - sum;
			return make_pair(sa[i], interval[i].first + d - 1);
		}
		sum += now;
	}
	assert(false);
}

inline int check(pair<int, int> now) {
	int r = n, l = n, sum = 1;
	while (l >= 1) {
		if (cmp(make_pair(l, r), now) == 1) {
			if (l == r) return false;
			r = l;
			sum++;
		} else l--;
	}
	return sum <= K;
}

void clear(void) {
  for (int i = 0; i <= n + 10; i++) {
    sa[i] = Rank[i] = wa[i] = wb[i] = w[i] = height[i] = 0;
  }
}

int main(void) {
	Pow[0] = 1; for (int i = 1; i < MAXN; i++) Pow[i] = Pow[i - 1] * base;
	while (scanf("%d", &K) == 1) {
		scanf("%s", ch + 1);
		n = strlen(ch + 1); L = 1, R = n;
		clear();
		if (n == 1) {
			puts(ch + 1);
			continue;
		}
		for (int i = 1; i <= n; i++) a[i] = ch[i] - 'a' + 1, Hash[i] = Hash[i - 1] * base + a[i]; a[n + 1] = 0;
		getSA(a, sa, n);
		getHeight(a, sa, height, n);
		long long l = 1, r = 0;
		for (int i = 1; i <= n; i++) {
			interval[i].first = sa[i] + height[i];
			interval[i].second = n;
			r += interval[i].second - interval[i].first + 1;
		}
		while (l <= r) {
			long long mid = (l + r) >> 1;
			pair<int, int> now = select(mid);
			if (check(now)) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		pair<int, int> Ans = select(l);
		for (int i = Ans.first; i <= Ans.second; i++) putchar(a[i] + 'a' - 1); puts("");
	}
	return 0;
}

