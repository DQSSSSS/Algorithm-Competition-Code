#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 5010;
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

vector<int> g[5010],yi,ji,ou;

int pri[2100010],tot;
bool npri[2100010];

void shai(int n) {
	for(int i = 2;i <= n;i ++) {
		if(!npri[i]) pri[++ tot] = i;
		for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
			npri[m] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}

int match[5010];
bool vis[5010];

bool dfs(int u) {
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		if(!vis[v]) {
			vis[v] = 1;
			if(!match[v] || dfs(match[v])) {
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}

int del[SZ],a[SZ],n,k;

int get_ans(int now,int yisz,int sum,int k,bool isyi) {
	//cout << now << " " << yisz << " " << sum << " " << k << " " << isyi << endl;
	int ans = min(now,k) * 2;
	if(k > now) {
		int dd = k - now;
		if(dd * 2 <= yisz) ans += dd * 2;
		else {
			ans += yisz / 2 * 2;
			dd -= yisz / 2;
			if(dd) {
				if(yisz & 1) {
					if(yisz > 1)
						ans ++,dd --;
					else if(isyi) {
						bool f = 0;
						for(int i = 1;i <= n;i ++)
							if(a[i] % 2 == 0 && !match[i] && !npri[a[i] + 1])
								f = 1;
						if(f) ans += 2,dd --;
						else ans ++,dd --;
					}
				}
				//cout << dd << endl;
				if(dd <= sum) ans += dd;
				else ans += sum;
			}
		}
	}
	//cout << ans << endl;
	return min(ans,k * 2);
}

int main() {
	freopen("H.in","r",stdin);
	freopen("my.out","w",stdout);
	shai(2e6);
	int T = read();
	while(T --) {
		n = read(),k = read();
		yi.clear(),ji.clear(),ou.clear();
		for(int i = 1;i <= n;i ++) {
			a[i] = read();
			del[i] = 0;
			match[i] = vis[i] = 0;
			g[i].clear();
		}
		/*for(int i = 1;i <= n;i ++) {
			int f = 0;
			for(int j = i + 1;j <= n;j ++)
				if(!npri[a[i] + a[j]])
					cout << i << " " << j << endl;
		}*/
		int sum = n;
		for(int i = 1;i <= n;i ++) {
			if(a[i] == 1) { sum --; continue; }
			int f = 0;
			for(int j = 1;j <= n;j ++)
				if(!npri[a[i] + a[j]])
					f = 1;
			if(!f) del[i] = 1,sum --;
		}
		for(int i = 1;i <= n;i ++) {
			if(del[i]) continue;
			if(a[i] == 1) yi.push_back(i);
			else if(a[i] % 2 == 0) ou.push_back(i);
			else ji.push_back(i);
		}
		for(int i = 0;i < ji.size();i ++) {
			int x = ji[i];
			for(int j = 0;j < ou.size();j ++) {
				int y = ou[j];
				if(!npri[a[x] + a[y]]) g[x].push_back(y);
			}
		}	
		bool isyi = 0;
		for(int i = 0;i < yi.size();i ++) {
			int x = yi[i];
			for(int j = 0;j < ou.size();j ++) {
				int y = ou[j];
				if(!npri[a[x] + a[y]]) g[x].push_back(y),isyi = 1;
			}
			//if(i == 0 && f == 0) sum -= yi.size();
		}
		int now = 0;
		for(int k = 0;k < ji.size();k ++) {
			int x = ji[k];
			for(int i = 1;i <= n;i ++) vis[i] = 0;
			if(dfs(x)) now ++;
		}
		//cout << now << " " << sum << endl;
		int ans = get_ans(now,yi.size(),sum - 2 * now,k,isyi);
		for(int i = 0,t = 0;i < yi.size();i ++) {
			int x = yi[i];
			for(int j = 1;j <= n;j ++) vis[j] = 0;
			if(dfs(x)) now ++,t ++;
			ans = max(ans,get_ans(now,yi.size() - t,sum - now - (now - t),k,isyi));
		//	cout << now << endl;
		}
		ans = min(ans,sum + (int)(isyi ? yi.size() : yi.size() / 2));
		printf("%d\n",ans);
	}
	return 0;
}
/**
2333
7 5
1 1 1 1 1 1 4

1
20 10
5 4 5 3 3 4 4 3 1 1 4 4 1 5 5 2 3 2 2 3 

1
20 10
3 4 2 4 2 2 3 4 3 2 5 1 4 3 2 1 5 5 1 1 

1
5 3
3 3 3 3 1 
*/
