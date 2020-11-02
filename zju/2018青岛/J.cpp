#include<bits/stdc++.h>
using namespace std;

const int SZ = 1e6 + 10;
typedef long long LL;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a=='-') flag = 1; a = getchar(); }
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a = getchar(); }
    if(flag) n=-n;
    return n;
}

int a[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read(),t = 0;
        for(int i = 1;i <= n;i ++) {
            a[i] = read();
            if(a[i] == 0) t ++;
        }
        if(t > m) puts("Impossible");
        else if(n == m) puts("Richman");
        else {
            m -= t;
            vector<int> b;
            LL minx = 1e9,sum = 0;
            for(int i = 1;i <= n;i ++)
                if(a[i])
                    b.push_back(a[i]);
            for(int i = 0;i < m;i ++) {
                sum += b[i];
            }
            for(int i = m;i < b.size();i ++) {
                minx = min(minx,b[i]*1ll);
            }
            printf("%lld\n",sum + minx - 1);
        }
    }
}
/**
1
5 3
5 0 4 0 3
*/
