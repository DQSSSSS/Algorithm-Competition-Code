#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e5 + 10;
const int mod = 998244353;
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

mt19937 rd(time(0));

char mp[55][55];
int val[55][55],cost[55][55];

bool isTurning(char c) {
    return c == '>' || c == '<' || c == '^' || c == 'v';
}
bool isSource(char c) {
    return c == 'L' || c == 'R' || c == 'U' || c == 'D';
}

int randlr(int l,int r) { return rd()%(r-l+1)+l; }

void get_data(int maxn,int maxm,int maxk,int maxl,int maxcost,int maxvalue) {
    int n = randlr(max(1,maxn-3),maxn),m = randlr(max(1,maxm-3),maxm);
    //int k = randlr(max(0,maxk-3),maxk),l = randlr(max(0,maxl-3),maxl);
    int k = randlr(0,n*m/2),l = randlr(0,n*m-k);
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            mp[i][j] = '.';
    memset(val,0,sizeof val);
    memset(cost,0,sizeof cost);

    for(int i = 1;i <= k;i ++) {
        int x,y;
        do {
            x=randlr(1,n);
            y=randlr(1,m);
        }while(mp[x][y] != '.');
        mp[x][y] = 'x';
        val[x][y] = randlr(0,maxvalue);
    }

    for(int i = 1;i <= l;i ++) {
        int x,y;
        do {
            x=randlr(1,n);
            y=randlr(1,m);
        }while(mp[x][y] != '.');
        static char c[] = "<^>v";
        mp[x][y] = c[randlr(0,3)];
        cost[x][y] = randlr(0,maxcost);
    }

    int raytimes = randlr(0,n*m-k-l),walltimes = randlr(0,n*m-k-l-raytimes);

    for(int i = 1;i <= raytimes;i ++) {
        int x,y;
        do {
            x=randlr(1,n);
            y=randlr(1,m);
        }while(mp[x][y] != '.');
        static char c[] = "LRUD";
        mp[x][y] = c[randlr(0,3)];
    }

    for(int i = 1;i <= walltimes;i ++) {
        int x,y;
        do {
            x=randlr(1,n);
            y=randlr(1,m);
        }while(mp[x][y] != '.');
        mp[x][y] = '#';
    }

    printf("%d %d %d %d\n",n,m,k,l);
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            printf("%c",mp[i][j]);
        puts("");
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            if(mp[i][j] == 'x')
                printf("%d %d %d\n",i,j,val[i][j]);
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            if(isTurning(mp[i][j]))
                printf("%d %d %d\n",i,j,cost[i][j]);
    }
    puts("");
}

void getdata1() {
    int n = 50,m = 50,k = 1,l = 2498;
    mp[1][1] = 'R';
    mp[n][m] = 'x';
    val[n][m] = 1000000000;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(i == 1 && j == 1) continue;
            if(i == n && j == m) continue;
            static char c[] = "<^>v";
            mp[i][j] = '^';
            cost[i][j] = randlr(1,1000000);
        }
    }
    printf("%d %d %d %d\n",n,m,k,l);
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            printf("%c",mp[i][j]);
        puts("");
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            if(mp[i][j] == 'x')
                printf("%d %d %d\n",i,j,val[i][j]);
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            if(isTurning(mp[i][j]))
                printf("%d %d %d\n",i,j,cost[i][j]);
    }
    puts("");
}

void getdata2() {
    int n = 50,m = 50,k = 1,l = 2498;
    mp[1][1] = 'R';
    mp[n][m] = 'x';
    val[n][m] = 1000000000;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(i == 1 && j == 1) continue;
            if(i == n && j == m) continue;
            static char c[] = "<^>v";
            mp[i][j] = c[randlr(0,3)];
            cost[i][j] = randlr(1,1000000);
        }
    }
    printf("%d %d %d %d\n",n,m,k,l);
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            printf("%c",mp[i][j]);
        puts("");
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            if(mp[i][j] == 'x')
                printf("%d %d %d\n",i,j,val[i][j]);
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            if(isTurning(mp[i][j]))
                printf("%d %d %d\n",i,j,cost[i][j]);
    }
    puts("");
}

void getdata3() {
    int n = 50,m = 50,k = 1,l = 0;
    mp[1][1] = 'R';
    mp[n][m] = 'x';
    val[n][m] = 1000000000;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(i == 1 && j == 1) continue;
            if(i == n && j == m) continue;
            static char c[] = "<^>v";
            if(i&1) mp[i][j] = c[randlr(0,3)],cost[i][j] = randlr(1,1000000);
            else {
                if(i%4==0) {
                    if(j == 1) mp[i][j] = c[randlr(0,3)],cost[i][j] = randlr(1,1000000);
                    else mp[i][j] = '#';
                }
                else {
                    if(j == m) mp[i][j] = c[randlr(0,3)],cost[i][j] = randlr(1,1000000);
                    else mp[i][j] = '#';
                }
            }
        }
    }

    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            if(isTurning(mp[i][j])) l ++;
    }

    printf("%d %d %d %d\n",n,m,k,l);
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            printf("%c",mp[i][j]);
        puts("");
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            if(mp[i][j] == 'x')
                printf("%d %d %d\n",i,j,val[i][j]);
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            if(isTurning(mp[i][j]))
                printf("%d %d %d\n",i,j,cost[i][j]);
    }
    puts("");
}

void getdata4() {
    int n = 50,m = 50,k = 1,l = 0;
    mp[1][1] = 'R';
    mp[n][m] = 'x';
    val[n][m] = 1000000000;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(i == 1 && j == 1) continue;
            if(i == n && j == m) continue;
            mp[i][j] = '.';
            if(i+j==50&&i<24) mp[i][j] = 'v';
            if(i==j&&i<25) mp[i][j] = '>';

            if(i+j==52&&i>27) mp[i][j] = '^';
            if(i==j+1&&i>27) mp[i][j] = '<';
            if(mp[i][j] != '.') cost[i][j] = 1e9;

            if(i>=24 && j == m) {
                static char c[] = "<^>v";
                mp[i][j] = c[randlr(0,3)];
                cost[i][j] = randlr(1,1e7);
            }
        }
    }

    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            if(isTurning(mp[i][j])) l ++;
    }

    printf("%d %d %d %d\n",n,m,k,l);
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            printf("%c",mp[i][j]);
        puts("");
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            if(mp[i][j] == 'x')
                printf("%d %d %d\n",i,j,val[i][j]);
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            if(isTurning(mp[i][j]))
                printf("%d %d %d\n",i,j,cost[i][j]);
    }
    puts("");
}

void getdata5() {
    int n = 50,m = 50,k = 0,l = 0;

    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            mp[i][j] = '.';
            if(i == 1 || j == 1 || i == n || j == m) {
                mp[i][j] = 'x';
                val[i][j] = randlr(0,1e9);
            }
        }
    }

    int N = 15;
    for(int i = 0;i < 50-2*N;i ++) {
        for(int j = 0;j < 50-2*N;j ++) {
            if(i == 0) mp[i+N][j+N] = 'D';
            if(j == 0) mp[i+N][j+N] = 'R';
            if(i == 49-2*N) mp[i+N][j+N] = 'U';
            if(j == 49-2*N) mp[i+N][j+N] = 'L';

            if(i == 0 || j == 0 || i == 49-2*N || j == 49-2*N) {
                val[i][j] = randlr(0,1e9);
            }
        }
    }

    N = 5;
    for(int i = 0;i < 50-2*N;i ++) {
        for(int j = 0;j < 50-2*N;j ++) {
            if(i == 0) mp[i+N][j+N] = 'D';
            if(j == 0) mp[i+N][j+N] = 'R';
            if(i == 49-2*N) mp[i+N][j+N] = 'U';
            if(j == 49-2*N) mp[i+N][j+N] = 'L';

            if(i == 0 || j == 0 || i == 49-2*N || j == 49-2*N) {
                val[i][j] = randlr(0,1e9);
            }
        }
    }

    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(mp[i][j] == '.') {
                static char c[] = "<^>v";
                mp[i][j] = c[randlr(0,3)];
                cost[i][j] = randlr(0,1e3);
            }
        }
    }

    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(isTurning(mp[i][j])) l ++;
            if(mp[i][j] == 'x') k ++;
        }
    }

    printf("%d %d %d %d\n",n,m,k,l);
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            printf("%c",mp[i][j]);
        puts("");
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            if(mp[i][j] == 'x')
                printf("%d %d %d\n",i,j,val[i][j]);
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            if(isTurning(mp[i][j]))
                printf("%d %d %d\n",i,j,cost[i][j]);
    }
    puts("");
}

void getdata6() {
    int n = 50,m = 50,k = 0,l = 0;

    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            mp[i][j] = '.';
            if(i == 1 || j == 1 || i == n || j == m) {
                mp[i][j] = 'x';
                val[i][j] = randlr(0,1e9);
            }
        }
    }

    int N = 15;
    for(int i = 0;i < 50-2*N;i ++) {
        for(int j = 0;j < 50-2*N;j ++) {
            if(i == 0) mp[i+N][j+N] = 'D';
            if(j == 0) mp[i+N][j+N] = 'R';
            if(i == 49-2*N) mp[i+N][j+N] = 'U';
            if(j == 49-2*N) mp[i+N][j+N] = 'L';

            if(i == 0 || j == 0 || i == 49-2*N || j == 49-2*N) {
                val[i][j] = randlr(0,1e9);
            }
        }
    }

    N = 5;
    for(int i = 0;i < 50-2*N;i ++) {
        for(int j = 0;j < 50-2*N;j ++) {
            if(i == 0) mp[i+N][j+N] = 'D';
            if(j == 0) mp[i+N][j+N] = 'R';
            if(i == 49-2*N) mp[i+N][j+N] = 'U';
            if(j == 49-2*N) mp[i+N][j+N] = 'L';

            if(i == 0 || j == 0 || i == 49-2*N || j == 49-2*N) {
                val[i][j] = randlr(0,1e9);
            }
        }
    }

    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(mp[i][j] == '.') {
                static char c[] = "<^>v";
                mp[i][j] = c[randlr(0,3)];
                cost[i][j] = randlr(0,3);
            }
        }
    }

    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(isTurning(mp[i][j])) l ++;
            if(mp[i][j] == 'x') k ++;
        }
    }

    printf("%d %d %d %d\n",n,m,k,l);
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            printf("%c",mp[i][j]);
        puts("");
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            if(mp[i][j] == 'x')
                printf("%d %d %d\n",i,j,val[i][j]);
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++)
            if(isTurning(mp[i][j]))
                printf("%d %d %d\n",i,j,cost[i][j]);
    }
    puts("");
}

int main() {
    freopen("data.in","w",stdout);
    int T = 20;
    printf("%d\n",T);

    getdata1();
    getdata2();
    getdata3();
    getdata4();
    getdata5();
    getdata6();
    get_data(50,50,2500,2500,3,1000000000);
    get_data(50,50,2500,2500,1,2);
    get_data(50,50,2500,2500,0,1000000000);
    get_data(50,50,2500,2500,3,3);
    get_data(50,50,2500,2500,1000,5);
    T -= 11;
    while(T --) {
        get_data(50,50,2500,2500,1000000000,1000000000);
    }
    /*for(int i = 1;i <= m;i ++) {
        int l = L[i],r = R[i],x = X[i];
        int ans = 0;
        for(int j = l;j <= r;j ++) if(__gcd(x,a[j]) == 1) ans ++;
        printf("%d\n",ans);
    }*/
    return 0;
}
