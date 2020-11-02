#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

map<int,int> now,mp;
multiset<int> s2;
set<int> s;

int a[SZ],nx[SZ];

int main() {
	int T = read();
	while(T --) {
		mp.clear();
		int n = read();
		for(int i = 1;i <= n;i ++) a[i] = read();
		for(int i = n;i >= 1;i --) {
			nx[i] = mp[a[i]];
			mp[a[i]] = i;
		}
		int ans = 1;
		for(int l = 1;l <= n;l ++) cout << nx[l] << " "; puts("");
		for(int l = 1;l <= n;l ++) {
			int r = l - 1;
			s.clear(); s2.clear(); now.clear();
			s.insert(n + 1); s.insert(l);
			s2.insert(n - l);
			while(233) {
				r ++;
				if(r > n || now[a[r]]) break;
				now[a[r]] = 1;
//				for(set<int> :: iterator it = s.begin();it != s.end();it ++) cout << *it << " "; puts("");
				for(int j = r;j;j = nx[j]) {
					set<int> :: iterator pre = s.upper_bound(j);
					set<int> :: iterator suf = pre; pre --;
			//		cout << *suf << " -- " << j << " -- " << *pre << endl;
					s2.erase(s2.lower_bound(*suf-*pre-1));
					s2.insert(*suf-j-1);
					s2.insert(j-*pre-1);
					s.insert(j);
				}
			//	cout << s2.size() << endl;
				//for(multiset<int> :: iterator it = s2.begin();it != s2.end();it ++)
					//cout << *it << " "; puts("");
				multiset<int> :: iterator it = s2.end(); it--;
				ans = max(ans,r - l + 1 + *it);
				cout << l << " " << r << endl;
				cout << r - l + 1 << " " << *it << " " << r-l+1+*it << endl;
				puts("----");
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/**
3
3
1 2 3
8
3 1 2 1 6 1 2 5
3
1 1 1

233
8
3 1 2 1 6 1 2 5
*/
