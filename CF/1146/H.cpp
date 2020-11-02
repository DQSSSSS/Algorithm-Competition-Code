#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e5 + 10;
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

struct haha {
    LL x,y;
    int id;
}a[SZ],e;

haha operator -(haha a,haha b) { return (haha){a.x-b.x,a.y-b.y}; }
LL operator *(haha a,haha b) { return a.x*b.y-a.y*b.x; }

bool cmp(haha a,haha b) {
    return (a - e) * (b - e) > 0;
}

bitset<310> b[310][310],tmp;

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        a[i].x = read(),a[i].y = read();
        a[i].id = i;
        tmp.set(i);
    }

    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++) {
            if(i == j) continue;
            for(int k = 1;k <= n;k ++) {
                if(k == i || k == j) continue;
                if((a[k] - a[i]) * (a[j] - a[i]) < 0) b[i][j].set(k);
            }
        }
    }
/*
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++) {
            if(i == j) continue;
            printf("(%d,%d) ",i,j);
            for(int k = 1;k <= n;k ++) {
                cout<<b[i][j][k];
            }
            puts("");
        }
    }*/

    LL ans = 1ll * n * (n-1) * (n-2) * (n-3) * (n-4) / 120,sum4 = 0,sum3 = 0;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++) {
            for(int k = 1;k <= n;k ++) {
                if(i == j || j == k || i == k) continue;
                bitset<310> now1 = tmp,now4 = tmp;
                now1 &= b[i][j]; now1 &= b[k][j]; now1 &= b[i][k];

                now4 &= b[j][i]; now4 &= b[i][k]; now4 &= b[k][j];

               // LL n1 = now1.count(),n2 = now2.count();
                LL n1 = now1.count(),n4 = now4.count();
               /* for(int l = 1;l <= n;l ++) cout<<b[j][i][l]; puts("");
                for(int l = 1;l <= n;l ++) cout<<b[i][k][l]; puts("");
                for(int l = 1;l <= n;l ++) cout<<b[k][j][l]; puts("");
                if(i == 1 && j == 2 && k == 4) system("pause");*/

                LL d3 = 0,d4 = 0;
                d3 += n4 * (n4-1) / 2;
                d4 += n1 * n4;

                sum3 += d3;
                sum4 += d4;

               // if(d3)
               // printf("(%d %d %d) %lld %lld %lld %lld (%lld,%lld)\n",i,j,k,n1,n2,n3,n4,d3,d4);
                //if(d)
              //  cout << i << " " << j << " " << k << " " << now1.count() << " " << now2.count() << " " << now3.count() << endl;
            }
        }
    }
    sum3 /= 3;
    sum4 /= 2;
    ans -= sum3 + sum4;
    //cout << sum3 << " " << sum4 << endl;
    cout << ans << endl;
}

/**
8
0 0
4 0
0 4
4 4
1 2
2 1
3 2
2 3


10
841746 527518
595261 331297
-946901 129987
670374 -140388
-684770 309555
-302589 415564
-387435 613331
-624940 -95922
945847 -199224
24636 -565799
13 154
*/
