#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 4000010;
const LL INF = 1e18 + 10;
const int mod = 10007;
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

map<LL,int> mp;

int n,m,p;

LL a[210][210];
LL a1[210][210],a2[210][210],MaxMat[210][210],tmp[210][210];
LL b[210],f[210],sum[210];
multiset<LL> Add[210],Del[210];


int main() {
	while(~scanf("%d%d%d",&n,&m,&p)) {
		memset(a1,0,sizeof a1);
		memset(a2,0,sizeof a2);
		memset(tmp,0,sizeof tmp);
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= m;j ++)
				a[i][j] = read(),MaxMat[i][j] = -INF;
		for(int l = 1;l <= n;l ++) {
			for(int i = 1;i <= m;i ++) b[i] = 0;
			for(int r = l;r >= 1;r --) {
				for(int i = 1;i <= m;i ++) {
					b[i] += a[r][i];
					f[i] = -INF;	
				}
				f[0] = -INF;
				sum[m + 1] = 0;
				for(int i = m;i >= 1;i --) sum[i] = sum[i + 1] + b[i];
				mp.clear();
				LL Max = -INF;
				for(int i = 1;i <= m;i ++) {
					f[i] = max(b[i],f[i - 1] + b[i]);
					Max = max(Max,f[i]);
					if(!mp[sum[i]]) mp[sum[i]] = i;
					int L = mp[f[i] + sum[i + 1]],R = i;
					Add[L].insert(f[i]);
					Del[R].insert(f[i]);
				}
				a1[l][r] = Max;
				multiset<LL> s;
				for(int i = 1;i <= m;i ++) {
					while(Add[i].size()) {
						multiset<LL> :: iterator it = Add[i].begin();
						s.insert(-*it);
						Add[i].erase(it);
					}
					tmp[r][i] = -*s.begin();
					while(Del[i].size()) {
						multiset<LL> :: iterator it = Del[i].begin();
						multiset<LL> :: iterator it2 = s.lower_bound(-*it);
						s.erase(it2);
						Del[i].erase(it);
					}
				}
			}
			for(int i = 1;i <= m;i ++) MaxMat[1][i] = max(MaxMat[1][i],tmp[1][i]);
			for(int i = 2;i <= l;i ++) 
				for(int j = 1;j <= m;j ++)
					MaxMat[i][j] = max(MaxMat[i][j],max(MaxMat[i - 1][j],tmp[i][j])),tmp[i][j] = 0;
		}

		LL ans0 = -INF,ans1 = INF;
		
		for(int l = 1;l <= m;l ++) {
			for(int i = 1;i <= n;i ++) b[i] = 0;
			for(int r = l;r >= 1;r --) {
				for(int i = 1;i <= n;i ++) {
					b[i] += a[i][r];
					f[i] = -INF;
				}
				f[0] = -INF;
				LL Max = -INF;
				for(int i = 1;i <= n;i ++) {
					f[i] = max(b[i],f[i - 1] + b[i]);
					Max = max(Max,f[i]);
				}
				a2[l][r] = Max;
				ans0 = max(ans0,Max);
			}
		}
		
		for(int i = 1;i <= n;i ++) {
			for(int j = i;j >= 1;j --)
				for(int k = j;k >= 1;k --)
					a1[i][1] = max(a1[i][1],a1[j][k]);
		}
		for(int i = n;i >= 1;i --) {
			for(int j = n;j >= i;j --)
				for(int k = j;k >= i;k --)
					a1[n][i] = max(a1[n][i],a1[j][k]);
		}	
		for(int i = 1;i <= m;i ++) {
			for(int j = i;j >= 1;j --)
				for(int k = j;k >= 1;k --)
					a2[i][1] = max(a2[i][1],a2[j][k]);
		}
		for(int i = m;i >= 1;i --) {
			for(int j = m;j >= i;j --)
				for(int k = j;k >= i;k --)
					a2[m][i] = max(a2[m][i],a2[j][k]);
		}
		for(int i = 1;i <= n;i ++) {
			for(int j = 1;j <= m;j ++) {
				LL tmp = -INF;
				if(j > 1) tmp = max(tmp,a2[j - 1][1]);
				if(j < m) tmp = max(tmp,a2[m][j + 1]);
				if(i > 1) tmp = max(tmp,a1[i - 1][1]);
				if(i < n) tmp = max(tmp,a1[n][i + 1]);
				LL mm = tmp;
				mm = max(mm,MaxMat[i][j] - a[i][j] + p);
				ans1 = min(ans1,mm);
			}
		}
		printf("%lld\n",min(ans0,ans1));
	}
	return 0;
}
