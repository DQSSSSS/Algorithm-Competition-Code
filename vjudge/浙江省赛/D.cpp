#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}


int main() {
    int T = read();
    while(T --) {
        int n = read();
        int x = n,len = 0;
        while(x) a[++ len] = x,x/=2;
        sort(a+1,a+1+len);
        int tot = 0,rst = n;
        for(int i = 1,now = 1;i <= len;i += 2) {
            if(i + 1 == len) {
                now = n;
                while(rst --) g[++tot] = now --;
            }
        }
    }
}
