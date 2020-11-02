#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned int UI;
typedef pair<LL,LL> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

const int MAXN = 1e5;
UI mu[SZ];
int pk[SZ];
LL psum[SZ];
pii f[SZ];
int pri[SZ],tot;
bool vis[SZ];

void shai(int n = MAXN) {
    pk[1] = psum[1] = mu[1] = 1; f[1] = make_pair(1,1);
    for(int i = 2;i <= n;i ++) {
    	if(!vis[i]) pri[++ tot] = i,mu[i] = -1,f[i] = make_pair(i + 1,i),psum[i] = i + 1,pk[i] = i;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
        	vis[m] = 1;
            if(i % pri[j] == 0) {
            	mu[m] = 0;
				pk[m] = pk[i] * pri[j];
				psum[m] = psum[i] + pk[m];
            	f[m] = make_pair(f[i].first / psum[i] * psum[m],m);
            	break;
            }
            else {
                mu[m] = -mu[i];
                pk[m] = pri[j];
                psum[m] = pri[j] + 1;
                f[m] = make_pair(f[pri[j]].first * f[i].first,m);
            }
        }
    }
    sort(f + 1,f + 1 + n);
    //for(int i = 1;i <= n;i ++) cout << f[i].first << " " << f[i].second << endl;
}

UI tree[SZ],n = 1e5;

void add(int x,UI d) {
	for(int i = x;i <= n;i += i & -i)
		tree[i] += d;
}

UI Ask(int x) {
	UI ans = 0;
	for(int i = x;i >= 1;i -= i & -i)
        ans += tree[i];
    return ans;
}

struct haha {
	UI n,m,x,id;
	UI ans;
}ask[SZ];

bool cmp1(haha a,haha b) { return a.x < b.x; }
bool cmp2(haha a,haha b) { return a.id < b.id; }

int main() {
	shai();
    int q = read();
    for(int i = 1;i <= q;i ++)
        ask[i].n = read(),ask[i].m = read(),ask[i].x = read(),ask[i].id = i;
    sort(ask + 1,ask + 1 + q,cmp1);
    for(int i = 1,j = 1;i <= q;i ++) {
    	while(j <= 1e5 && f[j].first <= ask[i].x) {
            for(int k = f[j].second;k <= 1e5;k += f[j].second)
                add(k,f[j].first * mu[k / f[j].second]);
            j ++;
        }
        UI n = ask[i].n,m = ask[i].m;
    	if(n > m) swap(n,m);
        for(UI k = 1,r;k <= n;k = r + 1) {
            r = min(n / (n / k),m / (m / k));
            ask[i].ans += 1u * (Ask(r) - Ask(k - 1)) * (n / k) * (m / k);
        }
    }
    sort(ask + 1,ask + 1 + q,cmp2);
    for(int i = 1;i <= q;i ++)
    	printf("%u\n",ask[i].ans & ((1ll << 31ll) - 1ll));
    return 0;
}
