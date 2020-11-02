#include<bits/stdc++.h>
using namespace std;

const int SZ = 1e6 + 10;
typedef long long LL;

char s[SZ],t[SZ];
bool b[SZ];

int main() {
    int T;
    scanf("%d",&T);
    while(T --) {
        int n;
        scanf("%d",&n);
        scanf("%s",s);
        scanf("%s",t);
        for(int i = 0;i < n;i ++) {
            b[i] = s[i] != t[i];
        }
        vector<int> a;
        for(int i = 0,j = 0;i < n;i ++) {
            if(i + 1 == n || b[i+1] != b[i]) {
                if(b[i] == 0) { j = i + 1; continue; }
                else {
                    a.push_back(i-j+1);
                    j = i + 1;
                    if(a.size() == 3) break;
                }
            }
        }
        if(a.size() == 3) puts("0");
        else {
            if(a.size() == 2) printf("%d\n",6);
            else if(a.size() == 1) {
                LL ans = 2*(a[0]-1);
                for(int i = 0,j = 0;i < n;i ++) {
                    if(i + 1 == n || b[i+1] != b[i]) {
                        if(b[i] == 0) { j = i + 1; continue; }
                        else {
                            ans += 2*(n-i + j-1);
                            break;
                        }
                    }
                }
                printf("%lld\n",ans);
            }
            else printf("%lld\n",1ll*n*(n+1)/2);
        }
    }
}
