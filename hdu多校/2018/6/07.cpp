#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const ULL mod = 998244353;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

ULL ksm(ULL a,ULL b) {
	a %= mod;
	ULL ans = 1;
    while(b) {
    	if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int n,m;
struct edge {
	int f,t;
	ULL d;
}l[SZ];

//bool cmp2(haha a,haha b) { return a.d < b.d; }
bool operator <(edge a,edge b) { return a.d < b.d; }

bool use[SZ];
int fa[SZ];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

ULL ABS(ULL a,ULL b) {
	if(a > b) return a-b;
	else return b-a;
}

ULL check(ULL mm) {
	int pl = 0,pr = m + 1;
    for(int i = 1;i <= m;i ++) {
		if(l[i].d * (n - 1llu) < mm) pl = i;
	}
	pr = pl + 1;
    for(int i = 1;i <= n;i ++) fa[i] = i;
    ULL ans = 0;
    while(pl >= 1 || pr <= m) {
    	int i;
        if(pr > m) i = pl --;
        else if(pl < 1) i = pr ++;
        else {
			ULL dl = ABS(l[pl].d * (n - 1llu),mm);
			ULL dr = ABS(l[pr].d * (n - 1llu),mm);
        	if(dl < dr) {
        		i = pl --;
        	}
        	else i = pr ++;
        }
        int x = find(l[i].f);
        int y = find(l[i].t);
    	if(x != y) {
    		fa[x] = y;
    		ULL d = ABS(l[i].d * (n - 1llu),mm);
    		if(d * d < d) return 1e18;
    		ans += d * d;
    	}
    }
    return ans;
}

ULL get(LL mm) {
    int pl = 0,pr = n;
    for(int i = 1;i <= m;i ++) {
        if(l[i].d *(n - 1) < mm) pl = i;
    }
    pr = pl + 1;
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1;i <= m;i ++) use[i] = 0;
    while(pl >= 1 || pr <= m) {
        int i;
        if(pr > m) i = pl --;
        else if(pl < 1) i = pr ++;
        else if(l[pl].d < l[pr].d) i = pl --;
        else i = pr ++;
        int x = find(l[i].f);
        int y = find(l[i].t);
        if(x != y) {
            fa[x] = y;
            use[i] = 1;
        }
    }

    LL A = 0;
    for(int i = 1;i <= m;i ++)
        if(use[i]) A = (A + l[i].d) % mod;
  //  cout << A << endl;
    A = A * ksm(n - 1,mod - 2) % mod;
  //  cout << A * (n - 1) % mod << endl;
    ULL ans = 0;
    for(int i = 1;i <= m;i ++)
        if(use[i]) {
            ULL d = ABS(l[i].d,A) % mod;
            (ans += d * d % mod) %= mod;
        }
    ans = ans * ksm(n - 1,mod - 2) % mod;
    ans += mod; ans %= mod;
    return ans;
}

int main() {
	//freopen("233.txt","r",stdin);
	int T = read();
    while(T --) {
        n = read(),m = read();
		for(int i = 1;i <= m;i ++) {
            int x = read(),y = read(),v = read();
            l[i].f = x; l[i].t = y; l[i].d = v;
            //g[x].push_back(y);
            //g[y].push_back(x);
		}
        sort(l + 1,l + 1 + m);
        ULL L = 0,R = 0;
        for(int i = m,t = 1;i >= 1,t <= n - 1;i --,t ++)
			R += l[i].d;
        while(R - L > 2) {
        	ULL midl = L + (R - L) / 3;
        	ULL midr = R - (R - L) / 3;
            if(check(midl) > check(midr)) L = midl;
            else R = midr;
        }
        ULL ans = L;
        ULL tmp = (ULL)-1;
        for(ULL i = L;i <= R;i ++) {
        	ULL d = check(i);
            if(d < tmp) ans = i,tmp = d;
            //cout << i << " " << d << endl;
        }
		//cout << ans << " " << tmp << endl;
		//printf("%.10f %llu\n",(double)ans / (n - 1),tmp);
		//printf("%.10f %.10f\n",(double)L / (n - 1),(double)R / (n - 1));
		//printf("%.10f %.10f\n",(double)L,(double)R);
        printf("%llu\n",get(ans));
    }
	return 0;
}
/**
48299.7737464505 48299.7737464505
121942570

49497.2676031590 49497.6152761624

305316148
118334464
243134354
340848150
541803937
852181271
849846890
223264695
550408995
165012836


29023.0000000000 29023.0000200002
35643971
28831.0000000000 28831.0000200002
292833841
29267.0000000000 29267.0000200002
801369930
28949.0000000000 28949.0000200002
180486788
28927.0000000000 28927.0000200002
415151668
29090.0000000000 29090.0000200002
79224431
29009.0000000000 29009.0000200002
850380868
28944.0000000000 28944.0000200002
832251702
28960.0000000000 28960.0000200002
78642017
29163.0000000000 29163.0000200002
845011668

4 6
1 2 1
2 3 1
3 4 1
1 4 5
1 3 5
3 4 6

*/
