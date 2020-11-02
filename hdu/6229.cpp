#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef double LD;
typedef pair<LL,LL> pii;
const int SZ = 2100010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;
const LD PI = acos(-1);
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

LL get_ini(LL n) {
	LL ans = 0;
	if(n == 1) return 1;
	if(n == 2) return 3 * 4;
	ans = 3 * 4 + 4 * (n - 2) * 4 + (n - 2) * (n - 2) * 5;
	return ans;
}

int n,k;
map<int,map<int,int> > mp;

int pos_val(int x,int y) {
	if(mp[x][y] > 0) return mp[x][y];
	if(x == 0 && y == 0) return 3;
	if(x == 0 && y == n - 1) return 3;
	if(x == n - 1 && y == 0) return 3;
	if(x == n - 1 && y == n - 1) return 3;
	if(x == 0 || y == 0 || x == n - 1 || y == n - 1) return 4;
	return 5;
}

int main() {
	int T = read(),cc = 0;
	while(T --) {
		n = read(),k = read();
		mp.clear();
		LL fz,fm;
		fm = get_ini(n);
		if(n == 1) fz = 0;
		else fz = (fm + 2 * 3 + (n - 2) * 5) / 2;
	//	cout << fz << " " << fm << endl;
		for(int i = 1;i <= k;i ++) {
			int nx = read(),ny = read();
			if(nx + ny >= n - 1)
				fz -= pos_val(nx,ny);
			fm -= pos_val(nx,ny);
			mp[nx][ny] = -1;
			for(int j = 0;j < 4;j ++) {
				int x = nx + dx[j];
				int y = ny + dy[j];
				if(x >= 0 && x < n && y >= 0 && y < n) {
					if(mp[x][y] == -1) continue;
					if(!mp[x][y])
						mp[x][y] = pos_val(x,y);
		//			cout << x << " " << y << endl;
					mp[x][y] --; fm --;
					if(x + y >= n - 1) fz --;
				}
			}
		//	cout << fz << " / " << fm << endl;
		}
		LL d = __gcd(fz,fm);
		fz /= d; fm /= d;
		printf("Case #%d: %lld/%lld\n",++ cc,fz,fm);
	}
	return 0;
}	
