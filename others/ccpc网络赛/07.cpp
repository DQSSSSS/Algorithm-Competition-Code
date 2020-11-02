#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

vector<LL> pre[SZ],g[SZ];
LL a[SZ],n,s,m,k,sum[SZ];

bool vis[SZ];
deque<int> q;

LL get(vector<LL> g,int m) {
	while(q.size()) q.pop_back();
	LL ans = 0;
	for(int i = 0;i < g.size();i ++) {
        while(q.size() && g[q.back()] >= g[i]) q.pop_back();
		q.push_back(i);
        while(q.size() && q.front() < i - m) q.pop_front();
        LL d = q.size() ? g[q.front()] : 0;
        ans = max(ans,g[i] - d);
	}
	return ans;
}

int main() {
    int T = read(),cc = 0;
    while(T --) {
        n = read(),s = read(),m = read(),k = read();
        int len = __gcd(n,k);
        for(int i = 0;i < n;i ++){
        	a[i] = read();
        }
        bool allnon = 1;
		for(int i = 0;i < len;i ++) g[i].clear(),pre[i].clear(),sum[i] = 0;
		for(int i = 0;i < len;i ++) {
            for(int j = i;!vis[j];j += k,j %= n)
                g[i].push_back(a[j]),vis[j] = 1,sum[i] += a[j];
            int sz = g[i].size();
            for(int j = 0;j < sz;j ++) g[i].push_back(g[i][j]);
            pre[i].push_back(g[i][0]);
            for(int j = 1;j < g[i].size();j ++) {
            	pre[i].push_back(g[i][j] + pre[i][j - 1]);
            }
            for(int j = i;vis[j];j += k,j %= n)
                vis[j] = 0;
			if(sum[i] > 0) allnon = 0;
		}
		LL ans = 0;
		if(allnon == 1) {
			for(int i = 0;i < len;i ++) {
                ans = max(ans,get(pre[i],m));
			}
		}
		else {
			for(int i = 0;i < len;i ++) {
                LL tmp = 0,l = g[i].size() / 2;
                tmp = max(0ll,m / l * sum[i]);
                tmp += get(pre[i],m % l);
                ans = max(ans,tmp);
//                cout << tmp << endl;
                ans = max(ans,get(pre[i],m));
                if(m / l > 1)
	                ans = max(ans,(m / l - 1) * sum[i] + get(pre[i],l));
			}
		}
        ans = ans >= s ? 0 : s - ans;
		printf("Case #%d: %lld\n",++ cc,ans);
    }
    return 0;
}
/***
2
5 233 11 1
100 100 -100 -100 1

*/
