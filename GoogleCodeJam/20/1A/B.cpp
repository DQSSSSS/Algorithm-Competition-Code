#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 200010;
const LL INF = 1e18 + 10;
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

int C[1010][1010];

int work() {
    int n = read();
    int t =30;
    if(n <= t) {
        int r = 1;
        while(n --) {
            printf("%d %d\n",r,1);
            r ++;
        }
    }
    else {
        int val = 0,N = n;
        n -= t;
        int r = 1,c = 1,dir = 1;
        for(int i = 0;i < 30 && (n>>i);i ++) {
            if(n >> i & 1) {
                while(c >= 1 && c <= r) {
                    printf("%d %d\n",r,c);
                    val += C[r][c];
                    c += dir;
                }
                if(dir == -1) c -= dir;
                r ++;
                dir *= -1;
            }
            else {
                printf("%d %d\n",r,c);
                val += C[r][c];
                r ++;
                t --;
                if(c != 1) c ++;
            }
        }
        while(t --) {
            printf("%d %d\n",r,c);
            val += C[r][c];
            r ++;
            if(c != 1) c ++;
        }
       /* if(val != N) {
            cout << val << " -- " << N << endl;
        }
        assert(val == N);*/
    }
}

int main() {
    C[1][1] = 1;
    for(int i = 2;i <= 100;i ++) {
        for(int j = 1;j <= i;j ++) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }

    int T = read(),cc = 0;
    while(T --) {
        printf("Case #%d:\n",++ cc);
        work();
    }
}
