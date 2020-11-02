#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 37;
const int INF = 1e9 + 10;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

short pp[SZ],aa[SZ],cc[SZ],mm[SZ],gg[SZ];
short f[SZ][SZ][SZ][SZ];
LL ans[SZ][SZ][SZ][SZ];

int main(){
    int n = read();
    for(int i = 0;i < n;i ++)
		pp[i] = read(),aa[i] = read(),cc[i] = read(),mm[i] = read(),gg[i] = read();
    int P = read(),A = read(),C = read(),M = read();
    for(int i = 0;i < n;i ++)
        for(int a = P;a >= pp[i];a --)
            for(int b = A;b >= aa[i];b --)
				for(int c = C;c >= cc[i];c --)
					for(int d = M;d >= mm[i];d --) {
                        if(f[a][b][c][d] < f[a - pp[i]][b - aa[i]][c - cc[i]][d - mm[i]] + gg[i]) {
							f[a][b][c][d] = f[a - pp[i]][b - aa[i]][c - cc[i]][d - mm[i]] + gg[i];
                            ans[a][b][c][d] = ans[a - pp[i]][b - aa[i]][c - cc[i]][d - mm[i]] | (1ll << (LL)i);
                        }
					}
	LL sum = 0,x = ans[P][A][C][M];
	for(LL j = 0;j < n;j ++) if(x & (1ll << j)) sum ++;
	cout << sum << endl;
	for(LL j = 0;j < n;j ++) if(x & (1ll << j)) cout << j << " ";
    return 0;
}
