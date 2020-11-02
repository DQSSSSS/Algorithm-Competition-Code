#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int n;
LL dp[SZ],a[SZ];
vector<LL> g[10010],g2[10010];

///  1 3 2 4
///1 4 5 2
///  1 2 4
///  2 3
///  3 4
///  4

void add(vector<LL> &g,int x,LL d) {
    int n = g.size(); n --;
    for(int i = x;i <= n;i += i & -i)
    	(g[i] += d) %= mod;
}

LL ask(const vector<LL> &g,int x) {
	LL ans = 0;
    for(int i = x;i > 0;i -= i & -i)
    	(ans += g[i]) %= mod;
	return ans;
}

int main() {
/*
	n = 10000;
	LL ans = 0;
    for(int k = 1;k <= n;k ++) a[k] = k;
    for(int k = 1;k <= 10;k ++) {
        for(int i = 2;i <= n;i ++) swap(a[i],a[rand() % (i - 1) + 1]);
        ans = max(ans,get_max());
    }
    cout << ans << endl;
*/
	int T = read(),cc = 0;
	while(T --) {
		n = read();
		for(int i = 1;i <= n;i ++) a[i] = read();

		for(int i = 0;i <= n;i ++) dp[i] = INF,g2[i].clear(),g[i].clear();
		for(int i = 0;i <= n;i ++)
			g2[i].push_back(0);
		g2[0].push_back(n+1);
		for(int i = 1;i <= n;i ++) {
			int id = lower_bound(dp + 1,dp + 1 + n,a[i]) - dp;
			dp[id] = a[i];
            for(int j = 1;j <= id;j ++) {
                g2[j].push_back(a[i]);
            }
		}

		int maxlen = lower_bound(dp + 1,dp + 1 + n,INF) - dp - 1;

		for(int i = 1;i <= maxlen;i ++) sort(g2[i].begin(),g2[i].end());


	/*	for(int i = 0;i <= maxlen;i ++) {
			for(int j = 0;j < g2[i].size();j ++)
				cout << g2[i][j] << " ";
			puts("");
		}
*/
		for(int i = 1;i <= n;i ++) dp[i] = INF,g[i].resize(g2[i].size());
		g[0].push_back(0);
		g[0].push_back(1);
		for(int i = 1;i <= n;i ++) {
			int id = lower_bound(dp + 1,dp + 1 + n,a[i]) - dp;
			dp[id] = a[i];
            for(int j = id - 1;j >= 0;j --) {
                int pos1 = lower_bound(g2[j].begin(),g2[j].end(),a[i]) - g2[j].begin();
                int pos2 = lower_bound(g2[j + 1].begin(),g2[j + 1].end(),a[i]) - g2[j + 1].begin();
                          //          cout << i << " " << j << " " << pos1 << " " << pos2 << endl;

                if(j == 0) {
                	add(g[j + 1],pos2,1);
                }
                else {
					LL x = ask(g[j],pos1);
					add(g[j + 1],pos2,x);
            	}
            }
		}
/*
		for(int i = 0;i <= maxlen;i ++) {
			for(int j = 0;j < g[i].size() - 1;j ++)
				cout << ask(g[i],j + 1) - ask(g[i],j) << " ";
			puts("");
		}

		cout << maxlen << endl;
*/
		printf("Case #%d: ",++ cc);
		for(int i = 1;i <= n;i ++) {
			if(i > maxlen) {
				printf("%lld%c",0ll,i == n ? '\n' : ' ');
				continue;
			}
			LL ans = ask(g[i],g[i].size() - 1);
			printf("%lld%c",ans,i == n ? '\n' : ' ');
		}
	}
	return 0;
}
/*

*/
