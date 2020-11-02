#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
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

struct haha {
	int x,y;
}a[SZ];

int num[SZ],bj[SZ];

int main(){
	int n = read(),m = read();
	for(int i = 1;i <= m;i ++) {
		a[i].x = read(),a[i].y = read();
		if(a[i].x > a[i].y) swap(a[i].x,a[i].y);
		num[a[i].x] ++;
	}
	int sx = -1,sy = -1;
	for(int i = 1;i <= n;i ++) {
		if(num[i] < n - i) {
			for(int j = 1;j <= m;j ++) {
				if(a[j].x == i) {
					bj[a[j].y] = 1;
				}
			}
			sx = i;
			for(int j = 1;j <= n;j ++)
				if(!bj[j] && j != i) sy = j;
			break;
		}
	}
	if(sx == -1 || sy == -1) return puts("NO"),0;
	puts("YES");
	int t = 3;
	for(int i = 1;i <= n;i ++) {
		if(i == sx) printf("1 ");
		else if(i == sy) printf("2 ");
		else printf("%d ",t ++);
	}
	puts("");
	t = 2;
	for(int i = 1;i <= n;i ++) {
		if(i == sx) printf("1 ");
		else if(i == sy) printf("1 ");
		else printf("%d ",t ++);
	}
	return 0;
}


