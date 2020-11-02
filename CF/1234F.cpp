#include<bits/stdc++.h>
using namespace std;

const int SZ = 2e6 + 10;

int f[SZ];
char s[SZ];

int main() {
    scanf("%s",s+1);
    int n = strlen(s+1);
    for(int i = 1;i <= n;i ++) {
        int j = i,len = 0;
        int S = 0;
        while(j >= 1) {
            int p = s[j] - 'a';
            if(S >> p & 1) break;
            len ++; S |= 1 << p; j --;
            f[S] = max(f[S],len);
        }
    }
    for(int i = 0;i < 20;i ++) {
        for(int S = 0;S < (1<<20);S ++) {
            if(S >> i & 1) {
                f[S] = max(f[S],f[S^(1<<i)]);
            }
        }
    }
    int ans = 0,msk = 1<<20; msk --;
    for(int S = 0;S < (1<<20);S ++) {
        ans = max(ans,f[S]+f[S^msk]);
    }
    cout << ans << endl;
    return 0;
}
