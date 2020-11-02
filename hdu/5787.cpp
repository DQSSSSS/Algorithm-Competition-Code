#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
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

LL f[22][12][12][12][12];
int k;

bool check(int p1,int p2,int p3,int p4,int x) {
	if(x == 10) return true;
    if(k == 2) return x != p1;
    if(k == 3) return x != p1 && x != p2;
    if(k == 4) return x != p1 && x != p2 && x != p3;
    if(k == 5) return x != p1 && x != p2 && x != p3 && x != p4;
}

void init() {
	memset(f,0,sizeof(f));
    for(int i = 0;i <= 9;i ++) f[1][i][10][10][10] = 1;
    for(int i = 2;i <= 18;i ++)
    	for(int a = 0;a <= 10;a ++)
			for(int b = 0;b <= 10;b ++)
				for(int c = 0;c <= 10;c ++)
					for(int d = 0;d <= 10;d ++)
						for(int x = 0;x <= 9;x ++) {
                            if(check(a,b,c,d,x))
                                f[i][x][a][b][c] += f[i - 1][a][b][c][d];
						}
}

LL ask(LL x) {
	//cout << "---  " << x << "  ---" << endl;
    LL n = 0,num[22] = {0};
    while(x) num[++ n] = x % 10,x /= 10;
    LL ans = 0;
    for(int i = 1;i < n;i ++)
        for(int a = 1;a <= 9;a ++)
			for(int b = 0;b <= 10;b ++)
				for(int c = 0;c <= 10;c ++)
					for(int d = 0;d <= 10;d ++)
						ans += f[i][a][b][c][d];
	//cout << ans << endl;
	for(int a = 1;a < num[n];a ++)
		for(int b = 0;b <= 10;b ++)
			for(int c = 0;c <= 10;c ++)
				for(int d = 0;d <= 10;d ++)
					ans += f[n][a][b][c][d];
	//cout <<ans << endl;
	int a = num[n],b = 10,c = 10,d = 10;
    for(int i = n - 1;i >= 1;i --) {
        for(int p1 = 0;p1 < num[i];p1 ++) {
            if(!check(a,b,c,d,p1)) continue;
			for(int p2 = 0;p2 <= 10;p2 ++) {
				if(!check(p1,a,b,c,p2)) continue;
				for(int p3 = 0;p3 <= 10;p3 ++) {
					if(!check(p2,p1,a,b,p3)) continue;
					for(int p4 = 0;p4 <= 10;p4 ++) {
    					if(!check(p3,p2,p1,a,p4)) continue;
                        ans += f[i][p1][p2][p3][p4];
                    }
        		}
        	}
        }
       // cout << i << " " << ans << endl;
        int x = num[i];
        if(!check(a,b,c,d,x)) break;
        d = c; c = b; b = a; a = x;
    }
	return ans;
}

int main() {
	LL l,r;
    while(~scanf("%lld%lld%d",&l,&r,&k)) {
		init();
        //printf("%lld %lld %lld\n",ask(r + 1),ask(l),ask(r + 1) - ask(l));
        printf("%lld\n",ask(r + 1) - ask(l));
    }
    /*LL n;
    while(~scanf("%lld%d",&n,&k)) {
		init();
		cout << ask(n + 1) << endl;
    }*/
    return 0;
}
