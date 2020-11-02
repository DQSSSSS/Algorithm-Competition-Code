#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2500 + 5;
const ll mod = 1e9 + 7;
map<ll, ll> mmp[N];
int n;
string s;
string op[N];
ll id[N], x[N], y[N];
ll L[N];
ll dfs(int p, ll len) {
	ll res = 0;
	if(op[p] == "SUB") {
        res = dfs(id[p], x[p] + len - 1) - dfs(id[p], x[p] - 1);
	}
	else {
        res = dfs(id[x[p]], min(L[x[p]], len)) + dfs(id[y[p]], len - L[x[p]]);
	}
	res = (res % mod + mod) % mod;
	// cout << p << " " << len << " " << res << endl;
	return mmp[p][len] = res;
}

ll sum[N*N];
map<pii,int> subid;
int main() {
	cin >> n >> s;
	int tot = 0;
	for(int i = 1; i <= s.size(); i++) {
        ll t = 0;
		for(int j = i;j <= s.size();j ++) {
            tot ++;
            t += s[j-1];
            sum[tot] = t;
            subid[make_pair(i,j)] = tot;
		}
	}
	for(int i = 1 + tot; i < n + tot; i++) {
		cin >> op[i];
		if(op[i] == "SUB") {
			cin >> id[i] >> x[i] >> y[i];
			x[i] ++; y[i] ++;
			if(id[i] == 0) {
                ch[i][0] = subid[make_pair(x[i],y[i])];
			}
			else {
                ch[]
			}
		}
		else {
			cin >> x[i] >> y[i];
			L[i] = L[x[i]] + L[y[i]];
		}
	}
	cout << dfs(n - 1 + tot) << endl;
	return 0;
}
