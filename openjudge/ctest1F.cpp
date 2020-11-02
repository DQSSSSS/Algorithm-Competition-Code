#include<bits/stdc++.h>
using namespace std;

int f[110][110],a[110];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            for(int k = 1;k <= i;k ++)
                if(i-k >= j-1)
                    f[i][j] = max(f[i][j],f[i-k][j-1] + a[k]);
        }
    }
    printf("%d\n",f[n][m]);
    return 0;
}
