#include<bits/stdc++.h>
using namespace std;

const int SZ = 1e6 + 10;

int sum[4][SZ];
char s[SZ];

int get(int x,int l,int r) {
    return sum[x][r] - sum[x][l-1];
}

int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",s + 1);
    int t[4] = {0};
    for(int i = 1;i <= n;i ++) {
        s[i+n] = s[i];
        t[s[i]-'A'] ++;
    }

    for(int i = 1;i <= 2*n;i ++) {
        for(int j = 0;j < 3;j ++)
            sum[j][i] += sum[j][i-1];
        sum[s[i]-'A'][i] ++;
    }

    int ans = n;
    for(int i = 0;i < 3;i ++)
        for(int j = 0;j < 3;j ++) {
            for(int k = 0;k < 3;k ++) {
                if(i == j || j == k || i == k) continue;
                for(int l = 1;l <= n;l ++) {
                    int a = t[i],b = t[j],c = t[k];
                    int S = get(i,l,l+a-1) + get(j,l+a,l+a+b-1) + get(k,l+a+b,l+n-1);
                    ans = min(ans,n-S);
                }
            }
        }
    printf("%d\n",ans);
    return 0;
}
