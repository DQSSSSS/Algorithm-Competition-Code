#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 5e5 + 10;
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a=='-') flag=1; a=getchar(); }
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a=getchar(); }
    if(flag) n=-n;
    return n;
}

int n,q;

struct haha {
    int x1,y1;
    int x2,y2;
    LL ans;
}A[SZ];

int a[SZ],b[SZ];
int pra[SZ],prb[SZ];
int nxa[SZ],nxb[SZ];

void work() {
    init(a,pra,nxa); init(b,prb,nxb);

    for(int i = 1;i <= q;i ++) {
        int x1 = A[i].x1,y1 = A[i].y1;
        int x2 = A[i].x2,y2 = A[i].y2;
        int dx = x2 - x1,dy = y2 - y1;
        if(dx <= dy) {
            int d = dy - dx;
            if(d&1) d--;
            LL ans = 1e18;
            if(pra[x1] != -1) {
                LL tmp = suma[x1] - suma[pra[x1]] + suma[x2] - suma[pra[x1]];
                tmp += sumb[y2] - sumb[y1];
                tmp += d;
                ans = min(ans,tmp);
            }
            if(nxa[x1] != -1) {
                LL tmp = suma[pra[x1]] - suma[x1] + abs(suma[x2] - suma[nxa[x1]]);
                tmp += sumb[y2] - sumb[y1];
                tmp += d;
                ans = min(ans,tmp);
            }
            ans = min(ans,(x2-x1+y2-y1+d)*5);
            A[i].ans = ans;
        }
    }
}

int main() {
    n = read();
    for(int i = 1;i < n;i ++) a[i] = read();
    for(int i = 1;i < n;i ++) b[i] = read();
    q = read();
    for(int i = 1;i <= q;i ++) {
        int x1 = read(),y1 = read();
        int x2 = read(),y2 = read();
        A[i].x1 = min(x1,x2); A[i].x2 = max(x1,x2);
        A[i].y1 = min(y1,y2); A[i].y2 = max(y1,y2);
    }
    work();
    for(int i = 1;i < n;i ++) swap(a[i],b[i]);
    for(int i = 1;i <= q;i ++) {
        swap(A[i].x1,A[i].y1);
        swap(A[i].x2,A[i].y2);
    }
    work();
    for(int i = 1;i <= q;i ++) {
        printf("%lld\n",A[i].ans);
    }
}
