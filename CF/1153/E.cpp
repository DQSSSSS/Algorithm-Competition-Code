#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int t = 0;

int ask(int x1,int y1,int x2,int y2) {
    if(++ t > 2019) while(1);
    printf("? %d %d %d %d\n",x1,y1,x2,y2);
    fflush(stdout);
    return read();
}

int main() {
    int n = read();
    int l = -1,r = -1;
    for(int i = 1;i < n;i ++) {
        int x = ask(1,1,n,i);
        if(x & 1) {
            if(l == -1) l = i,r = i+1;
            else r = i+1;
        }
    }
    int u = -1,d = -1;
    for(int i = 1;i < n;i ++) {
        int x = ask(1,1,i,n);
        if(x & 1) {
            if(u == -1) u = i,d = i+1;
            else d = i+1;
        }
    }

    if(l != -1 && u != -1) {
        if(ask(1,1,u,l) & 1)
            return printf("! %d %d %d %d\n",u,l,d,r),0;
        else
            return printf("! %d %d %d %d\n",u,r,d,l),0;
    }
   // printf("%d %d %d %d\n",u,l,d,r);
    if(l != -1) {
        int L = 0,R = n;
        while(R - L > 1) {
            int mid = L + R >> 1;
            int x = ask(1,1,mid,l);
            if(x % 2 == 0) L = mid;
            else R = mid;
        }
        return printf("! %d %d %d %d\n",R,l,R,r),0;
    }
    else {
        int L = 0,R = n;
        while(R - L > 1) {
            int mid = L + R >> 1;
            int x = ask(1,1,u,mid);
            if(x % 2 == 0) L = mid;
            else R = mid;
        }
        return printf("! %d %d %d %d\n",u,R,d,R),0;
    }
}
