#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = uint64_t;

using namespace std;
const int MAXN = 2e6 + 100;

string s, t;

string tmp;
int z[MAXN];
int go[MAXN];
int pl[MAXN];
int ad[MAXN];

void zf(const string &s, int *z) {
	int l = 0, r = 0;
	z[0] = 0;
	for (int i = 1; i < s.size(); ++i) {
		if (r > i)
			z[i] = min(r - i, z[i - l]);
		else
			z[i] = 0;
		while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] > r)
			r = i + z[i], l = i;
	}
}


int main() {
    freopen("M.in","r",stdin);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> s >> t;
	reverse(s.begin(), s.end());
	tmp = t + "#" + s;
	reverse(s.begin(), s.end());
	zf(tmp, z);
	tmp = "";
	for (int i = 0; i < s.size(); ++i) {
		tmp += s[i];
		tmp += "#";
	}
	int l = 0, r = 0;
	for (int i = 0; i < tmp.size(); ++i) {
		pl[i] = 0;
		int cur = 0;
		if (r > i)
			cur = min(r - i, pl[2 * l - i]);
		else
			cur = 1;
		while (i + 1 > cur && tmp.size() - i > cur && tmp[i - cur] == tmp[i + cur])
			++cur;
		pl[i] = cur;
		++ad[max(0, i - cur)];
		--ad[i];
		if (i + cur > r)
			r = i + cur, l = i;
	}
	int now = 0;
	for (int i = 0; i < tmp.size(); ++i) {
		now += ad[i];
		if (i % 2 == 0) {
			go[i / 2] = now - 1;
		}
	}
	ll ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		ans += ll(go[i]) * z[t.size() + 1 + s.size() - 1 - i];
	}
	cout << ans << "\n";
	return 0;
}

