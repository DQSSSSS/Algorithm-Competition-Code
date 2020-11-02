#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ= 1e6 + 10;

int a[SZ];
int f[SZ][2][2];

int main() {
    int n;
    while(~scanf("%d",&n)) {
        for(int i = 1;i <= n+3;i ++) {
            a[i] = 0;
            for(int j = 0;j < 2;j ++) {
                for(int k = 0;k < 2;k ++)
                    f[i][j][k] = 0;
            }
        }
        for(int i = 1;i <= n;i ++) {
            int x;
            scanf("%d",&x);
            a[x] ++;
        }
        for(int i = 1;i <= n;i ++) {
            for(int j = 0;j < 2;j ++)
                for(int k = 0;k < 2;k ++) {
                    for(int l = 0;l < 2;l ++) {
                        if(a[i] >= j+k+l && a[i+1] >= k+l && a[i+2] >= l)
                            f[i][k][l] = max(f[i][k][l],f[i-1][j][k] + l + (a[i]-j-k-l)/2);
                    }
                }
        }
        int ans = 0;
        for(int j = 0;j < 2;j ++) {
            for(int k = 0;k < 2;k ++)
                ans = max(ans,f[n][j][k]);
        }
        printf("%d\n",ans);
    }
}

