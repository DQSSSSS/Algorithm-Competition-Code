#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 2010;
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

char s[SZ];
int sum[66][1010][510],L,n;
int id[1010][510],xx[SZ],yy[SZ];
int vis[1010][510];

int get(char c) {
	if('0' <= c && c <= '9') return c - '0';
	if('a' <= c && c <= 'z') return c - 'a' + 10;
	if('A' <= c && c <= 'Z') return c - 'A' + 36;
}

int get(int k,int p1,int x1,int y1,int x2,int y2) {
    int d = sum[k][xx[p1]][yy[p1]];
    int d1 = sum[k][x1][y1];
    int d2 = sum[k][x2][y2];
    int d3 = sum[k][x2][y1];
    /*cout << k << endl;
    cout << xx[p1] << " " << yy[p1] << ", ";
    cout << xx[p2] << " " << yy[p2] << ", ";
    cout << xx[p3] << " " << yy[p3] << endl;
	cout << x << " " << x1 << " " << x2 << " " << x3 << endl;*/
	return d - d1 - d2 + d3;
}

int getx(int x) { return (x - 1) / n + 1; }
int gety(int x) { return (x - 1) % n + 1; }

int main() {
	int T = read();
    while(T --) {
        L = read();
        n = 2 * L - 1;
        for(int i = 1;i <= 2 * L - 1;i ++) {
			scanf("%s",s + 1);
            int len = strlen(s + 1);
            for(int j = 1;j <= len;j ++) {
            	int y = i > L ? j + i - L : j;
				sum[get(s[j])][i][y] = 1;
            }
        }
        for(int i = 1,tot = 0;i <= 2 * L - 1;i ++) {
			for(int j = 1;j <= 2 * L - 1;j ++) {
                xx[++ tot] = i; yy[tot] = j;
			}
		}

        for(int k = 0;k <= 61;k ++)
			for(int i = 1;i <= 2 * L - 1;i ++) {
				for(int j = 1;j <= 2 * L - 1;j ++) {
					sum[k][i][j] += sum[k][i - 1][j] + sum[k][i][j - 1] - sum[k][i - 1][j - 1];
				}
			}
			/*
		for(int k = 0;k <= 18;k ++,puts(""))
			for(int i = 1;i <= 2 * L - 1;i ++) {
				int m = 2 * L - 1 - abs(i - L);
				for(int j = 1;j <= 2 * L - 1;j ++) {
					printf("%d ",sum[k][i][j]);
				}
				puts("");
			}
			*/

		for(int is = L,j = 1,x = 1;is >= 1;is --,j ++,x ++) {
            for(int i = is,t = 1,y = 1;t <= 2 * L - is;i += 2,t ++,y ++) {
                id[i][j] = (x - 1) * n + y;
      //          cout << i << " " << j << " " << (x - 1) * n + y << endl;
            }
		}
		for(int is = 2,j = L + 1,x = L + 1;is <= L;is ++,j ++,x ++) {
            for(int i = is,t = 1,y = is;t <= 2 * L - is;i += 2,t ++,y ++) {
                id[i][j] = (x - 1) * n + y;
      //          cout << i << " " << j << " " << (x - 1) * n + y << endl;
            }
		}

		int q = read();
		while(q --) {
			int x = read(),y = read(),l = read();
			int p6 = id[x][y];
			int p5 = id[x + l - 1][y + l - 1];
			int p4 = id[x + 3 * (l - 1)][y + l - 1];
			int p3 = id[x + 4 * (l - 1)][y];
			int p2 = id[x + 3 * (l - 1)][y - l + 1];
			int p1 = id[x + l - 1][y - l + 1];
			int zx = id[x + 2 * (l - 1)][y];

			/*int p5z = id[max(0,x + l - 1 - 2)][y + l - 1];
			int p6z = id[max(0,x - 2)][y];
			int p3s = id[x + 4 * (l - 1) + 1][y - 1];
			int p2s = id[x + 3 * (l - 1) + 1][y - l + 1 - 1];*/

			int p5zx = getx(p5),p5zy = gety(p5) - 1;
			int p6zx = getx(p6),p6zy = gety(p6) - 1;
			int p3sx = getx(p3) - 1,p3sy = gety(p3);
			int p2sx = getx(p2) - 1,p2sy = gety(p2);

			cout << p1 << " " << p2 << " " << p3 << " ";
			cout << p4 << " " << p5 << " " << p6 << endl;
			cout << xx[p6] << " " << yy[p6] << endl;
			cout << xx[p5] << " " << yy[p5] << endl;
			cout << xx[p4] << " " << yy[p4] << endl;
			cout << xx[p3] << " " << yy[p3] << endl;
			cout << xx[p2] << " " << yy[p2] << endl;
			cout << xx[p1] << " " << yy[p1] << endl;
			puts("");
            cout << xx[p4] << " " << yy[p4] << endl;
            cout << p5zx << " " << p5zy << endl;
            cout << p3sx << " " << p3sy << endl;
			puts("");
			cout << xx[zx] << " " << yy[zx] << endl;
            cout << p6zx << " " << p6zy << endl;
            cout << p2sx << " " << p2sy << endl;

			int ans = 0;
			for(int k = 0;k <= 61;k ++) {
                int d1 = get(k,p4,p5zx,p5zy,p3sx,p3sy);
                int d2 = get(k,zx,p6zx,p6zy,p2sx,p2sy);
                int d3 = sum[k][p5zx][p5zy] - sum[k][getx(p3)][p5zy];
                int d4 = sum[k][p3sx][p3sy] - sum[k][p3sx][gety(p5)];
				if(d1 + d2 + d3 + d4 > 0)
					ans ++,cout << k << " " << d1 << " " << d2 << " " << d3 << " " << d4 << endl;
			}
			printf("%d\n",ans);
		}
    }
}
/**
0  1  2
3  4  5 6
7  8  9 10 11
  12 13 14 15
     16 17 18

1
3
012
3456
789ab
cdef
ghi
10
1 3 3
*/
