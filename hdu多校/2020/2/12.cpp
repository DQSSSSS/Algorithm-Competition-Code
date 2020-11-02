#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 200010;
const LL INF = 1e18 + 10;
const LL mod = 1e17;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

char A[SZ],B[SZ];
int nx[SZ][27],f[22][22];

int main() {
    int T = read();
    while(T --) {
        scanf("%s",A+1);
        scanf("%s",B+1);
        int n = strlen(A+1);
        int m = strlen(B+1);
        for(int i = 0;i < 26;i ++) nx[n+1][i] = n + 1;
        for(int i = n;i >= 1;i --) {
            memcpy(nx[i],nx[i+1],sizeof nx[i]);
            nx[i][A[i] - 'a'] = i;
            //for(int j = 0;j < 26;j ++) cout << nx[i][j] << " "; puts("");
        }
        int q = read();
        while(q --) {
            int l = read(),r = read();
            for(int i = 1;i <= m;i ++) {
                for(int j = i+1;j <= m;j ++) {
                    f[i][j] = n+1;
                }
            }

            f[1][1] = nx[l][B[1] - 'a'];
            for(int i = 2;i <= m;i ++) {
                for(int j = 1;j <= i;j ++) {
                    if(j>1)
                        f[i][j] = min(f[i-1][j],nx[min(f[i-1][j-1]+1,n+1)][B[i] - 'a']);
                    else
                        f[i][j] = min(f[i-1][j],nx[l][B[i] - 'a']);
                }
            }

            int ans = 0;
            for(int j = 1;j <= m;j ++)
                if(f[m][j] <= r)
                    ans = max(ans,j);

         /*   for(int i = 1;i <= m;i ++) {
                for(int j = 1;j <= i;j ++) {
                    printf("%d ",f[i][j]);
                }
                puts("");
            }

            cout << ans << endl;*/
            printf("%d\n",(r-l+1-ans)+m-ans);
        }
    }
}
