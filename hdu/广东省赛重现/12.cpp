#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

char a[SZ],b[SZ];

int main() {
    while(~scanf("%s%s",a,b)) {
        string aa = a,bb = b;
        if(aa == bb) puts("Equal");
        else {
            if(aa.length() != bb.length()) puts("No");
            else {
                int n = aa.length();
                if(aa[0] == bb[0] && aa[n-1] == bb[n-1]) {
                    sort(a,a+n);
                    sort(b,b+n);
                    aa = a; bb = b;
                    if(aa == bb)
                        puts("Yes");
                    else puts("No");

                }
                else puts("No");
            }
        }
    }
}
