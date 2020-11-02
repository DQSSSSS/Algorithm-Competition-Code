#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int SZ = 1e6 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 +a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

struct haha {
    int n,a[SZ];
    int find_pos1(int x) {
        return lower_bound(a+1,a+1+n,x) - a;
    }
    int find_pos2(int x) {
        return lower_bound(a+1,a+1+n,x) - a - 1;
    }
}a,b,c;

LL ans;
int d;

void work1(haha &a,haha &b,haha &c) {
    LL tmp = 0;
    for(int i = 1;i <= a.n;i ++) {
        int x = a.a[i];
        int bl = b.find_pos1(x-d),br = b.find_pos2(x);
        int cl = c.find_pos1(x-d),cr = c.find_pos2(x);
        LL bx = br - bl + 1,cx = cr - cl + 1;
        tmp += bx * cx;
    }
   // cout <<tmp << endl;
    ans += tmp;
}

void work2(haha &a,haha &b,haha &c) {
    map<int,int> mp;
    for(int i = 1;i <= b.n;i ++) mp[b.a[i]] ++;

    LL tmp = 0;
    for(int i = 1;i <= a.n;i ++) {
        int x = a.a[i];
        int cl = c.find_pos1(x-d),cr = c.find_pos2(x);
        LL bx = mp[x],cx = cr - cl + 1;
        tmp += bx * cx;
    }
    ans += tmp;
}


void work3(haha &a,haha &b,haha &c) {
    map<int,int> mp; for(int i = 1;i <= b.n;i ++) mp[b.a[i]] ++;
    map<int,int> mp2; for(int i = 1;i <= c.n;i ++) mp2[c.a[i]] ++;

    LL tmp = 0;
    for(int i = 1;i <= a.n;i ++) {
        int x = a.a[i];
        LL bx = mp[x],cx = mp2[x];
        tmp += bx * cx;
    }
    ans += tmp;
}

int main() {
    while(~scanf("%d%d%d%d",&d,&a.n,&b.n,&c.n)) {
        for(int i = 1;i <= a.n;i ++) a.a[i] = read();
        for(int i = 1;i <= b.n;i ++) b.a[i] = read();
        for(int i = 1;i <= c.n;i ++) c.a[i] = read();

        ans = 0;
        work1(a,b,c);
        work1(b,a,c);
        work1(c,b,a);

        work2(a,b,c);
        work2(a,c,b);
        work2(c,b,a);

        work3(a,b,c);

        printf("%lld\n",ans);
    }
}
